// https://leetcode.com/problems/kth-largest-element-in-a-stream

const (
    UNSET = -10001
)

type KthLargest struct {
    Size int
    Nums []int
}


func Constructor(k int, nums []int) (ret KthLargest) {
    for appendSize := k - len(nums); appendSize > 0; appendSize-- {
        nums = append(nums, UNSET)
    }

    sort.Slice(nums, func (i, j int) bool {
        return nums[i] < nums[j]
    })

    ret.Size = k
    ret.Nums = nums[len(nums)-k:]

    return ret
}


func (this *KthLargest) Add(val int) int {
    if val > this.Nums[0] {
        this.Nums[0] = val
        sort.Slice(this.Nums, func (i, j int) bool {
            return this.Nums[i] < this.Nums[j]
        })
    }
    return this.Nums[0]
}

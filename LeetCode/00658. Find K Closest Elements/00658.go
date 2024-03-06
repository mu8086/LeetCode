// https://leetcode.com/problems/find-k-closest-elements

func findClosestElements(arr []int, k int, x int) []int {
    size := len(arr)

    right := sort.SearchInts(arr, x)
    left := right-1
    
    if right == 0 {
        return arr[:k]
    } else if right == size {
        return arr[size-k:]
    }

    lDiff, rDiff := x - arr[left], arr[right] - x

    for k > 0 {
        k--

        if lDiff <= rDiff {
            left--
            if left < 0 {
                right += k
                break
            }

            lDiff = x - arr[left]
        } else {
            right++
            if right >= size {
                left -= k
                break
            }

            rDiff = arr[right] - x
        }
    }

    return arr[left+1:right]
}

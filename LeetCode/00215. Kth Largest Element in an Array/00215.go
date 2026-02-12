// https://leetcode.com/problems/kth-largest-element-in-an-array

type IntHeap []int

func (h IntHeap) Len() int {
    return len(h)
}

// Min-Heap
func (h IntHeap) Less(i, j int) bool {
    return h[i] < h[j]
}

func (h IntHeap) Swap(i, j int) {
    h[i], h[j] = h[j], h[i]
}

func (h *IntHeap) Push(x any) {
    *h = append(*h, x.(int))
}

func (h *IntHeap) Pop() any {
    old := *h
    n := len(old)
    x := old[n-1]
    *h = old[:n-1]
    return x
}

func findKthLargest(nums []int, k int) int {
    h := &IntHeap{}
    heap.Init(h)

    for _, n := range nums {
        heap.Push(h, n)

        if h.Len() > k {
            heap.Pop(h)
        }
    }

    return (*h)[0]
}

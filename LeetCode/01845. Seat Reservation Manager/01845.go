// https://leetcode.com/problems/seat-reservation-manager

type IntHeap []int

func (h IntHeap) Len() int           { return len(h) }
func (h IntHeap) Less(i, j int) bool { return h[i] < h[j] }
func (h IntHeap) Swap(i, j int)      { h[i], h[j] = h[j], h[i] }

func (h *IntHeap) Push(x any) {
	*h = append(*h, x.(int))
}

func (h *IntHeap) Pop() any {
	old := *h
	n := len(old)
	x := old[n-1]
	*h = old[0 : n-1]
	return x
}

type SeatManager struct {
    h *IntHeap
}

func Constructor(n int) (manager SeatManager) {
    var intHeap IntHeap = make([]int, n, n)
    for i := 0; i < n; i++ {
        intHeap[i] = i+1
    }
    heap.Init(&intHeap)

    manager.h = &intHeap
    return manager
}

func (this *SeatManager) Reserve() int {
    seat := heap.Pop(this.h).(int)
    return seat
}

func (this *SeatManager) Unreserve(seatNumber int)  {
    heap.Push(this.h, seatNumber)
}

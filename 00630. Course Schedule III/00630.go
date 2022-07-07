import (
	"container/heap"
	"fmt"
    "sort"
)

type PriorityQueue []int

func (pq PriorityQueue) Len() int {
    return len(pq)
}

func (pq PriorityQueue) Less(i, j int) bool {
    return pq[i] > pq[j]
}

func (pq PriorityQueue) Swap(i, j int) {
    pq[i], pq[j] = pq[j], pq[i]
}

func (pq *PriorityQueue) Push(x interface{}) {
    *pq = append(*pq, x.(int))
}

func (pq *PriorityQueue) Pop() interface{} {
    old := *pq
    n := len(*pq)
    
    item := old[n-1]    // heap.Pop() move [0] -> [n-1], then call h.Pop(), so use [n-1] here
    
    *pq = old[0 : n-1]
    return item
}

func scheduleCourse(courses [][]int) int {
    sort.Slice(courses, func(a, b int) bool {
        return courses[a][1] < courses[b][1]
    })
    
    pq := make(PriorityQueue, 0)
    heap.Init(&pq)
    
    time := 0
    for _, v := range courses {
        time += v[0]
        heap.Push(&pq, v[0])
        
        if time > v[1] {
            time -= heap.Pop(&pq).(int)
        }
    }
    
    return pq.Len()
}

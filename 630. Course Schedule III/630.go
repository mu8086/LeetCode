import (
	"container/heap"
	"fmt"
    "sort"
)

type Item struct {
    Value       int
}

type PriorityQueue []*Item

func (pq PriorityQueue) Len() int {
    return len(pq)
}

func (pq PriorityQueue) Less(i, j int) bool {
    return pq[i].Value > pq[j].Value
}

func (pq PriorityQueue) Swap(i, j int) {
    pq[i], pq[j] = pq[j], pq[i]
}

func (pq *PriorityQueue) Push(x interface{}) {
    item := x.(*Item)
    *pq = append(*pq, item)
}

func (pq *PriorityQueue) Pop() interface{} {
    old := *pq
    n := len(*pq)
    
    item := old[n-1]    // heap.Pop() move [0] -> [n-1], then call h.Pop(), so use [n-1] here
    
    old[n-1] = nil
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
        item := &Item{
            Value: v[0],
        }
        
        time += v[0]
        heap.Push(&pq, item)
        
        if time > v[1] {
            time -= heap.Pop(&pq).(*Item).Value
        }
    }
    
    return pq.Len()
}

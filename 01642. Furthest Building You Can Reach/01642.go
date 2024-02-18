// https://leetcode.com/problems/furthest-building-you-can-reach

import (
	"container/heap"
)

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

func furthestBuilding(heights []int, bricks int, ladders int) int {
    reach, size := 1, len(heights)
    ladder := ladders

    ladderPos := &IntHeap{}
    heap.Init(ladderPos)

    for ; reach < size && ladder > 0; reach++ {
        if diff := heights[reach-1] - heights[reach]; diff >= 0 {
            continue
        } else {
            heap.Push(ladderPos, -diff)
            ladder--
        }
    }

    top := 0
    if ladderPos.Len() > 0 {
        top = heap.Pop(ladderPos).(int)
    }
    for ; reach < size; reach++ {
        if heights[reach-1] >= heights[reach] {
            continue
        }

        if bricks == 0 {
            break
        }

        diff := heights[reach] - heights[reach-1]
        if (top != 0 && bricks >= top) || bricks >= diff {
            if top == 0 || top >= diff {
                bricks -= diff
            } else {
                bricks -= top
                heap.Push(ladderPos, diff)
                top = heap.Pop(ladderPos).(int)
            }
        } else {
            break
        }
    }

    return reach-1
}

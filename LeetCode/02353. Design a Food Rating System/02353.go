// https://leetcode.com/problems/design-a-food-rating-system

type FoodRatings struct {
    cuisineMap map[string]PriorityQueue
    foodMap map[string]*Item
}

type Item struct {
    food     string
    cuisine  string
    priority int
    index int
}

type PriorityQueue []*Item

func (pq PriorityQueue) Len() int { return len(pq) }

func (pq PriorityQueue) Less(i, j int) bool {
    if pq[i].priority == pq[j].priority {
        return pq[i].food < pq[j].food
    }
    return pq[i].priority > pq[j].priority
}

func (pq PriorityQueue) Swap(i, j int) {
    pq[i], pq[j] = pq[j], pq[i]
    pq[i].index = i
    pq[j].index = j
}

func (pq *PriorityQueue) Push(x any) {
    n := len(*pq)
    item := x.(*Item)
    item.index = n
    *pq = append(*pq, item)
}

func (pq *PriorityQueue) Pop() any {
    old := *pq
    n := len(old)
    item := old[n-1]
    old[n-1] = nil
    item.index = -1
    *pq = old[0 : n-1]
    return item
}

func (pq *PriorityQueue) Top() any {
    return (*pq)[0]
}

func Constructor(foods []string, cuisines []string, ratings []int) FoodRatings {
    foodRatings := FoodRatings{
        cuisineMap: make(map[string]PriorityQueue),
        foodMap: make(map[string]*Item),
    }

    size := len(foods)

    for i := 0; i < size; i++ {
        item := &Item{
            food:    foods[i],
            cuisine: cuisines[i],
            priority: ratings[i],
            index: i,
        }

        pq := foodRatings.cuisineMap[cuisines[i]]
        if pq == nil {
            pq = make(PriorityQueue, 0, 0)
        }
        heap.Push(&pq, item)
        foodRatings.cuisineMap[cuisines[i]] = pq

        foodRatings.foodMap[foods[i]] = item
    }

    return foodRatings
}

func (this *FoodRatings) ChangeRating(food string, newRating int)  {
    if item := this.foodMap[food]; item != nil {
        item.priority = newRating
        pq := this.cuisineMap[item.cuisine]
        heap.Fix(&pq, item.index)
    }
}

func (this *FoodRatings) HighestRated(cuisine string) string {
    if cuisinePQ := this.cuisineMap[cuisine]; cuisinePQ != nil {
        if top := cuisinePQ.Top().(*Item); top != nil {
            return top.food
        }
    }
    return ""
}

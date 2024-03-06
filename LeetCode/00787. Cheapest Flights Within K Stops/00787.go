// https://leetcode.com/problems/cheapest-flights-within-k-stops

func findCheapestPrice(n int, flights [][]int, src int, dst int, k int) int {
    sort.Slice(flights, func (i, j int) bool {
        if flights[i][0] != flights[j][0] {
            return flights[i][0] < flights[j][0]
        }
        return flights[i][1] < flights[j][1]
    })

    size := len(flights)
    idxM := make([]int, n, n)
    costs := make([]int, n, n)
    oriCosts := make([]int, n, n)
    for i := 0; i < n; i++ {
        idxM[i], costs[i], oriCosts[i] = -1, -1, -1
    }

    for i := 0; i < size; i++ {
        if idxM[flights[i][0]] == -1 {
            idxM[flights[i][0]] = i
        }
    }

    queue := []int{src}
    costs[src], oriCosts[src] = 0, 0

    for levelSize := len(queue); k >= 0 && levelSize > 0; k, levelSize = k-1, len(queue) {
        nextRound := make(map[int]bool)

        for i := 0; i < levelSize; i++ {
            node := queue[i]

            // no next city
            if idxM[node] == -1 {
                continue
            }

            // loop all next city
            for sameSrcIdx := idxM[node]; sameSrcIdx < size && flights[sameSrcIdx][0] == node; sameSrcIdx++ {
                next, cost := flights[sameSrcIdx][1], flights[sameSrcIdx][2]

                newCost := oriCosts[next]

                // if city `next` haven't reach yet, or found a less costs
                if oriCosts[next] == -1 || oriCosts[next] > oriCosts[node] + cost {
                    newCost = oriCosts[node] + cost
                }

                // find minimum costs to reach city `next`, at the same step (level)
                if costs[next] == -1 || costs[next] > newCost {
                    costs[next] = newCost
                    nextRound[next] = true
                }
            }
        }

        // only the costs-reduced cities, should be to next round
        queue = []int{}
        for node := range nextRound {
            queue = append(queue, node)
            oriCosts[node] = costs[node]
        }
    }

    return costs[dst]
}

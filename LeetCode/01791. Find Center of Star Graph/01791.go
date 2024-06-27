// https://leetcode.com/problems/find-center-of-star-graph

func findCenter(edges [][]int) int {
    visited := make(map[int]bool)

    for _, edge := range edges {
        a, b := edge[0], edge[1]

        if visited[a] {
            return a
        } else if visited[b] {
            return b
        }

        visited[a], visited[b] = true, true
    }

    return -1
}

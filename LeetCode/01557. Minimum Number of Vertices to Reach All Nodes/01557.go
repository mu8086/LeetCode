// https://leetcode.com/problems/minimum-number-of-vertices-to-reach-all-nodes

func findSmallestSetOfVertices(n int, edges [][]int) (head []int) {
    count := make([]int, n)
    for _, edge := range edges {
        count[edge[1]]++
    }

    for i := 0; i < n; i++ {
        if count[i] == 0 {
            head = append(head, i)
        }
    }

    return head
}

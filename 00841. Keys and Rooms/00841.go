// https://leetcode.com/problems/keys-and-rooms

func canVisitAllRooms(rooms [][]int) bool {
    m := len(rooms)
    visited := make([]bool, m, m)

    var dfs func(i int)
    dfs = func(i int) {
        visited[i] = true

        for j := len(rooms[i])-1; j >= 0; j-- {
            room := rooms[i][j]
            
            if visited[room] {
                continue
            }

            dfs(room)
        }
    }

    dfs(0)

    for i := 0; i < m; i++ {
        if visited[i] == false {
            return false
        }
    }
    return true
}

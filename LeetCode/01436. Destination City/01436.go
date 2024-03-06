// https://leetcode.com/problems/destination-city

func destCity(paths [][]string) (ans string) {
    m := make(map[string]bool)

    for _, path := range paths {
        m[path[0]] = false

        if _, exists := m[path[1]]; !exists {
            m[path[1]] = true
        }
    }

    for path, ok := range m {
        if ok {
            ans = path
            break
        }
    }

    return ans
}

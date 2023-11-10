// https://leetcode.com/problems/crawler-log-folder

func minOperations(logs []string) (depth int) {
    for _, log := range logs {
        if log == "./" {
            continue
        } else if log == "../" {
            if depth > 0 {
                depth--
            }
        } else {
            depth++
        }
    }
    return depth
}

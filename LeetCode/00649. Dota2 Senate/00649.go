// https://leetcode.com/problems/dota2-senate

func predictPartyVictory(s string) string {
    queue := []byte(s)
    dBannedSize, rBannedSize := 0, 0

    for {
        qSize := len(queue)

        if dBannedSize + rBannedSize >= qSize {
            break
        }

        for i := 0; i < qSize; i++ {
            if queue[i] == 'D' {
                if dBannedSize > 0 {
                    dBannedSize--
                } else {
                    queue = append(queue, 'D')
                    rBannedSize++
                }
            } else {
                if rBannedSize > 0 {
                    rBannedSize--
                } else {
                    queue = append(queue, 'R')
                    dBannedSize++
                }
            }
        }

        queue = queue[qSize:]
    }

    if queue[0] == 'D' {
        return "Dire"
    }
    return "Radiant"
}

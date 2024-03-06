// https://leetcode.com/problems/minimum-amount-of-time-to-collect-garbage

func garbageCollection(garbage []string, travel []int) (ans int) {
    garbageSize := func(s string) (m, p, g int) {
        for i := len(s)-1; i >= 0; i-- {
            switch s[i] {
            case 'M':
                m++
            case 'P':
                p++
            case 'G':
                g++
            }
        }
        return
    }

    redundantM, redundantP, redundantG := 0, 0, 0

    ans += len(garbage[0])
    for i, size := 0, len(travel); i < size; i++ {
        m, p, g := garbageSize(garbage[i+1])
        if m == 0 {
            redundantM += travel[i]
        } else {
            redundantM = 0
        }
        if p == 0 {
            redundantP += travel[i]
        } else {
            redundantP = 0
        }
        if g == 0 {
            redundantG += travel[i]
        } else {
            redundantG = 0
        }

        ans += len(garbage[i+1]) + travel[i]*3
    }
    ans -= redundantM + redundantP + redundantG

    return ans
}

// https://leetcode.com/problems/merge-intervals

// check how far we can reach
func merge(intervals [][]int) (ans [][]int) {
    sort.Slice(intervals, func(i, j int) bool {
        return intervals[i][0] < intervals[j][0]
    })

    size := len(intervals)

    headIdx, farest := 0, intervals[0][1]
    for i := 1; i < size; i++ {
        if farest >= intervals[i][0] {
            if farest < intervals[i][1] {
                farest = intervals[i][1]
            }
        } else {
            ans = append(ans, []int{intervals[headIdx][0], farest})
            headIdx, farest = i, intervals[i][1]
        }
    }

    ans = append(ans, []int{intervals[headIdx][0], farest})

    return ans
}

// line sweep
func mergeLineSweep(intervals [][]int) (ans [][]int) {
    size := len(intervals)
    m := make(map[int]int)

    for i := 0; i < size; i++ {
        m[intervals[i][0]]++
        m[intervals[i][1]]--
    }

    list := [][2]int{}
    for k, v := range m {
        list = append(list, [2]int{k, v})
    }

    sort.Slice(list, func(i, j int) bool {
        return list[i][0] < list[j][0]
    })

    headIdx, walkingCount := 0, 0
    for i, size := 0, len(list); i < size; i++ {
        walkingCount += list[i][1]

        if walkingCount == 0 {
            ans = append(ans, []int{list[headIdx][0], list[i][0]})
            headIdx = i+1   // next head
        }
    }

    return ans
}

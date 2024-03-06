// https://leetcode.com/problems/insert-interval

func binarySearch(intervals [][]int, target int) int {
    l, m, r := 0, 0, len(intervals)-1
    
    if len(intervals) == 0 {
        return 0
    }

    if target < intervals[0][0] {
        return 0
    } else if target > intervals[r][1] {
        return r+1
    }

    for l < r {
        m = l + (r-l)/2
        a, b := intervals[m][0], intervals[m][1]
        if a <= target && target <= b {
            return m
        } else if target < a {
            r = m-1
        } else {
            l = m+1
        }
    }
    if target > intervals[l][1] {
        return l+1
    }

    return l
}

func insert(intervals [][]int, newInterval []int) (ans [][]int) {
    i := 0
    l := len(intervals)

    a, b := newInterval[0], newInterval[1]
    idxA := binarySearch(intervals, a)
    if idxA == l {  // newInterval is non-overlapping, and greater than all
        return append(intervals, newInterval)
    }

    // non-overlapping intervals before newInterval
    ans = append(ans, intervals[:idxA]...)
    
    if a > intervals[idxA][0] {
        a = intervals[idxA][0]
    }
    if b <= intervals[l-1][1] {
        for i = idxA; i < l; i++ {
            if b < intervals[i][0] {
                if i != idxA && b < intervals[i-1][1] {
                    b = intervals[i-1][1]
                }
                ans = append(ans, []int{a, b})
                break
            } else if b <= intervals[i][1] {
                ans = append(ans, []int{a, intervals[i][1]})
                i++
                break
            }
        }

        // non-overlapping intervals after newInterval
        ans = append(ans, intervals[i:l]...)

    } else { // {a, b} cover all left intervals
        ans = append(ans, []int{a, b})
    }

    return ans
}

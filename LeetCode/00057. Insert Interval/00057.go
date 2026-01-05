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

func insert2(intervals [][]int, newInterval []int) [][]int {
    size := len(intervals)

    ansIdx := 0
    ans := [][]int{[]int{newInterval[0], newInterval[1]}}
    
    for i := 0; i < size; i++ {
        newFrom, newTo := intervals[i][0], intervals[i][1]
        from, to := ans[ansIdx][0], ans[ansIdx][1]

        if newTo < from {                       // [newFrom-newTo] [from-to]
            ans[ansIdx][0], ans[ansIdx][1] = newFrom, newTo
            ans = append(ans, []int{newInterval[0], newInterval[1]})
            ansIdx++
        } else if newTo == from {               // [newFrom-(newTo==from)-to] 
            ans[ansIdx][0] = newFrom
        } else if newTo > from && newTo < to {  // [min(from,newFrom)-newTo-to]
            ans[ansIdx][0] = min(from, newFrom)
            ans[ansIdx][1] = to
        } else if newTo == to {                 // [min(from,newFrom)-(newTo==to)]
            ans[ansIdx][0] = min(from, newFrom)
        } else {                                // newTo > to
            if newFrom <= to {                  // [min(from,newFrom)-to-newTo]
                ans[ansIdx][0] = min(from, newFrom)
                ans[ansIdx][1] = newTo
            } else {                            // [from-to] [newFrom-newTo]
                ans = append(ans, intervals[i:]...)
                break
            }
        }
    }

    return ans
}

func insert3(intervals [][]int, newInterval []int) [][]int {
    idx := 0
    ans := [][]int{newInterval}

    isOverlapped := func(a, b []int) bool {
        if a[0] > b[1] || b[0] > a[1] {
            return false
        }
        return true
    }
    
    for _, interval := range intervals {
        if isOverlapped(ans[idx], interval) {
            ans[idx][0] = min(ans[idx][0], interval[0])
            ans[idx][1] = max(ans[idx][1], interval[1])
            continue
        }

        if ans[idx][0] < interval[0] {
            ans = append(ans, interval)
        } else {
            ans = append(ans, ans[idx])
            ans[idx] = interval
        }
        idx++
    }

    return ans
}

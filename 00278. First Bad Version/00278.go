// https://leetcode.com/problems/first-bad-version

func firstBadVersion(n int) int {
    l, r := 0, n

    for l < r {
        m := l + (r-l)/2

        if isBadVersion(m) {
            r = m
        } else {
            l = m+1
        }
    }

    return l
}

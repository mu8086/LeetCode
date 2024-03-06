// https://leetcode.com/problems/pairs-of-songs-with-total-durations-divisible-by-60

func numPairsDivisibleBy60(time []int) (ans int) {
    mods := [60]int{}

    for i := len(time)-1; i >= 0; i-- {
        t := time[i] % 60
        ans += mods[(60-t) % 60]
        mods[t]++
    }

    return ans
}

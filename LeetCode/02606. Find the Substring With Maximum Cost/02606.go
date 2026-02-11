// https://leetcode.com/problems/find-the-substring-with-maximum-cost

func maximumCostSubstring(s, chars string, vals []int) int {
    val := [26]int{}
    for i := 0; i < 26; i++ {
        val[i] = i+1
    }
    for k, v := range chars {
        val[v-'a'] = vals[k]
    }

    ans, prefix := 0, 0
    for _, c := range s {
        prefix += val[c-'a']
        if prefix < 0 {
            prefix = 0
            continue
        }

        if ans < prefix {
            ans = prefix
        }
    }

    return ans
}

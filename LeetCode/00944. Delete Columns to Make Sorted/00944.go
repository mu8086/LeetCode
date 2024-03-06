// https://leetcode.com/problems/delete-columns-to-make-sorted

func minDeletionSize(strs []string) int {
    var remove, sLen = 0, len(strs[0])

    for idx := 0; idx < sLen; idx++ {
        for s := 1; s < len(strs); s++ {
            if strs[s-1][idx] >  strs[s][idx] {
                remove++
                break
            }
        }
    }

    return remove
}

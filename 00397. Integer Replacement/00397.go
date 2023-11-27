// https://leetcode.com/problems/integer-replacement

func integerReplacement(n int) (ops int) {
    for n > 1 {
        ops++

        if (n & 1) == 0 {
            n >>= 1
        } else {
            if n == 3 {
                n--
            } else if (n & 2) == 0 {   // xx01 -> n-1
                n--
            } else {    // xx11 -> n+1
                n++
            }
        }
    }

    return ops
}

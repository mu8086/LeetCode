// https://leetcode.com/problems/letter-case-permutation

func letterCasePermutation(s string) (ans []string) {
    bs := []byte(s)
    size := len(bs)

    transform := func(c byte) byte {
        const diff byte = 'a' - 'A'
        if 'A' <= c && c <= 'Z' {
            return c + diff
        }
        return c - diff
    }

    loop := func([]byte, int, int){}
    loop = func(bs []byte, idx, size int) {
        if idx == size {
            ans = append(ans, string(bs))
            return
        }

        if '0' <= bs[idx] && bs[idx] <= '9'{
            loop(bs, idx+1, size)
        } else {
            loop(bs, idx+1, size)

            bs[idx] = transform(bs[idx])
            loop(bs, idx+1, size)
            bs[idx] = transform(bs[idx])
        }
    }

    loop(bs, 0, size)

    return ans
}

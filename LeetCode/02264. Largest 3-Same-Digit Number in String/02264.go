// https://leetcode.com/problems/largest-3-same-digit-number-in-string

func largestGoodInteger(num string) (ans string) {
    var max byte

    for i, lastLeadingIdx := 0, len(num)-3; i <= lastLeadingIdx; {
        if num[i] == num[i+2] {
            if num[i] == num[i+1] {
                if max < num[i] {
                    max = num[i]
                }

                i += 3
            } else {
                i += 2
            }
        } else {
            i += 1
        }
    }

    if max >= '0' {
        ans = fmt.Sprintf("%c%c%c", max, max, max)
    }
    return ans
}

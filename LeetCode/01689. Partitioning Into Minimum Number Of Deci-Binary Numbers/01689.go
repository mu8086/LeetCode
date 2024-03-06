// https://leetcode.com/problems/partitioning-into-minimum-number-of-deci-binary-numbers

func minPartitions(n string) int {
    var maxDigit rune

    for _, digit := range n {
        if maxDigit < digit {
            maxDigit = digit

            if maxDigit == '9' {
                break
            }
        }
    }

    return int(maxDigit - '0')
}

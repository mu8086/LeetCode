// https://leetcode.com/problems/excel-sheet-column-number

func titleToNumber(columnTitle string) (n int) {
    for _, c := range columnTitle {
        if n != 0 {
            n *= 26
        }

        n += int(c-'A'+1)
    }

    return n
}

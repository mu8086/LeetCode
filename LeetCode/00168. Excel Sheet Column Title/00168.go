// https://leetcode.com/problems/excel-sheet-column-title

func convertToTitle(columnNumber int) (s string) {
    for columnNumber > 0 {
        columnNumber--

        digit := (columnNumber % 26)
        s = string(digit + 'A') + s

        columnNumber /= 26
    }

    return s
}

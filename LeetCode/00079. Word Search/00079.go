// https://leetcode.com/problems/word-search

func exist(board [][]byte, word string) bool {
    rowSize, colSize, wordSize := len(board), len(board[0]), len(word)

    visited := make([][]bool, rowSize, rowSize)
    for i := 0; i < rowSize; i++ {
        visited[i] = make([]bool, colSize, colSize)
    }

    toggle := func(row, col int) { visited[row][col] = !visited[row][col] }

    var match func(row, col, wordIdx int) bool
    match = func(row, col, wordIdx int) bool {
        if row < 0 || row >= rowSize || col < 0 || col >= colSize {
            return false
        } else if visited[row][col] {
            return false
        } else if board[row][col] != word[wordIdx] {
            return false
        } else if wordIdx == wordSize-1 {
            return true
        }

        toggle(row, col)
        if match(row-1, col, wordIdx+1) {
            return true
        }
        if match(row+1, col, wordIdx+1) {
            return true
        }
        if match(row, col-1, wordIdx+1) {
            return true
        }
        if match(row, col+1, wordIdx+1) {
            return true
        }
        toggle(row, col)

        return false
    }

    for i := 0; i < rowSize; i++ {
        for j := 0; j < colSize; j++ {
            if match(i, j, 0) {
                return true
            }
        }
    }
    return false
}

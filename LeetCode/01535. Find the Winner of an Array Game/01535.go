// https://leetcode.com/problems/find-the-winner-of-an-array-game

func getWinner(arr []int, k int) (winner int) {
    for count, i, l := 0, 1, len(arr); i < l; i++ {
        // store max value in arr[0]
        if arr[0] < arr[i] {
            arr[0] = arr[i]
        }

        if winner != arr[0] {
            winner = arr[0]
            count = 0
        }

        count++
        if count == k {
            break
        }
    }

    return winner
}

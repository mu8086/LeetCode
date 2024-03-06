// https://leetcode.com/problems/add-digits

func addDigits(num int) int {
    for num > 9 {
        sum := 0
        for num > 0 {
            sum += num % 10
            num /= 10
        }
        num = sum
    }
    return num
}

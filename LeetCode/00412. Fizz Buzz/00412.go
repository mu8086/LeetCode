// https://leetcode.com/problems/fizz-buzz

func fizzBuzz(n int) []string {
    ans := make([]string, n+1, n+1)

    for i := 1; i <= n; i++ {
        if i % 3 == 0 && i % 5 == 0 {
            ans[i] = "FizzBuzz"
        } else if i % 3 == 0 {
            ans[i] = "Fizz"
        } else if i % 5 == 0 {
            ans[i] = "Buzz"
        } else {
            ans[i] = strconv.Itoa(i)
        }
    }

    return ans[1:]
}

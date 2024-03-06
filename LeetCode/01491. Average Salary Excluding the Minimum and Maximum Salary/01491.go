// https://leetcode.com/problems/average-salary-excluding-the-minimum-and-maximum-salary

func average(salary []int) float64 {
    size := len(salary)
    sum, min, max := salary[0], salary[0], salary[0]

    for i := 1; i < size; i++ {
        tmp := salary[i]
        
        sum += tmp
        if min > tmp {
            min = tmp
        }
        if max < tmp {
            max = tmp
        }
    }

    return float64(sum-min-max) / float64(size-2)
}

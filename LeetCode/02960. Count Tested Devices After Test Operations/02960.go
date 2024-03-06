// https://leetcode.com/problems/count-tested-devices-after-test-operations

func countTestedDevices(batteryPercentages []int) (nonZero int) {
    for i, size := 0, len(batteryPercentages); i < size; i++ {
        if batteryPercentages[i] > nonZero {
            nonZero++
        }
    }

    return nonZero
}

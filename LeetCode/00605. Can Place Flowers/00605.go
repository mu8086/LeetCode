// https://leetcode.com/problems/can-place-flowers

func canPlaceFlowers(flowerbed []int, n int) bool {
    size := len(flowerbed)
    
    if size == 1 {
        return flowerbed[0] + n <= 1
    }

    if size >= 2 && flowerbed[0] + flowerbed[1] == 0 {
        flowerbed[0] = 1
        n--
    }

    if size >= 2 && flowerbed[size-1] + flowerbed[size-2] == 0 {
        flowerbed[size-1] = 1
        n--
    }

    zeros := 0
    for i := 1; i < size && n > 0; i++ {
        if flowerbed[i] == 0 {
            zeros++
        } else {
            n -= (zeros-1) / 2
            zeros = 0
        }
    }

    return n <= 0
}

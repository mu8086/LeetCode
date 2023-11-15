// https://leetcode.com/problems/pairs-of-songs-with-total-durations-divisible-by-60

// others' submission
func numPairsDivisibleBy60(time []int) int {
    total := 0
    mods := make([]int, 60)

    for i := 0; i < len(time); i++ {    
         m := time[i] % 60
        if m == 0  {
            total += (mods[m])
        } else {
            total += (mods[60-m])
        }
        mods[m] += 1
    }

    return total
}

// normal (based on sort & binarySearch)
func numPairsDivisibleBy60Ver2(time []int) (pair int) {
    size := len(time)
    for i := 0; i < size; i++ {
        time[i] %= 60
    }

    sort.Ints(time)

    zeroSize := sort.SearchInts(time, 1)
    pair += zeroSize * (zeroSize - 1) / 2
    if zeroSize == size {
        return pair
    }

    thirtyIdx := sort.SearchInts(time, 30)
    if thirtyIdx != size {
        thirtySize := sort.SearchInts(time, 31) - thirtyIdx
        pair += thirtySize * (thirtySize-1) / 2
    }

    for val := 1; val < 30; val++ {
        myIdx := sort.SearchInts(time, val)
        if myIdx == size || time[myIdx] != val {
            continue
        }

        otherIdx := sort.SearchInts(time, 60-val)
        if otherIdx == size || time[otherIdx] != 60-val {
            continue
        }

        mySize := sort.SearchInts(time, val+1) - myIdx
        otherSize := sort.SearchInts(time, 60-val+1) - otherIdx

        pair += mySize*otherSize
    }

    return pair
}

// bad
func numPairsDivisibleBy60Ver1(time []int) (pair int) {
    for i, lastIdx := 0, len(time)-1; i < lastIdx; i++ {
        for j := i+1; j <= lastIdx; j++ {
            if (time[i] + time[j]) % 60 == 0 {
                pair++
            }
        }
    }
    return pair
}

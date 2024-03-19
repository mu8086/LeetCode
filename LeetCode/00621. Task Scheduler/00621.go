// https://leetcode.com/problems/task-scheduler

func leastInterval(tasks []byte, n int) int {
    size := len(tasks)
    m := make(map[byte]int)

    for i := 0; i < size; i++ {
        m[tasks[i]]++
    }

    maxFreq, maxFreqSize := 0, 0
    for _, v := range m {
        if maxFreq < v {
            maxFreq = v
            maxFreqSize = 1
        } else if maxFreq == v {
            maxFreqSize++
        }
    }

    groupSize := maxFreq
    groupLength := n+1

    totalSlot := groupSize * groupLength
    idleSlotL, idleSlotR := (groupSize-1) * (groupLength-maxFreqSize), groupLength-maxFreqSize

    sizeWithoutMaxFreq := size - (maxFreq * maxFreqSize)

    if size >= totalSlot {
        return size
    }

    if sizeWithoutMaxFreq <= idleSlotL {
        return totalSlot - idleSlotR
    }
    return totalSlot - (idleSlotL + idleSlotR - sizeWithoutMaxFreq)
}

/*
["A","A","A","B","B","B","C","D","E","F","G"]
3

size := 11
maxFreq, maxFreqSize := 3, 2
groupSize, groupLength := 3, 4

--> A--- A--- A===
    AB-- AB-- AB==

totalSlot : 3 * 4 = 12
idleSlotL (notation '-'), idleSlotR (notation '=') := (3-1) * (4-2), 4-2    = 4, 2

sizeWithoutMaxFreq := 11 - (3*2)    = 5

return 12-(4+2-5)   = 11
*/

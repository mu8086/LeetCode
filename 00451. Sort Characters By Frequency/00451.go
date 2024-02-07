// https://leetcode.com/problems/sort-characters-by-frequency

func frequencySort(s string) string {
    freq := [256]struct{
        char byte
        freq int
    }{}

    for i := 0; i < 256; i++ {
        freq[i].char = byte(i)
    }

    for _, c := range s {
        freq[int(c)].freq++
    }

    sort.Slice(freq[:], func(i, j int) bool {
        return freq[i].freq > freq[j].freq
    })

    uniqSize := sort.Search(len(freq), func(i int) bool {
        return freq[i].freq == 0
    })

    ans := []byte{}
    for i := 0; i < uniqSize; i++ {
        for uniqChar, repeat := freq[i].char, freq[i].freq; repeat > 0; repeat-- {
            ans = append(ans, uniqChar)
        }
    }

    return string(ans)
}

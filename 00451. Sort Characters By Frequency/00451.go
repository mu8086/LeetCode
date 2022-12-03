// https://leetcode.com/problems/sort-characters-by-frequency

type charFreq struct {
	char byte
	freq int
}

func frequencySort(s string) string {
	freqMap := make(map[byte]int)
	for i := 0; i < len(s); i++ {
		freqMap[s[i]]++
	}

	freqSlice := make([]charFreq, 0, 0)
	for c, freq := range freqMap {
		freqSlice = append(freqSlice, charFreq{char: c, freq: freq})
	}

	sort.Slice(freqSlice, func(i, j int) bool {
		return freqSlice[i].freq > freqSlice[j].freq
	})

	var result []byte
	for i := 0; i < len(freqSlice); i++ {
		for j := 0; j < freqSlice[i].freq; j++ {
			result = append(result, freqSlice[i].char)
		}
	}

	return string(result)
}

// https://leetcode.com/problems/sort-vowels-in-a-string

func sortVowels(s string) string {
    var (
        vowelIdx []int
        vowels []byte
    )

    slice := []byte(s)
    for i, l := 0, len(s); i < l; i++ {
        switch s[i] {
        case 'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U':
            vowelIdx = append(vowelIdx, i)
            vowels = append(vowels, s[i])
        }
    }

    sort.Slice(vowels, func(i, j int) bool { return vowels[i] < vowels[j] })

    for i, l := 0, len(vowelIdx); i < l; i++ {
        idx := vowelIdx[i]
        slice[idx] = vowels[i]
    }

    return string(slice)
}

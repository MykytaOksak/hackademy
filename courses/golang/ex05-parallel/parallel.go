package letter

import "sync"

func Frequency(s string) map[rune]int {
	m := make(map[rune]int)
	for _, chr := range s {
		m[chr]++
	}
	return m
}

func ConcurrentFrequency(texts []string) map[rune]int {
	var wg sync.WaitGroup
	freqMap := make([]map[rune]int, len(texts))
	for i, text := range texts {
		wg.Add(1)
		go func(i int, text string) {
			freqMap[i] = Frequency(text)
			wg.Done()
		} (i, text)
	}
	wg.Wait()

	ret := make(map[rune]int)
	for _, m := range freqMap {
		for letter, freq := range m {
			ret[letter] += freq
		}
	}

	return ret
}

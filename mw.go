package main

func mergeAlternatingChars(s1, s2 string) string {
	result := make([]byte, len(s1)+len(s2))
	i, j, k := 0, 0, 0

	for {
		if i < len(s1) {
			result[k] = s1[i]
			i++
			k++
		}
		if j < len(s2) {
			result[k] = s2[j]
			j++
			k++
		}
		if i >= len(s1) && j >= len(s2) {
			break
		}
	}

	return string(result[:k])
}

func main() {
	s1 := "abc"
	s2 := "pqr"

	merged := mergeAlternatingChars(s1, s2)
	print("s1: ")
	print(s1)
	print("\ns2: ")
	print(s2)
	print("\nMerged result: ")
	print(merged)
	print("\n")
}

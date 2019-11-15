package main

func leastInterval(tasks []byte, n int) int {
	mp := make(map[byte]int)
	for _, val := range tasks {
		mp[val] += 1
	}
	mx := 0
	occur := 0

	for _, v := range mp {
		if v > mx {
			mx = v
			occur = 1
		} else if v == mx {
			occur += 1
		}
	}

	if (n+1)*(mx-1)+occur < len(tasks) {
		return len(tasks)
	}
	return (n+1)*(mx-1) + occur
}

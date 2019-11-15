package main

func findPoisonedDuration(timeSeries []int, duration int) int {
	if len(timeSeries) == 0 {
		return 0
	}
	var total = duration
	for i:=1; i < len(timeSeries); i++{
		if timeSeries[i] - timeSeries[i-1] > duration {
			total += duration
		}else{
			total += timeSeries[i] - timeSeries[i-1]
		}
	}
	return total
}


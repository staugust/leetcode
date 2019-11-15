package main

// https://leetcode.com/problems/swap-for-longest-repeated-character-substring/
func maxRepOpt1(text string) int {
	if len(text) < 2 {
		return len(text)
	}
	var single = make([]int, len(text))
	var double = make([]int, len(text))
	single[0] = 1
	double[0] = 1
	double[1] = 2

	for i := 1; i < len(text); i++{
		if text[i] == text[i - 1]{
			single[i] = 1 + single[i-1]
			double[i] = 1 + double[i-1]
		}else{
			single[i] = 1
			if i > 1 {
				if text[i] == text[i - 2]{
					double[i] = single[i -2] + 2
				}else{
					double[i] = 2
				}
			}
		}


	}

}

func main(){


}
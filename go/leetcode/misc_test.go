/*
Copyright 2020 Alipay.Inc.
*/

package main

import (
	"fmt"
	"testing"
)

func Test(t *testing.T) {
	matrix := [][]int{{7, 10}, {7, 12}, {7, 5}, {7, 4}, {7, 2}}
	fmt.Println(getOrder(matrix))

}

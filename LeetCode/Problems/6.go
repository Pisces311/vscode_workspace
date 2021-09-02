package main

func convert(s string, numRows int) string {
	if numRows == 1 {
		return s
	}
	ma := make([][]rune, numRows)
	for i := 0; i < numRows; i++ {
		ma[i] = make([]rune, 1000)
	}
	row, col := 0, 0
	down := true
	for _, ch := range s {
		ma[row][col] = ch
		if down {
			if row < numRows-1 {
				row++
			} else {
				row--
				col++
				down = false
			}
		} else {
			if row == 0 {
				down = true
				row++
			} else {
				col++
				row--
			}
		}
	}
	ret := ""
	for i := 0; i < numRows; i++ {
		for j := 0; j <= col; j++ {
			if ma[i][j] != 0 {
				ret += string(ma[i][j])
			}
		}
	}
	return ret
}

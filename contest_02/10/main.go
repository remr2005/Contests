func shift(data []int, s int) {
	var arr_ [10]int
	s = (s%10 + 10) % 10
	for i := 0; i < 10; i++ {
		arr_[(i+s)%10] = data[i]
	}
	copy(data, arr_[:])
}
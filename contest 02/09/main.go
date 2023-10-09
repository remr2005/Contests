func isLucky(a string) bool {
	var first, second int
	for i := 0; i < 3; i++ {
		first += int(a[i])
		second += int(a[i+3])
	}
	return first == second
}
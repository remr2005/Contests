import "strings"

func isPalindrome(a string) bool {
	a = strings.ToLower(a)
	var first string = ""
	var second string = ""
	for i := 0; i < len(a); i++ {
		if (96 < int(a[i]) && int(a[i]) < 123) || (47 < int(a[i]) && int(a[i]) < 58) {
			first += string(a[i])
			second = string(a[i]) + second
		}
	}
	return first == second
}
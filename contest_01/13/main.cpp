#include <iostream>
#include<string>

std :: string func(int j,int n) {
	int n_ = n + j;
	std::string str = std::to_string(j);
	for (int i = j + 1;i < n_;i++) str = str + " " + std::to_string(i);
	return str;
}

int main()
{
	int n;
	std::cin >> n;
	int i = 1;
	int len = 2;
	int local_len = 1;
	int k = 1;
	//std::cout << func(2,2);
	while (i <= n) {
		if ((local_len + i) > n) {
			std::cout << func(i, n - i+1);
			break;
		}
		std::cout << func(i, local_len) << "\n";
		i += local_len;
		local_len += k;
		if (local_len == len) {
			k *= (-1);
			len += 1;
		}
		if (local_len == 1 && k == -1) k *= (-1);
	}
}
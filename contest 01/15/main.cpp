#include <iostream>
#include<string>

int main()
{
	std::string  str;
	std::string  res;
	std::cin >> str;
	int n = 0;
	char j = str[0];
	char last;
	for (char c : str)
	{
		if (c == j) n += 1;
		else if (c != j && n != 1) {
			res.push_back(j);
			res += std::to_string(n);
			n = 1;
			j = c;
		}
		else {
			res.push_back(j);
			j = c;
		}
		last = c;
	}
	res.push_back(last);
	if (n!=1) res += std::to_string(n);
	std::cout << res;
}
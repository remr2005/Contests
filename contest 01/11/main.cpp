#include <iostream>
#include <cstdlib>

int main()
{
	int a;
	int b;
	int c;
	std::cin >> a;
	std::cin >> b;
	std::cin >> c;
	if (abs(a - b) > abs(a - c))std::cout << 'C' << ' ' << abs(a - c);
	else std::cout << 'B' << ' ' << abs(a - b);
}
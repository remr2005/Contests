#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
    int n;
    std::cin >> n;
    std::vector<long long> first(n);
    for (auto& line : first) std::cin >> line;

    int n_;
    std::cin >> n_;
    std::vector<long long> second(n_);
    for (auto& line : second) std::cin >> line;

    for (auto i : second) {
        first.push_back(i);
    }
    std::sort(first.begin(), first.end());
    for (auto& line : first) std::cout << line << ' ';

}
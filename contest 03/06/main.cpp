#include <iostream>
#include <string>
#include <map>

int main()
{
    int count;
    std::cin >> count;
    std::map<std::string, std::string> maps;
    for (int i = 0;i < count;i++) {
        std::string line;
        std::cin >> line;
        int end = line.find(';', 0);
        maps[line.substr(0, end)] = line.substr(end + 1, 1000);
    }
    int count_;
    std::cin >> count_;
    for (int i = 0;i < count_;i++) {
        std::string line;
        std::cin >> line;
        std::cout << maps[line] << ' ';
    }
}
int nums(std::string a) {
    int sum = 0;
    for (auto i : a)if (i == '1') sum += 1;
    return sum;
}

bool compare(std::string a, std::string b) {
    int a_int = nums(a);
    int b_int = nums(b);
    if (a == b) return false;
    if (a_int == b_int) return std::stoi(a) < std::stoi(b);
    return a_int > b_int;
}
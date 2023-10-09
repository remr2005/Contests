std::tuple<int, int, int> find_lcm(int a, int b) {
    int maxs;
    if (a > b) maxs = a;
    if (a <= b) maxs = b;
    while (true) {
        if ((maxs % a == 0) && (maxs % b == 0)) break;
        maxs += 1;
    }
    return std::make_tuple(maxs, maxs / a, maxs / b);
}

std::tuple<int, int> reduce(int a, int b) {
    int mins;
    int nod;
    if (a > b) mins = a;
    if (a <= b) mins = b;
    for (int i = 1; i <= mins;i++) {
        if ((a % i == 0) && (b % i == 0)) nod = i;
    }
    return std::make_tuple(a / nod, b / nod);
}
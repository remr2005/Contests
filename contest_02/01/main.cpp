#include<cmath>
int is_prime(int number) {
    double n = number;
    int num = sqrt(n);
    for (int i = 2; i <= num;i++) {
        if (number % i == 0) return false;
    }
    return true;
}

#include <iostream>
#include <string>
#include<vector>
#include <algorithm>

class Bigint {
public:
    std::vector<int> arr;
    bool znak;
    std::string str;

    std::string stringfi() {
        std::string res;
        for (auto i : this->arr) res = std::to_string(i) + res;
        if (this->znak and res != "0") { res = "-" + res; /*std::cout << 1 << '\n'; */ }
        return res;
    }

    Bigint() {
        this->znak = false;
    }

    Bigint(std::string a) {
        int k = 0;
        this->znak = false;
        for (auto i : a) {
            if (k == 0 and i == '-') {
                this->znak = true;
                continue;
            }
            int buf = (int)i-48;
            this->arr.push_back(buf);
            k += 1;
        }
        std::reverse(this->arr.begin(), this->arr.end());
        this->str = this->stringfi();
    }

    bool operator > (const Bigint& b) const
    {
        if (this->arr.size() == b.arr.size()) {
            for (int i = this->arr.size() - 1; i >= 0;i--) {
                if (this->arr[i] > b.arr[i]) return true;
                else return false;
            }
        }

        if (this->arr.size() > b.arr.size()) return true;
        return false;
    }

    bool operator < (const Bigint& b) const
    {
        if (this->arr.size() == b.arr.size()) {
            for (int i = this->arr.size() - 1; i >= 0;i--) {
                if (this->arr[i] < b.arr[i]) return true;
                else return false;
            }
        }

        if (this->arr.size() < b.arr.size()) return true;
        return false;
    }

    bool operator == (const Bigint& b) const
    {
        if (this->arr.size() == b.arr.size() and this->znak  == b.znak) {
            for (int i = this->arr.size() - 1; i >= 0;i--) {
                if (this->arr[i] != b.arr[i]) return false;
            }
            return true;
        }
        return false;
    }
};

std::ostream& operator<<(std::ostream& out, const Bigint& num) {
    out << (num.str);
    return out;
}

Bigint operator + ( Bigint& a,  Bigint& b){   
    Bigint res;
    if ((a.znak or b.znak) and !(a.znak and b.znak)) {
        /*Серьезность	Код	Описание	Проект	Файл	Строка	Состояние подавления
Ошибка	C2676	бинарный "-": "Bigint" не определяет этот оператор или преобразование к типу приемлемо к встроенному оператору	contest_5	C:\Users\USER\source\repos\contest_5\contest_5\contest_5.cpp	408	
*/
    }
    int len;
    int buf = 0;
    if (a.arr.size() > b.arr.size()) len = a.arr.size();
    else len = b.arr.size();
    for (int i = 0; i < len; i++) {
        if (i >= a.arr.size()) {
            a.arr.push_back(0);
        }
        if (i >= b.arr.size()) {
            b.arr.push_back(0);
        }
        res.arr.push_back((buf + a.arr[i] + b.arr[i])%10);
        buf = (buf + a.arr[i] + b.arr[i]) / 10;
    }
    if (buf != 0) res.arr.push_back(buf);
    if (a.znak and b.znak) res.znak = true;
    res.str = res.stringfi();
    return res;
}

Bigint operator - (Bigint& a, Bigint& b)
{   
    Bigint res;
    if (a.znak and b.znak == false) {
        a.znak = false;
        res = (a + b);
        res.znak = true;
        res.str = res.stringfi();
        return res;
    }
    else if (a.znak and b.znak) {
        b.znak = false;
        a.znak = false;
        res = b - a;
        return res;
    }
    else if (a > b) {
        int len;
        int buf = 0;
        if (a.arr.size() > b.arr.size()) len = a.arr.size();
        else len = b.arr.size();
        for (int i = 0; i < len; i++) {
            if (i >= a.arr.size()) {
                a.arr.push_back(0);
            }
            if (i >= b.arr.size()) {
                b.arr.push_back(0);
            }

            if ((-buf + a.arr[i] - b.arr[i]) < 0) {
                res.arr.push_back(10 - buf + a.arr[i] - b.arr[i]);
                buf = 1;
            }
            else {
                res.arr.push_back(-buf + a.arr[i] - b.arr[i]);
                buf = 0;
            }
        }

        while (res.arr.size() > 1 && res.arr.back() == 0) res.arr.pop_back();
        res.str = res.stringfi();
        return res;
    }
    else {
        int len;
        int buf = 0;
        if (a.arr.size() > b.arr.size()) len = a.arr.size();
        else len = b.arr.size();
        for (int i = 0; i < len; i++) {
            if (i >= a.arr.size()) {
                a.arr.push_back(0);
            }
            if (i >= b.arr.size()) {
                b.arr.push_back(0);
            }

            if ((-buf - a.arr[i] + b.arr[i]) < 0) {
                res.arr.push_back(10 - buf - a.arr[i] + b.arr[i]);
                buf = 1;
            }
            else {
                res.arr.push_back(-buf - a.arr[i] + b.arr[i]);
                buf = 0;
            }
        }

        while (res.arr.size() > 1 && res.arr.back() == 0) res.arr.pop_back();
        res.znak = true;
        res.str = res.stringfi();
        return res;
    }
}

int main() {
    std::string a, b;
    std::cin >> a >> b;

    Bigint first(a);
    Bigint second(b);
    Bigint c;
    c = (first - second);
   // std::cout << first << std::endl;
    std::cout << "a + b = " << (first + second) << std::endl;
    std::cout << "a - b = " << (first - second) << std::endl;
    /*
    std::cout << "a * b = " << (first * second) << std::endl;
    std::cout << "a / b = " << (first / second) << std::endl;

    int c;
    std::cin >> c;
    Bigint third(c);
    Bigint zero;

    std::cout << "с > 0 = " << (third > zero) << std::endl;
    std::cout << "с < 0 = " << (third < zero) << std::endl;
    std::cout << "с == 0 = " << (third == zero) << std::endl;
    */
}

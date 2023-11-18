#include<vector>
#include <algorithm>

class Bigint {
public:
    std::vector<int> arr; //
    bool znak; // знак
    std::string str;//строковое представление

    std::string stringfi() {
        std::string res;
        for (auto i : this->arr) res = std::to_string(i) + res;
        if (this->znak and res != "0") { res = "-" + res;  }
        return res;
    }

    Bigint() {
        this->znak = false;
        this->arr.push_back(0);
        this->str = this->stringfi();
    }

    Bigint(int a) {
        if (a == 0) {
            this->arr.push_back(0);
            this->znak = false;
            this->str = this->stringfi();
        }
        else {
        this->znak = false;
        if (a < 0) {
            this->znak = true;
            a *= -1;
        }
        while (a > 0) {
            this->arr.push_back(a % 10);
            a /= 10;
        }
        this->str = this->stringfi();
        }
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
        if (this->arr == b.arr and this->znak == b.znak)return false;
        else if (this->arr.size() == b.arr.size() and !this->znak and !b.znak) {
            for (int i = this->arr.size() - 1; i >= 0;i--) {
                if (this->arr[i] == b.arr[i]) continue;
                if (this->arr[i] > b.arr[i]) return true;
                if (this->arr[i] < b.arr[i]) return false;
            }
        }
        else if (this->arr.size() == b.arr.size() and this->znak and b.znak) {
            for (int i = this->arr.size() - 1; i >= 0;i--) {
                if (this->arr[i] == b.arr[i]) continue;
                if (this->arr[i] > b.arr[i]) return false;
                if (this->arr[i] < b.arr[i]) return true;
            }
        }
        else if (this->znak and !b.znak)return false;
        else if (!this->znak and b.znak)return true;
        else if (this->arr.size() > b.arr.size() and !this->znak and !b.znak) return true;
        return false;
    }

    bool operator < (const Bigint& b) const
    {   
        if (*this == b) return false;
        return !(*this>b);
    }

    bool operator == (const Bigint& b) const
    {
        if (this->arr == b.arr and this->znak == b.znak)return true;
        return false;
    }
};

Bigint plus(Bigint a, Bigint b) {
    int carry = 0;
    for (size_t i = 0; i < std::max(a.arr.size(), b.arr.size()) || carry; ++i) {
        if (i == a.arr.size())
            a.arr.push_back(0);
        a.arr[i] += carry + (i < b.arr.size() ? b.arr[i] : 0);
        carry = a.arr[i] >= 10;
        if (carry)  a.arr[i] -= 10;
    }
    return a;
}

Bigint raz(Bigint a, Bigint b) {
    int carry = 0;
    a.znak = false;
    b.znak = false;
    bool f;
    if (a > b or a == b) f = false;
    if (a < b) {
        f = true;
        Bigint res;
        res = a;
        a = b;
        b = res;
    }
    for (size_t i = 0; i < b.arr.size() || carry; ++i) {
        a.arr[i] -= carry + (i < b.arr.size() ? b.arr[i] : 0);
        carry = a.arr[i] < 0;
        if (carry)  a.arr[i] += 10;
    }
    while (a.arr.size() > 1 && a.arr.back() == 0)
        a.arr.pop_back();
    a.znak = f;
    return a;
}

std::ostream& operator<<(std::ostream& out, const Bigint& num) {
    out << (num.str);
    return out;
}

Bigint operator +(Bigint a, Bigint b){
    Bigint res;
    res.arr.pop_back();
    if (a.znak != 1 and b.znak != 1) {
        res = plus(a, b);
    }
    else if (a.znak and b.znak) {
        a.znak = false;
        b.znak = false;
        res = plus(a,b);
        res.znak = true;
    }
    else if (a.znak != 1 and b.znak) {
        res = raz(a, b);
    }
    else if (a.znak and b.znak != 1) {
        res = raz(b, a);
    }
    res.str = res.stringfi();
    return res;
}

Bigint operator -(Bigint a, Bigint b) {
    Bigint res;
    if (a.znak != 1 and b.znak != 1) {
        res = raz(a,b);
    }
    else if (a.znak and b.znak != 1) {
        a.znak = false;
        res = plus(a,b);
        res.znak = true;
    }
    else if (a.znak and b.znak) {
        b.znak = false;
        a.znak = false;
        res = raz(b,a);
    }
    else if (a.znak != 1 and b.znak) {
        b.znak = false;
        res = plus(a,b);
    }
    res.str = res.stringfi();
    return res;
}

Bigint operator *(Bigint a, Bigint b) {
    Bigint res;
    res.arr.pop_back();
    res.arr.insert(res.arr.cbegin(),a.arr.size() + b.arr.size(),0);
    for (size_t i = 0; i < a.arr.size(); ++i)
        for (int j = 0, carry = 0; j < (int)b.arr.size() || carry; ++j) {
            long long cur = res.arr[i + j] + a.arr[i] * 1ll * (j < (int)b.arr.size() ? b.arr[j] : 0) + carry;
            res.arr[i + j] = int(cur % 10);
            carry = int(cur / 10);
        }
    while (res.arr.size() > 1 && res.arr.back() == 0)
        res.arr.pop_back();
    if (a.znak == b.znak) res.znak = false;
    if (a.znak != b.znak) res.znak = true;
    res.str = res.stringfi();
    return res;
}

Bigint operator /(Bigint a, Bigint b) {
    int k = 0;
    bool f;
    Bigint res;
    res.arr.pop_back();
    if (a.znak == b.znak) f = false;
    if (a.znak != b.znak) f = true;
    a.znak = false;
    b.znak = false;
    if (a < b) return Bigint(0);
    while (true) {
        k += 1;
        Bigint buf = (b * Bigint(k));
        if ((a == buf)) {
            res = Bigint(k);
            break;
        }
        if ((a < buf)) {
            res = Bigint(k-1);
            break;
        }
    }
    res.znak = f;
    res.str = res.stringfi();
    return res;
}

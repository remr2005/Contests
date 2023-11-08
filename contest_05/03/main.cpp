#include <complex>


class Complex
{
public:
    std::complex<double> com;
    Complex() {
        com.real(0);
        com.imag(0);
    }
    Complex(std::string a) {
        std::string Zn = "";
        std::string buf = "";
        bool f = true;
        int k = 0;
        for (auto I : a) {
            if (I == '-' and Zn == "" and f) {
                Zn = "-";
            }
            else if (I == '-' and Zn == "-" and f) {
                Zn = "";
            }
            else if ((I == '+' and f) or I == ' ') {
                continue;
            }
            else if (I == '-' or I == '+' and f == false) {
                com.real(std::stod(Zn + buf));
                if (k == 1) com.imag(std::stod(Zn + buf));
                buf = "";
                k += 1;
                if (I == '-') Zn = "-";
                else Zn = "";
                f = true;
            }
            else {
                buf += I;
                f = false;
            }
        }
        com.imag(std::stod(Zn + buf));
    }
};

std::ostream& operator<<(std::ostream& out, const Complex& num) {
    out << (num.com.real() == 0.0 ? 0.0 : num.com.real())
        << (num.com.imag() < 0 ? "" : "+")
        << (num.com.imag() == 0.0 ? 0.0 : num.com.imag()) << 'j';
    return out;
}


Complex operator + (const Complex& a, const Complex& b)
{
    Complex res;
    res.com = a.com + b.com;
    return res;
}

Complex operator - (const Complex& a, const Complex& b)
{
    Complex res;
    res.com = a.com - b.com;
    return res;
}

Complex operator * (const Complex& a, const Complex& b)
{
    Complex res;
    res.com = a.com * b.com;
    return res;
}

Complex operator / (const Complex& a, const  Complex& b)
{
    Complex res;
    res.com = a.com / b.com;
    return res;
}
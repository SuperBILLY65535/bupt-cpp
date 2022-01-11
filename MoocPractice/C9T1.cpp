//
// Created by 14799 on 2021/12/3.
//

#include <cstdio>
#include <iostream>
using namespace std;

class Complex{
private:
    int Re, Im;
public:
    explicit Complex(int _re = 1, int _im = 1) {
        Re = _re;
        Im = _im;
    }
    Complex(const Complex &_c) {
        this -> Re = _c.Re;
        this -> Im = _c.Im;
    }
    Complex operator+(const Complex &_c) const {
        Complex tmp;
        tmp.Re = this->Re + _c.Re;
        tmp.Im = this->Im + _c.Im;
        return tmp;
    }
    void output() const {
        printf("%.d+%di\n", Re, Im);
    }
};

int GetInt() {
    int tmp;
    cin >> tmp;
    return tmp;
}

int main() {
    Complex *c1 = new Complex(GetInt(), GetInt()), *c2 = nullptr;
    int tmp = GetInt();
    if(tmp == -1000) {
        c2 = new Complex;
        tmp = GetInt();
    }
    else {
        c2 = new Complex(tmp, GetInt());
    }
    Complex sum((*c1) + (*c2));
    sum.output();
    return 0;
}
#include <cstdio>
#include <algorithm>
#include <iostream>
#include <iomanip>
using namespace std;

template<typename T>
void bubbles_sort(const T* arrBegin, const T* arrEnd) {
    for(T* iterator = arrBegin; iterator != arrEnd; iterator = iterator + 1) {
        for(T* cur = arrEnd - 1; cur != iterator; cur = cur - 1) {
            if(*cur < *(cur - 1)) {
                swap(*cur, *(cur - 1));
            }
        } 
    }
}

int main() {
    int a[10];
    double b[10];
    for(int i = 0; i < 10; i++) {
        cin >> a[i];
    }
    for(int i = 0; i < 10; i++) {
        cin >> b[10];
    }
    bubbles_sort<int>(a, a+10);
    bubbles_sort<double>(b, b+10);
    for(int i = 0; i < 10; i++) {
        cout << a[i] << ",";
    }
    cout << endl << setprecision(1);
    for(int i = 0; i < 10; i++) {
        cout << b[i] << ",";
    }
    return 0;
}
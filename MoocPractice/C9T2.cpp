#include <iostream>
#include <cstdio>
using namespace std;

class point {
private:
    int x, y, colour;
public:
    point(int _x = 0, int _y = 0, int _z = 255) {
        x = _x; y = _y; colour = _z;
        printf("point(%d,%d,%d)\n", x, y, colour);
    }
    ~point() {
        cout << "point~~~" << endl;
    }
    int getX() {
        return x;
    }
    int getY() {
        return y;
    }
    int getColour() {
        return colour;
    }
};

class rect: public point {
private:
    int len, wid;
public:
    rect(int _x, int _y, int _l, int _h) : point(_x, _y) {
        len = _l; wid = _h;
        cout << "rect" << endl;
    }
    void output() {
        printf("%d,%d,%d,%d\n", getX(), getY(), len, wid);
    }
    ~rect() {
        cout << "rect~~~" << endl;
    }
};

int main() {
    int x, y, l, w;
    cin >> x >> y >> l >> w;
    rect r(x, y, l, w);
    r.output();
    return 0;
}
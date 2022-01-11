#include <cstdio>
using namespace std;
int value(int k) {
    if(k == 1) {
        return 10;
    }
    else {
        return value(k - 1) + 2;
    }
}
int main() {
    int n;
    scanf("%d", &n);
    printf("%d", value(n));
    return 0;
}
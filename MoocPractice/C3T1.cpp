#include <cstdio>
using namespace std;
bool check(int num, int k) {
    int count = 0;
    while(num >= 10) {
        count = count + (num % 10);
        num = num / 10;
    }
    if (num + count == k) {
        return true;
    }
    return false;
}
int main() {
    int k;
    scanf("%d", &k);
    for (int i = 100; i <= 500; i++) {
        if(check(i, k)) {
            printf("%d\n", i);
        }
    }
    return 0;
}
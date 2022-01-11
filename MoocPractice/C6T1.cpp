#include <cstdio>
#include <cmath>
using namespace std;
int main() {
    int a[255], b[255], n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    for(int i = 0; i < n; i++) {
        scanf("%d", &b[i]);
    }
    auto dim = [] (int x, int y) -> float {
        return (y - x) * (y - x);
    };
    float sum = 0;
    for(int i = 0; i < n; i++) {
        sum += dim(a[i], b[i]);
    }
    printf("%.2f", sqrt(sum));
    return 0;
}
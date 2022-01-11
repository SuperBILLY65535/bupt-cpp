#include <cstdio>
#include <cmath>
using namespace std;
int main() {
    int n, score[10], maxi = 0, mini = __INT_MAX__, sum = 0;
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        scanf("%d", &score[i]);
        sum = sum + score[i];
        mini = fmin(mini, score[i]);
        maxi = fmax(maxi, score[i]);
    }
    sum = sum - maxi - mini;
    double avg = (sum * 1.0) / (n - 2);
    printf("%.2lf", avg);
    return 0;
}
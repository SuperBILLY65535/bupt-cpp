#include <cstdio>
#include <algorithm>
using namespace std;
void bubbles_sort(long long a[], int len){
    for(int i = 0; i < len - 1; i++){
        for(int j = len - 2; j >= i; j--){
            if(a[j] > a[j+1]) {
                swap(a[j], a[j+1]);
            }
        }
    }
    return;
}
int main() {
    long long num[3];
    for(int i = 0; i < 3; i++) {
        scanf("%lld", &num[i]);
    }
    bubbles_sort(num, 3);
    // sort(&num[0], &num[3]);
    printf("%lld,%lld,%lld", num[0], num[1], num[2]);
    return 0;
}
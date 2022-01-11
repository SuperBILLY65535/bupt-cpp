#include <cstdio>
using namespace std;

template<typename T = int> 
T get_sum(T *begin, T *end) // end = (actual end) + 1
{
    T sum = 0, *iter = begin; //iter: iterator
    while(iter < end)
    {
        sum = sum + *iter;
        iter += 1;//iteration
    }
    return sum;
}

int main() 
{
    int a[5], b[2][3];
    for(int i = 0; i < 5; i++) scanf("%d", &a[i]);
    for(int i = 0; i < 2; i++) {
        for(int j = 0; j < 3; j++) {
            scanf("%d", &b[i][j]);
        }
    }//input
    printf(
        "%d %d", 
        get_sum(&(a[0]), &(a[0]) + 5) / 5,
        get_sum(&(b[0][0]), &(b[0][0]) + 2 * 3) / (2 * 3)
    );
    return 0;
}

/*
it's also correct to reconstruct line 27 as:
get_sum(a, a + 5) / 5
but it's incorrect to reconstruct line 28 as:
get_sum(b, b + 6) / 6
think about why
*/
#include <cstdio>
using namespace std;

template<typename T = int> 
double get_average(T *begin, size_t sz) // end = (actual end) + 1
{
    T sum = 0, *iter = begin; //iter: iterator
    for(size_t i = 0; i < sz; i++) 
    {
        sum = sum + *iter;
        iter = iter + 1;
    }
    return sum * 1.0 / sz;
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
        get_average(&(a[0]), 5),
        get_average(&(b[0][0]), 6)
    );
    return 0;
}

/*
it's also correct to reconstruct line 27 as:
get_average(a, a + 5)
but it's incorrect to reconstruct line 28 as:
get_average(b, b + 6)
think about why
*/
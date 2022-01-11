#include <cstdio>
#include <cmath>
#include <cstdlib>
using namespace std;
int main() {
	int max = 0, a;
	while(scanf("%d", &a)!= EOF) {
		max = (a>max)? a : max;
	}
	printf("%d", max);
	return 0;
}
#include <cstdio>
using namespace std;
struct Student {
    char name[256];
    int score[3], sum = 0, n;
    void init() {
        scanf("%d%s", &n, &this->name);
        scanf("%d%d%d", &this->score[0], &this->score[1], &this->score[2]);
        sum = (this->score[0] + this->score[1] + this->score[2]);
    }
    void out() {
        printf("%d,%s,%d\n", this->n, this->name, this->sum);
    }
};
int main() {
    Student stu[6];
    for(int i = 1; i < 6; i++) {
        stu[i].init();
    }
    for(int i = 1; i < 6; i++) {
        stu[i].out();
    }
    return 0;
}
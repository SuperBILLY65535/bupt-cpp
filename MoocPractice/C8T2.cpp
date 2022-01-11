#include <cstdio>
#include <cstring>
using namespace std;
class Student{
protected:
    char name[255], IDNum[8];
    int age = 19;
    double score = 89.5;
public:
    Student(const char* id, const char* n, const int &a, const int &s){
        strcpy(this->IDNum, id);
        strcpy(this->name, n);
        this->age = a;
        this->score = s;
    }
    Student(){
        strcpy(name, "Lili");
        strcpy(IDNum, "2021001");
        this->age = 19;
        this->score = 89.5;
    }
    void pr(){
        printf("%s,%s,%d,%.1f\n", IDNum, name, age, score);
    }
};

class Graduate: public Student {
protected:
    char research_field[255];
public:
    Graduate() : Student() {
        printf("construction\n");
        scanf("%s", research_field);
    }
    void pr(){
        printf("%s,%s,%s\n", IDNum, name, research_field);
    }
};
Graduate grad;
int main() {
    Student *stu = &grad;
    (*stu).pr();
    return 0;
}
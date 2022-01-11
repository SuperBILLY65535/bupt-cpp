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
    ~Student(){
        printf("%s,%s,~~~\n", this->IDNum, this->name);
    }
    Student(){
        strcpy(this->name, "Lili");
        strcpy(this->IDNum, "2021001");
        this->age = 19;
        this->score = 89.5;
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
    ~Graduate() {
        printf("%s,%s,%s,~~~\n", this->IDNum, this->name, this->research_field);
    }
};
int main() {
    Student stu;
    Graduate grad;
    return 0;
}
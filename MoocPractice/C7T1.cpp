#include <cstdio>
#include <cstring>

class Student{
private:
    char name[255], IDNum[8];
    int age = 19;
    double score = 89.5;
public:
    Student(const char* id, const char* n, const int &a, const int &s);
    ~Student();
    Student();
};

Student::Student(const char *id, const char *n, const int &a, const int &s) {
    strcpy(this->IDNum, id);
    strcpy(this->name, n);
    this->age = a;
    this->score = s;
}

Student::Student() {
    strcpy(this->name, "Lili");
    strcpy(this->IDNum, "2021001");
    this->age = 19;
    this->score = 89.5;
}

Student::~Student() {
    std::printf("%s,%s,~~~\n", this->IDNum, this->name);
}

int main() {
    char name[255], id[255];
    int age;
    double score;
    std::scanf("%s\n%s\n%d\n%lf", id, name, &age, &score);
    Student *stu1 = new Student;
    Student *stu2 = new Student(id, name, age, score);
    delete stu2;
    delete stu1;
    return 0;
}
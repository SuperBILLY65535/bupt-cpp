#include <cstdio>
#include <cstring>

struct Student{
    char name[255], IDNum[8];
    int age = 19;
    double score = 89.5;
    Student(const char* id, const char* n, const int &a, const int &s);
    void printInfo() {
        printf("%s,%s,%d,%.1lf\n", this->IDNum, this->name, this->age, this->score);
    }
    // ~Student() = default;
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

// Student::~Student() {
//     std::printf("%s,%s,~~~\n", this->IDNum, this->name);
// }

int main() {
    Student stu;
    stu.printInfo();
    printf("%s,%s,%d,%.1lf\n", stu.IDNum, stu.name, stu.age, stu.score);
    return 0;
}
#include <cstdio>
#include <cstring>
#include <cctype>

void opr(const int& n, char &ch) {
    ch = ((ch - 'A' + 1) + n) % 26 + 'A' - 1;
}

int main() {
    int n;
    char str[32];
    std::scanf("%d\n%s", &n, &str);
    for (auto &ch : str) {
        if(std::isupper(ch)) opr(n, ch);
    }
    std::printf("%s", str);
    return 0;
}
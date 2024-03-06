#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int P1001(int n) {
    int m = 0;
    if (!n)
        return 0;
    while (n > 1) {
        if (n % 2 == 0) {
            n = n / 2;
            m++;
        } else {
            n = (n * 3 + 1) / 2;
            m++;
        }
    }
    return m;
}

void P1002() {
    char* sum = (char*)malloc(100 * sizeof(char));
    char* a = (char*)malloc(100 * sizeof(char));
    const char* s[] = { "ling","yi","er","san","si","wu","liu","qi","ba","jiu" };
    int m;
    while (scanf("%s", a) != EOF) {
        m = 0;
        for (size_t i = 0; a[i] != '\0'; i++) {
            int n = a[i] - '0';
            m = m + n;
        }
        sprintf(sum, "%d", m);
        for (size_t i = 0; sum[i] != '\0'; i++) {
            int b = sum[i] - '0';
            sum[i + 1] != '\0' ? printf("%s ", s[b]) : printf("%s\n", s[b]);
        }
    }
}

int main() {

    P1002();
}
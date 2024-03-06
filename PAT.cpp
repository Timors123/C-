#include "head.h"

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

// NONE
// 函数：检查字符串是否符合PAT规则
int P1003(const char* str) {
    int len = strlen(str);
    int posP = -1, posT = -1;
    int countP = 0, countT = 0;

    // 遍历字符串，统计P、T的数量并记录它们的位置
    for (int i = 0; i < len; i++) {
        if (str[i] == 'P') { countP++; posP = i; } else if (str[i] == 'T') { countT++; posT = i; } else if (str[i] != 'A') return 0; // 包含除P、A、T之外的字符
    }

    // 确保P和T的数量均为1，且P在T之前
    if (countP != 1 || countT != 1 || posT <= posP) return 0;

    int a = posP; // P前面A的数量
    int b = posT - posP - 1; // P和T之间A的数量
    int c = len - posT - 1; // T后面A的数量
    // 检查是否满足aPbTc => aPbATca规则
    if (b > 0 && (c == a * b)) return 1; // b不能为0，且c必须等于a*b
    return 0;
}

int main() {

}
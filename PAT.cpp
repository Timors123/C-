#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int x(int n) {
    int m = 0;
    while (n) {
        if (!n)
            return 0;
        if (!(n % 2)) {
            n /= n;
            m++;
        } else {
            n = (n * 3 + 1) / 2;
            m++;
        }
    }
    return m;
}
int main() {
    int a;
    scanf("%d", &a);
    printf("%d\n", x(a));
    return 0;
}
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    const char *str = "HelloWorld";
    int len = strlen(str);
    char *p = (char *)malloc(100);

    // 将 str字符串 复制到 p
    strcpy(p, str);
    for (int i = 0; i < len; i++)
    {
        printf("%c", p[i]);
    }
}

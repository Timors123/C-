#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    const char *originStr = "61Hello1World1C1BB1Aa1";
    const char *addStr = "追加内容1";

    // strlen 返回字符串长度,不包括\0
    int lenStr = strlen(originStr);
    int lenAddStr = strlen(addStr);

    // 申请空间
    char *strPoint = (char *)malloc(100);
    // char *strPoint1 = (char *)malloc(100);
    // 申请失败关闭
    if (!strPoint)
        return 0;

    // strcpy 复制字符串(返回类型char*): 将 str字符串 复制到 p
    strcpy_s(strPoint, lenStr + 1, originStr);
    strncpy_s(strPoint, lenStr + 1, originStr, lenStr); // 超出补0
    printf("strPoint复制后: %s\n", strPoint);

    // strcat 字符串追加(返回类型char*): 在 p 后追加字符串 addStr
    strcat_s(strPoint, lenAddStr + lenStr + 1, addStr);
    printf("strPoint追加后: %s\n", strPoint);

    // strcmp 字符串比较(返回类型int): 比较 字符串p 与 str : 相同返回0,不同返回1
    printf("比较 字符串strPoint 与 originStr: %s\n", strcmp(strPoint, originStr) == 0 ? "相同" : "不相同");

    // scanf("%s:", strPoint1);
    // scanf("%s:", strPoint);
    // printf("比较 字符串strPoint 与 originStr: %s\n", strcmp(strPoint1, strPoint) == 0 ? "相同" : "不相同");

    // strchr 字符匹配(返回类型char*,返回指向首个字符的指针): 查找字符串strPoint 内的 字符l 第一次出现的地址, 成功返回地址%p,失败返回NULL(地址为0000...)
    // 结果与字符串地址相减 得 索引值
    // strrchr 末次匹配,从尾部查找
    printf("%d\n", strchr(strPoint, 'l') - strPoint);
    printf("%d 查找失败\n\n", !strchr(strPoint, 'x') == NULL);

    // strstr 字符串匹配(返回类型char*,返回指向首个字符的指针): 查找字符串strPoint 内的 字符串ll 第一次出现的地址
    printf("%s\n", strstr(strPoint, "ll") == NULL ? "查找失败" : "查找成功");
    printf("%s\n", strstr(strPoint, "xl") == NULL ? "查找失败" : "查找成功");

    // atoi 字符串转数字((返回类型int): 将字符串中的数字返回,遇到字符中止
    printf("%d\n", atoi(strPoint));

    // 后续strtok_r使用
    char *strPoint_r = (char *)malloc(100);
    strcpy(strPoint_r, strPoint);
    strcat(strPoint_r, "strtok_s");

    // strtok 字符串切割(返回类型char *, 返回被分解的第一个子字符串，如果没有可检索的字符串，则返回一个空指针) : 按某个字符切割字符串
    char **token = (char **)malloc(100);
    // 默认静态指针
    token[0] = strtok(strPoint, "1");
    int i = 0;
    while (token[i])
    {
        i++;
        // 在使用 strtok 函数时，token = strtok(NULL, delim); 这行代码是用来继续从原始字符串中获取下一个令牌（token）的。
        // 当你第一次调用 strtok 函数时，你会传递要分割的字符串作为第一个参数。在这次调用之后，如果你想继续获取更多的令牌
        // 你应该将第一个参数设置为 NULL。这告诉 strtok 函数继续从上次停止的地方开始分割字符串。
        // 第一次调用：strtok 在内部保存了一个静态指针指向你的原始字符串，它会扫描这个字符串，直到找到一个不包含在 delim 参数中的字符，那个位置就是第一个令牌的开始。
        // 然后，strtok 继续扫描直到再次遇到 delim 参数中的任意字符，它将该位置的字符替换为 \0（空字符），并返回指向当前令牌的指针。
        // 后续调用：通过将 str 参数设置为 NULL，strtok 知道它应该继续处理之前传递给它的字符串。它会从上次找到的令牌后面开始
        // 重复之前的查找和替换过程，返回找到的下一个令牌的指针。这一过程将持续进行，直到字符串的末尾。
        token[i] = strtok(NULL, "1");
    }
    printf("\nstrtok 按1切割:\n");
    int j = 0;
    while (token[j])
    {
        // 查看token内容
        printf("%s\n", token[j]);
        j++;
    }

    // strtok_r 使用自定的指针char_r指向截取末尾(线程安全)
    char **token_r = (char **)malloc(100);
    // 自定指针
    char *char_r;
    int k = 0;
    token_r[k] = strtok_r(strPoint_r, "1", &char_r);
    while (token_r[k])
    {
        k++;
        token_r[k] = strtok_r(NULL, "1", &char_r);
    }
    // 查看token内容
    printf("\nstrtok_r 按1切割:\n");
    int n = 0;
    while (token_r[n])
    {
        // 查看token_r内容
        printf("%s\n", token_r[n]);
        n++;
    }

    // memset函数 复制字符 c（一个无符号字符）到参数 str 所指向的字符串的前 n 个字符
    // 是在一段内存块中填充某个给定的值,它是对较大的结构体或数组进行清零操作的一种最快方法,int类型的一般都是赋值0或-1
    printf("memset前:%s\n", strPoint_r);
    memset(strPoint_r, 'C', 10);
    printf("memset后:%s\n", strPoint_r);

    // sscanf_s 从一个字符串中读取数据,用于字符串输入时要求缓冲区大小参数，而在读取整数时不需要这些参数
    int a, b, c;
    char sscan[50];
    sscanf_s("100 200 300 sscan", "%d %d %d %s", &a, &b, &c, &sscan, sizeof(sscan));
    printf("输出:%d %d %d %s", a, b, c, sscan);

    free(strPoint);
    free(strPoint_r);
}

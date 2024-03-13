#include "head.h"

// 求平均值
double avg(double* score) {
    double max = score[0], min = score[0], sum = 0, cout = 0;

    for (size_t i = 0; score[i] > 0; i++) {
        if (score[i] > max) {
            max = score[i];
        }
        if (score[i] < min) {
            min = score[i];
        }
        sum += score[i];
        cout++;
    }
    return (sum - max - min) / cout;
}

// 检查是否为自幂数
int checkNum(int n) {
    int count = 0;
    int sum = 0;
    int m = n;
    // 计算位数
    for (;m > 0;)
    {
        m /= 10;
        count++;
    }
    m = n;
    // 计算位值 顺序:个 十 百 千 万 ...
    for (size_t i = 0; i < count; i++)
    {
        sum += pow((n % 10), count);
        n /= 10;
    }
    return m == sum;
}

// 求自幂数 n-m之间
int* NumberOfDaffodils(int n, int m) {
    int* Daffodils = NULL, num = 0;

    for (size_t i = n; i < m; i++)
    {
        if (checkNum(i))
        {
            // 动态分配大小
            Daffodils = (int*)realloc(Daffodils, (num + 2) * sizeof(int));
            if (Daffodils == NULL)
            {
                // 重新分配失败后释放
                free(Daffodils);
                return NULL;
            }

            Daffodils[num + 1] = i;
            num++;
        }
    }
    // 水仙花总个数放入Daffodils[0]
    Daffodils[0] = num;

    // 打印下
    printf("共%d个:\n", Daffodils[0]);
    for (size_t i = 0; i < Daffodils[0]; i++)
    {
        printf("%d\n", Daffodils[i + 1]);
    }
    return Daffodils;
}

// 冒泡排序(优化) 升序
void BubblingSort(int* n) {
    // int n[10] = { 15,197,23,107,44,55,12,875,59,11 };
    int flag;
    for (size_t i = 0; i < 10 - 1; i++)
    {
        flag = 0;
        for (size_t j = 0; j < 10 - i - 1;j++)
        {
            if (n[j] > n[j + 1])
            {
                n[j] = n[j] + n[j + 1];
                n[j + 1] = n[j] - n[j + 1];
                n[j] = n[j] - n[j + 1];
                flag = 1;
            }
        }
        if (!flag)
            break;
        for (size_t i = 0; i < 10; i++) {
            printf("%d ", n[i]);
        }
        printf("\n");
    }
}

// 回文数
int Palindromes() {
    char* s = "01233210";
    if (s[0] == '0')
    {
        printf("不是");
        return 0;
    }
    int l = strlen(s);
    if (!(l % 2))
    {
        for (size_t i = 0; i < (l / 2); i++)
        {
            if (s[i] != s[l - i - 1])
            {
                printf("不是");
                return 0;
            }
        }
        printf("是");
    } else {
        for (size_t i = 0; i < (l - 1) / 2; i++)
        {
            if (s[i] != s[l - i - 1])
            {
                printf("不是");
                return 0;
            }
        }
        printf("是");
    }

}

void test() {
    char a, b;
    int c, d;
    scanf("%d%c%d%c", &c, &a, &d, &b);
    printf("%d %c %d %c", c, a, d, b);
}

int main() {
    test();
}


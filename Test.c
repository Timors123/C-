#include "head.h"

#define N 5
#define F(x) (sin(x)*cos(x)) 
#define PI acos(-1.0) 

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
    for (size_t i = 0; i < 10; i++)
    {
        flag = 0;
        for (size_t j = 0; j < 9 - i;j++)
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
            flag++;

        if (flag == 0)
            break;
    }
    for (size_t i = 0; i < 10; i++) {
        printf("%d ", n[i]);
    }
    printf("\n");
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

// 斐波那契数列
int Fibonacci(int n) {
    if (n == 0 || n == 1)
        return n;
    return Fibonacci(n - 1) + Fibonacci(n - 2);
}
int Fibonaccii(int n) {
    if (n == 0 || n == 1)
        return n;
    int a = 0, b = 1, temp = 0;
    for (size_t i = 1; i < n; i++)
    {
        temp = a + b;
        a = b;
        b = temp;
    }
    return temp;
}

// 八皇后
void EightQueen() {
    int queen[8] = { 0 };		//用来储存皇后的位置 即queen的值就为第i行的列
    //queen[0]表示第0行
    //queen[i]表示第i行
    int cnt = 0;			//表示摆放了几个皇后，也表示摆放皇后的行数。
    int col = 0;			//表示在这一列上摆放了皇后
    int sum = 0;			//总共有几种摆法
    while (1) {
        //在(cnt,col)这个坐标摆放皇后
        if (cnt == 1 && queen[0] == 7 && col == 6) {		//表示第一行的皇后已经到了第八列且第二行的皇后到了第七列位置，已经摆放不下皇后了就退出循环
            break;
        }
        int isAttack = 0;		//用来表示皇后们之间是否能够攻击的到，如果攻击的到就是1，否则就为0
        int i = 0;
        for (i = 0;i < cnt;i++) {
            if (queen[i] == col) {	//表示在同一列上
                isAttack = 1;
            }
            int div_row = cnt - i;		//表示斜线上的纵坐标之差
            int div_col = queen[i] - col;		//表示斜线上横坐标之差
            if (div_row == div_col || div_row == -div_col) { 	//表示在同一斜线上
                isAttack = 1;
            }
        }
        if (isAttack == 0) {	//表示可以放置
            queen[cnt] = col;		//记录皇后当前的列数
            cnt++;					//开始摆放下一个皇后
            col = 0;				//下一个皇后从第一列开始遍历
            if (cnt == 8) {			//如果摆满了八个皇后就打印出他们的摆法
                for (i = 0;i < 8;i++) {
                    printf("%d  ", queen[i] + 1);
                }
                printf("\n");
                sum++;				//并且摆放种数+1
                do {		//越界问题	//回朔
                    cnt--;		//撤回正在摆放的皇后
                    col = queen[cnt] + 1;		//往下一个列寻找摆放位置
                } while (col >= 8);
            }
        } else {			//表示不能摆放
            col++;
            while (col >= 8) {			//回朔
                cnt--;				//退一格
                col = queen[cnt] + 1;	//上一个皇后往后移一格
            }
        }
    }
    printf("总共有%d种摆法\n", sum);
}

void test() {

}

int main() {
    test();
}


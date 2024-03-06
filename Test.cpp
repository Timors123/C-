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
// 求水仙花数
int* NumberOfDaffodils() {
    int* Daffodils = NULL, num = 0;
    for (size_t i = 100; i < 1000; i++)
    {
        if (i == (pow(i % 10, 3) + pow(i / 10 % 10, 3) + pow(i / 100, 3)))
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
    return Daffodils;
}

int main() {

}

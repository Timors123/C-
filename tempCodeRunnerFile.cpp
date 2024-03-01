    int *res = NULL;
    int num = 0;
    for (size_t i = 100; i < 1000; i++)
    {
        int a = i % 10;      // 个位
        int b = i / 10 % 10; // 十位
        int c = i / 100;     // 百位
        // printf("%d,%d,%d, %d+%d+%d=%d\n", a, b, c, (int)pow(a, 3), (int)pow(b, 3), (int)pow(c, 3), (int)pow(a, 3) + (int)pow(b, 3) + (int)pow(c, 3));
        if (i == ((int)pow(a, 3) + (int)pow(b, 3) + (int)pow(c, 3)))
        {
            res = (int *)realloc(res, (num + 1) * sizeof(int));
            *(res + num) = i;
            num++;
        }
    }
    for (size_t i = 0; i < num; i++)
    {
        printf("%d\n", res[i]);
    }
    free(res);
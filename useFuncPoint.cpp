#include "head.h"

void show(int a);

void test() {
    printf("test调用\n");
}

void func(void (*pt)(void)) {
    printf("\nfunc开始\n");
    pt();
    printf("func结束\n");
}

// 回调函数使用(三方库)

void compress(const char** fileName, void (*p)(int)) {
    printf("\n\n开始压缩---\n");
    printf("压缩进度--- ");
    // 回调
    p(10);
}

void show(int a) {
    printf("%d", a);
}

int main() {
    func(test);

    // 模拟压缩
    const char* fileName[] = { "aa", "bc", "cc" };
    compress(fileName, show);
}

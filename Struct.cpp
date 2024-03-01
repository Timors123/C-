#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 50

// struct可以写main外,也可写内部

// 第二种 定义时创建 并初始化
struct Others
{
    char name[10];
    int age;
} other1 = {"other1", 1}, other2 = {"other2", 2};

// 创建结构体并起别名,不用每次加上struct
typedef struct Address
{
    // char province[50];
    // char city[50];
    const char *province;
    const char *city;
    int code;
} Address;

int main()
{
    // 第一种 定义后再创建 并初始化
    struct Person
    {
        // char name[10];
        const char *name;
        int age;
        Address address;
    };
    // person1 完全初始化
    struct Person person1 = {
                      "person0",
                      0,
                      {"P{person0}",
                       "C{person0}",
                       120}},
                  person2;

    // 修改char[]类型成员变量 person1 name要使用strcpy,但修改指针类型char*不需要,可直接修改指针指向
    // strcpy(person1.name, "person1");
    person1.name = "person1";
    person1.age = 1;
    person1.address = {"P{person1}",
                       "C{person1}",
                       120};

    // 这种方法不能再创建新的结构体,不可复用
    struct
    {
        char name[10];
        int age;
    } Person3, other3;

    // typedef 省略struct
    Address address1 = {"P{address1}", "C{address1}", 121}, address2 = {"P{address1}", "C{address1}", 122};

    printf("person1的name: %s, age: %d, province: %s, city: %s, code:%d \n",
           person1.name, person1.age, person1.address.province, person1.address.city, person1.address.code);

    // 指针动态分配的scanf标准输入
    person2.name = (const char *)malloc(MAX_NAME_LENGTH * sizeof(char));
    if (person2.name == NULL)
    {
        // 内存分配失败的处理
        printf("Failed to allocate memory for name.\n");
        return 1;
    }
    printf("输入姓名:");
    scanf_s("%s", person2.name, MAX_NAME_LENGTH);
    printf("输入年龄:");
    scanf_s("%d", &person2.age);
    printf("person2 姓名:%s 年龄:%d", person2.name, person2.age);

    // free不能释放带有const限定符的指针

    // C++ 中 const_cast去除const限定符
    // free(const_cast<char *>(person2.name));

    // C 中通过简单的强制类型转换
    free((void *)person2.name);

    // 这不是 free 函数的要求，但是是一个好的编程习惯。
    // 这样做可以帮助防止悬挂指针（指向已经释放内存的指针）的使用，因为尝试访问 NULL 指针通常会导致程序立即崩溃，从而更容易发现问题所在。
    person2.name = NULL;
}

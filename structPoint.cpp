#include "head.h"

typedef struct Person
{
    char name[100];
    int age;
    int height = 160; // 设置缺省值
} Person;

int main()
{
    Person person0 = {"person0", 10};
    Person *p0Ponint = &person0;
    printf("person 信息--姓名:%s ,年龄:%d ,身高:%d \n", p0Ponint->name, p0Ponint->age, p0Ponint->height);

    // 结构体数组与其他数组用法基本一致
    Person people[3] = {
        {"person1", 11},
        {"person2", 12},
        {"person3", 13}};

    Person *peoplePoint = people;
    for (size_t i = 0; i < 3; i++)
    {
        printf("person[%d] 信息--姓名:%s ,年龄:%d\n", i + 1, (peoplePoint + i)->name, (peoplePoint + i)->age);
    }

    Person *crowd;
    int num;
    printf("输入录入人数:");
    scanf_s("%d", &num);

    crowd = (Person *)malloc(num * sizeof(Person));
    if (crowd == NULL)
        return 1;

    for (size_t i = 0; i < num; i++)
    {
        printf("输入姓名,年龄,身高:\n");
        scanf_s("%s %d %d", (crowd + i)->name, sizeof((crowd + i)->name), &(crowd + i)->age, &(crowd + i)->height);
    }
    for (size_t i = 0; i < num; i++)
    {
        printf("姓名 %s, 年龄 %d,身高 %d \n", (crowd + i)->name, (crowd + i)->age, (crowd + i)->height);
    }
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 一个单链表

typedef struct Person
{
    char name[10];
    int age;
    struct Person *next;
} Person;

// 创建节点
Person *create(Person p)
{
    Person *pnew = (Person *)malloc(sizeof(Person));
    if (!pnew)
        return NULL;

    strcpy(pnew->name, p.name);
    pnew->age = p.age;
    pnew->next = NULL;

    return pnew;
}
// 尾插法
void insertEnd(Person **head, Person p)
{
    if (!p.age)
        return;
    Person *pnew = create(p);
    if (!*head)
    {
        *head = pnew;
        return;
    }

    Person *temp = *head;
    // 移动头节点
    while (temp->next)
        temp = temp->next;
    // 找到最后一个节点
    temp->next = pnew;
}
// 头插法
void insertHead(Person **head, Person p)
{
    if (!p.age)
        return;
    Person *pnew = create(p);
    if (!*head)
    {
        *head = pnew;
        return;
    }
    // 将新结点指向头节点
    pnew->next = *head;
    // 新节点成为新的头节点
    *head = pnew;
}
// 删除 : 根据结构体删除
void del(Person **head, Person p)
{
    // 记录被删节点的前一个节点pre
    Person *pre = NULL, *temp = *head;
    // 头节点为空
    if (!temp)
        return;
    // 删除头节点
    if (temp->age == p.age && !strcmp(temp->name, p.name))
    {
        *head = temp->next;
        free(temp);
        return;
    }
    // 遍历链表寻找目标
    while (temp)
    {
        if (temp->age == p.age && !strcmp(temp->name, p.name))
        {
            pre->next = temp->next;
        }
        pre = temp;
        temp = temp->next;
    }
    // 释放,不需要悬置,因为这是在个局部变量
    free(temp);
}

// 输出
void outPut(Person *head)
{
    while (head)
    {
        printf("\npout: 姓名-> %s,年龄-> %d", head->name, head->age);
        head = head->next;
    }
    printf("\n");
}

// 批量插入,根据传入insertFunc不同,选择不同的添加方法
void multInput(Person *people, Person **head, void (*insertFunc)(Person **head, Person p))
{
    for (int i = 0; people[i].age; i++)
        insertFunc(head, people[i]);
}

int main()
{
    Person *head = NULL;
    Person people[] = {{"p1", 11}, {"p2", 12}, {"p3", 13}, {"p4", 14}, {"", 0}};
    // 注意参数insertFunc,需要传入方法地址,而不是方法调用后的返回值
    multInput(people, &head, &insertEnd);
    outPut(head);
    // 删除头节点
    Person p1 = {"p1", 11};
    del(&head, p1);
    outPut(head);
}

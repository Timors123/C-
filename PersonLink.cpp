#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 一个单链表

// 指针判空
int PointIsNULL(void *p)
{
    // 指针为空,停止操作
    if (!p)
    {
        return 1;
    }
    return 0;
};

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
    // 头指针为空,该节点为头指针
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
    // 头指针为空,该节点为头指针
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

// 批量插入,根据传入insertFunc不同,选择不同的添加方法
void multInput(Person *people, Person **head, void (*insertFunc)(Person **head, Person p))
{
    for (int i = 0; people[i].age; i++)
        insertFunc(head, people[i]);
}

// 在n之后插入(尾插法和头插法为其特殊情况)
void nInsert(Person *people, Person **head, Person *nPerson, void (*FailureHandling)(Person **head, Person p))
{
    // 头指针为空,使用头插法
    if (PointIsNULL(*head))
    {
        // FailureHandling 头节点为空时使用头插法or尾插法
        multInput(people, &*head, FailureHandling);
        return;
    }
    // nPerson为空,则使用头插法
    if (PointIsNULL(nPerson))
    {
        multInput(people, &*head, insertHead);
        return;
    }
    // nPerson年龄为负数,则使用尾插插法
    if (nPerson->age < 0)
    {
        multInput(people, &*head, insertEnd);
        return;
    }
    // 正常情况
    Person *pre = *head;
    while (pre)
    {
        if (!strcmp(pre->name, nPerson->name) && pre->age == nPerson->age)
            break;
        pre = pre->next;
    }
    if (!pre)
    {
        printf("(未匹配,插入失败)");
        return;
    }
    Person *nextPerson = pre->next;
    Person *p = NULL;
    for (size_t i = 0; people[i].age > 0; i++)
    {
        p = create(people[i]);
        pre->next = p;
        pre = p;
    }
    pre->next = nextPerson;
}

// 删除 : 根据结构体删除
void del(Person **head, Person p)
{
    // 头指针为空,停止操作
    if (PointIsNULL(*head))
        return;
    // 记录被删节点的前一个节点pre
    Person *pre = NULL, *temp = *head;
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

// 清空链表
/*
要点注意 :  head 是一个指向头指针的指针。
          *head 解引用了这个指针,得到头指针本身,它直接指向链表的第一个节点。
*/
void clear(Person **head)
{
    // 头指针为空,停止操作
    if (PointIsNULL(*head))
        return;
    Person *phead = *head;
    while (phead)
    {
        Person *temp = phead;
        phead = phead->next;
        free(temp);
    }
    *head = NULL;
    return;
}
// 删除n-m之间的节点
void delnm(Person **head, Person *pn, Person *pm)
{
    // 判断头节点
    if (PointIsNULL(*head))
        return;
    // pm pn都为空 清空链表
    if (!pm && !pn)
        clear(head);

    Person *pre = *head;
    Person *next = *head;
    // 寻找pn位置
    while (pre && !PointIsNULL(pn))
    {
        if (!strcmp(pre->name, pn->name) && pre->age == pn->age)
            break;
        pre = pre->next;
    }
    // 寻找pm位置
    while (next)
    {
        if (PointIsNULL(pm))
        {
            if (!next->next)
                break;
            next = next->next;
        }
        else
        {
            if (!strcmp(next->name, pm->name) && next->age == pm->age)
                break;
            next = next->next;
        }
    }
    // pn 或 pm 找不到
    if (!pre || !next)
        return;
    // 开始删除
    while (pre->next != next)
    {
        Person *temp = pre->next;
        pre->next = temp->next;
        free(temp);
    }
    // 如果pm为空,删除pn之后所有节点,由于上述已经删除pn-尾节点之间节点,最后只需再删除尾节点
    if (PointIsNULL(pm))
    {
        Person *temp = next;
        pre->next = temp->next;
        free(temp);
    }
    // 如果pn为空,删除pm之前所有节点,由于上述已经删除头节点-pm之间节点,最后只需再删除头节点
    if (PointIsNULL(pn))
    {
        Person *temp = *head;
        *head = temp->next;
        free(temp);
    }
}

// 输出链表
void outPut(const char *desc, Person *head)
{
    printf("\n--- %s ---\n", desc);
    if (!head)
    {
        printf("NULL\n");
        return;
    }
    while (head)
    {
        printf("姓名-> %s,年龄-> %d \n", head->name, head->age);
        head = head->next;
    }
}

int main()
{
    Person *head = NULL;

    // 注意参数insertFunc,需要传入方法地址,而不是方法调用后的返回值
    Person multPeople[] = {{"m-p1", 11}, {"m-p2", 12}, {"m-p3", 13}, {"m-p4", 14}, {"", 0}};
    multInput(multPeople, &head, &insertEnd);
    outPut("批量插入", head);

    // n后插入(示例m-p1)( &nPerson==NULL头插法 ; nPerson.age<0尾插法 )
    Person nPeople[] = {{"n-p1", 111}, {"n-p2", 112}, {"n-p3", 113}, {"n-p4", 114}, {"", 0}};
    Person p1 = {"m-p1", 11};
    nInsert(nPeople, &head, &p1, NULL);
    outPut("n后插入(示例m-p1)", head);

    // 删除头节点(示例m-p1)
    del(&head, p1);
    outPut("删除(示例m-p1)", head);

    // 删除pn-pm之间的节点
    Person pn = {"n-p3", 113};
    Person pm = {"m-p3", 13};
    delnm(&head, &pn, &pm);
    outPut("删除pn-pm(示例n-p3~m-p3)", head);

    // 清空节点
    clear(&head);
    outPut("清空", head);
}

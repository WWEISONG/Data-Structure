#ifndef _LIST_H
#define _LIST_H
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#define INIT_SIZE 10
#define INCREMENT_SIZE 5

typedef int Elemtype;
typedef int Position;
typedef struct list
{
	Elemtype *elem;
	int length; //当前线性表的长度
	int size;//分配的线性表的大小
}List;

typedef List *plist;

//操作：创建一个线性表，并初始化；
//后置条件:返回一个plist指针；
plist CreatAndInit(int sum);

//操作：判断线性表是否为空表
//前置条件：接受一个plist指针
//后置条件：如果为空，返回False,否则，返回true；
bool isEmpty(plist L);

//操作：清空线性表
//前置条件:接受一个plist指针；
//后置条件：返回清空之后的线性表的指针；

plist Clearlist(plist L);

//操作：彻底清除这个表
//前置条件:接受一个plist指针
void Destroylist(plist L);

//操作：查找某个元素
//前置条件：接受一个plist指针，要查找的元素
//后置条件：返回这个元素的位置；
Position FindElem(plist L, Elemtype target);

//操作：插入
//前置条件：接受plist指针，待插入的元素e,插入的位置i；
//后置条件：插入成功，返回1，否则返回0；
int InserElem(plist L, Position i, Elemtype e);

//操作：删除某个元素；
//前置条件：接受plist指针，待删除的元素target;
//后置条件：删除成功，返回true,否则，返回false；
bool DeleteElem(plist L, Elemtype target);

//操作：遍历
//前置条件：接受plist指针；
void Traverselist(plist L);
#endif
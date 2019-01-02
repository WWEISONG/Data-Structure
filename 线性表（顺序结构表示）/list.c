#include <stdio.h>
#include <stdlib.h>
#include "list.h"

plist CreatAndInit(int sum)
{
	plist L;
	L = (List *) malloc (sizeof(List)); //给指向线性表的指针分配地址；
	if (L == NULL)
	{
		printf("内存空间不足，分配失败\n");
		return;
	}
	L->elem = (Elemtype *) malloc (INIT_SIZE * sizeof(Elemtype));//给存储数据的数组分配地址；
	L->length = sum;//为存储任何数据，当前长度为0；
	L->size = INIT_SIZE;

	return L;
}

bool isEmpty(plist L)
{
	if (L->length == 0)
		return true;
	else
		return false;
}

plist Clearlist(plist L)
{
	L->length = 0;
	return L;
}

void Destroylist(plist L)
{
	free(L->elem);
	L->length = 0;
	L->size = 0;
	free(L);
}

Position FindElem(plist L, Elemtype target)
{
	int i;
	for (i = 0; i < L->length - 1; i++)
	{
		if (target == L->elem[i])
		{
			return i;
		}
	}
	if (i >= L->length)
	{
		printf("表中没有这个元素\n");
		return -1;
	}
}

int InserElem(plist L,Position i, Elemtype e)
{
	Elemtype new;
	Elemtype *p;//用来移动元素
	Elemtype *q;//用来移动元素
	if (i < 0 || i > L->length)
	{
		printf("请插入正确的位置\n");
		return 0;
	}
	if (L->length >= L->size)
	{
		new = (Elemtype *) realloc (L->elem, (L->size + INCREMENT_SIZE) * sizeof(Elemtype));
		if (new == NULL)
		{
			printf("没有分配到内存空间\n");
			return 0;
		}
		L->elem = new;
		L->size = L->size + INCREMENT_SIZE;
	}
	p = &L->elem[i-1];
	q = &L->elem[L->length - 1];
	for (;q >= p; q--)
	{
		*(q + 1) = *q;
	}
	*p = e;
	L->length++;
	return 1;
}

bool DeleteElem(plist L, Elemtype target)
{
	Position i;
	Elemtype *p;
	Elemtype *q;
	if (isEmpty(L))
	{
		printf("表为空\n");
		return fasle;
	}
	for (i = 0; i < L->length; i++)
	{
		if (target == L->elem[i])
			break;
	}
	if (i >= L->length)
	{
		printf("表中没有要删除的元素\n");
		return false;
	}
	p = &L->elem[i];
	q = &L->elem[L->length - 1];
	for (; p <= q; p++)
	{
		*p = *(p + 1);
	}
	L->length--;
	return true;
}

void Traverselist(plist L)
{
	int i;
	printf("表中的数据为：\n");
	for (i = 0; i < L->length; i++)
	{
		printf("%d ", L->elem[i]);
	}
}
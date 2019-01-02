#include <stdlib.h>
#include <stdio.h>
#include "list.h"
#include <string.h>

int main(void)
{
	plist L;
	int i, sum, target;
	char ch, *inside;

	printf("请问您要输入多少个数：\n");
	scanf("%d",&sum);
	L = CreatAndInit(sum);
	printf("请依次输入您要输入的数据：\n");
	for (i = 0; i < sum; i++)
	{
		scanf("%d", &L->elem[i]);
	}
	printf("数据录入已经完成，请选择：\n");
	printf("d:删除一i个元素\n");
	printf("a:添加一个元素\n");
	printf("f:查找某个元素\n");
	printf("t:遍历\n");
	printf("q:退出\n");
	while (getchar() != '\n')
			continue;

	while ((ch = getchar()) != 'q')
	{
		inside = strchr("dafqt", ch);
		if (inside == NULL)
		{
			printf("请您输入dafq中的一个：\n");
			continue;
		}
		switch(ch)
		{
			case 'd':	printf("请您输入您要删除的元素：\n");
						scanf("%d",&target);
						DeleteElem(L, target);
						break;
			case 'a':	printf("请您输入您要新增的元素以及要插入的位置: \n"); 
						scanf("%d %d", &target, &i);
						InserElem(L, i, target);
						break;
			case 'f':	printf("请您输入您要查找的元素：\n");
						scanf("%d", &target);
						FindElem(L, target);
						break;
			case 't':   Traverselist(L);
                        break;
			default :	break;
		}
		printf("d:删除一i个元素\n");
		printf("a:添加一个元素\n");
		printf("f:查找某个元素\n");
		printf("t:遍历\n");
		printf("q:退出\n");
		while (getchar() != '\n')
			continue;		
	}
	printf("BYE!\n");
	return 0;
}
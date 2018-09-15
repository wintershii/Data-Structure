#include<stdio.h>
#include<stdlib.h>
/**
  顺序表的翻转 
*/
typedef struct array{//数据结构类型声明 
	int array[1001];
	int n;
}Arr;

/**
  翻转函数
  参数:顺序表指针 
*/ 
void Reverse(Arr *list)
{
	int n = list->n;
	for(int i = 0; i < n/2; i++)
	{
		int temp = list->array[i];
		list->array[i] = list->array[n-i-1];
		list->array[n-i-1] = temp;
	}
}

int main()
{
	Arr *list = NULL;
	list = (Arr *)malloc(sizeof(Arr));//申请内存空间 
	int n;//顺序表中元素个数 
	scanf("%d",&n);
	list->n = n;
	for(int i = 0; i < n; i++)
	{
		scanf("%d",&list->array[i]);
	}
	Reverse(list);
	for(int i = 0; i < n; i++)
	{
		printf("%d ",list->array[i]);
	}
	printf("\n");
}

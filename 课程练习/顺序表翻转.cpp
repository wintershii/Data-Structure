#include<stdio.h>
#include<stdlib.h>
/**
  ˳���ķ�ת 
*/
typedef struct array{//���ݽṹ�������� 
	int array[1001];
	int n;
}Arr;

/**
  ��ת����
  ����:˳���ָ�� 
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
	list = (Arr *)malloc(sizeof(Arr));//�����ڴ�ռ� 
	int n;//˳�����Ԫ�ظ��� 
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

#include<stdio.h>

void rotate(int array[],int n,int k)
{
	int temp;
	if(k % n != 0)
	{
		for(int i = 0; i < k; i++)
		{
			temp = array[n-1];
			for(int j = n-2; j >=0; j--)
			{
				array[j+1] = array[j];
			}
			array[0] = temp;
		}
	}
}

int main()
{
	int n;//数组中元素个数 
	int k;//需要循环移动的距离 
	int array[100];
	printf("请输入数组中元素个数:");
	scanf("%d",&n);
	for(int i = 0; i < n; i++)
	{
		scanf("%d",&array[i]);
	}
	for(int i = 0; i < n; i++)
	{
		printf("%d",array[i]);
	}
	printf("\n");
	printf("请输入要移动的长度:");
	scanf("%d",&k);
	rotate(array,n,k);
	for(int i = 0; i < n; i++)
	{
		printf("%d",array[i]);
	}
	printf("\n");
}

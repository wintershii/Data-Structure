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
	int n;//������Ԫ�ظ��� 
	int k;//��Ҫѭ���ƶ��ľ��� 
	int array[100];
	printf("������������Ԫ�ظ���:");
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
	printf("������Ҫ�ƶ��ĳ���:");
	scanf("%d",&k);
	rotate(array,n,k);
	for(int i = 0; i < n; i++)
	{
		printf("%d",array[i]);
	}
	printf("\n");
}

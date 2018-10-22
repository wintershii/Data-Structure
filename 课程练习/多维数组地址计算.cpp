#include<stdio.h>
#define MAX 100
#define ATTOM 4

int solve(int n,int array[],int site,int list[])
{
	int add = 0;
	for(int i = 0; i < n; i++)
	{
		int temp = 0;
		int mult = 1;
		for(int j = 0; j < n-i-1; j++)
		{
			mult *= array[j];
		}
		temp = mult * (list[i] - 1);
		add += temp;
	}
	return site + (add * ATTOM);
}

int main()
{
	int n;
	int array[MAX];
	int list[MAX];
	printf("请输入数组维数:");
	scanf("%d",&n);
	for(int i = 0; i < n; i++)
	{
		printf("请输入第%d维上限值:",n-i);
		scanf("%d",&array[i]);
	}
	int site;
	printf("请输入起始地址:");
	scanf("%d",&site);
	printf("请输入要计算的地址:");
	for(int i = 0; i < n; i++)
	{
		printf("请输入第%d维值:",i+1);
		scanf("%d",&list[i]);
	}
	printf("最终地址为:%d",solve(n,array,site,list));
	return 0;
}

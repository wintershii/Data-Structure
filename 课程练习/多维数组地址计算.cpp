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
	printf("����������ά��:");
	scanf("%d",&n);
	for(int i = 0; i < n; i++)
	{
		printf("�������%dά����ֵ:",n-i);
		scanf("%d",&array[i]);
	}
	int site;
	printf("��������ʼ��ַ:");
	scanf("%d",&site);
	printf("������Ҫ����ĵ�ַ:");
	for(int i = 0; i < n; i++)
	{
		printf("�������%dάֵ:",i+1);
		scanf("%d",&list[i]);
	}
	printf("���յ�ַΪ:%d",solve(n,array,site,list));
	return 0;
}

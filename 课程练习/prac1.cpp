#include<stdio.h>

/**
  最坏情况下，遍历了整个数组之后都没有找到k元素，
  在数组有n个元素的情况下，最坏情况时间复杂度为O(n)
  量级为n的线性阶 
*/ 
int main()
{
	int array[1001];//数组 
	int k;//要查找的k元素 
	int n;//数组中的数据个数 
	int site = 0;//设置位置初始值 
	scanf("%d",&n);
	for(int i = 0; i < n; i++)//录入数组array数据 
	{
		scanf("%d",&array[i]);
	}
	scanf("%d",&k);
	for(int i = 0; i < n; i++)
	{
		if(array[i] == k)
		{
			site = i + 1;
			break;//若查找到k元素，结束遍历 
		}
	}
	printf("%d\n",site);//输出结果 
	return 0;
}

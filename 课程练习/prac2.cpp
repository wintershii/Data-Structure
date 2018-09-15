#include<stdio.h>
#define MIN_INT 0x80000000//最小整形 
/**
  最坏情况下时间复杂度为O(n) 
*/
int main()
{
	int array[1001];//数组 
	int n;//数组中的数据个数
	int max1,max2;
	scanf("%d",&n);
	for(int i = 0; i < n; i++)//录入数组array数据 
	{
		scanf("%d",&array[i]);
	}
	max1 = array[0];
	max2 = MIN_INT;
	for(int i = 1; i < n; i++)
	{
		if(array[i] > max2)
		{
			if(array[i] > max1)
			{
				max2 = max1;
				max1 = array[i];
			} 
			else
			{
				max2 = array[i];
			}
		} 
	}
	if(max2 == MIN_INT)
	{
		max2 = max1;
	}
	printf("最大值:%d  次最大值:%d\n",max1,max2);
	return 0;
}

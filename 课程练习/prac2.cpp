#include<stdio.h>
#define MIN_INT 0x80000000//��С���� 
/**
  ������ʱ�临�Ӷ�ΪO(n) 
*/
int main()
{
	int array[1001];//���� 
	int n;//�����е����ݸ���
	int max1,max2;
	scanf("%d",&n);
	for(int i = 0; i < n; i++)//¼������array���� 
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
	printf("���ֵ:%d  �����ֵ:%d\n",max1,max2);
	return 0;
}

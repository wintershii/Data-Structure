#include<stdio.h>

/**
  �����£���������������֮��û���ҵ�kԪ�أ�
  ��������n��Ԫ�ص�����£�����ʱ�临�Ӷ�ΪO(n)
  ����Ϊn�����Խ� 
*/ 
int main()
{
	int array[1001];//���� 
	int k;//Ҫ���ҵ�kԪ�� 
	int n;//�����е����ݸ��� 
	int site = 0;//����λ�ó�ʼֵ 
	scanf("%d",&n);
	for(int i = 0; i < n; i++)//¼������array���� 
	{
		scanf("%d",&array[i]);
	}
	scanf("%d",&k);
	for(int i = 0; i < n; i++)
	{
		if(array[i] == k)
		{
			site = i + 1;
			break;//�����ҵ�kԪ�أ��������� 
		}
	}
	printf("%d\n",site);//������ 
	return 0;
}

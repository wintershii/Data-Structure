#include<stdio.h>
#include<string.h>

int judge(char str[])
{
	int len = strlen(str);//�ַ������� 
	for(int i = 0; i < len/2; i++)
	{
		if(str[i] != str[len-i-1])
			return 0;
	}
	return 1;
}

int main()
{
	char str[1000];
	gets(str);
	int k = judge(str);
	if(k == 1)
	{
		printf("�ǻ���\n");
	}
	else
	{
		printf("���ǻ���\n");
	}
	return 0;
}

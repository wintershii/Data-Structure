#include<stdio.h>
#include<string.h>

int judge(char str[])
{
	int len = strlen(str);//字符串长度 
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
		printf("是回文\n");
	}
	else
	{
		printf("不是回文\n");
	}
	return 0;
}

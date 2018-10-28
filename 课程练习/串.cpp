#include<stdio.h>
#include<string.h>

/**
  第一题 
*/ 
void change(char r[],char ch1,char ch2)
{
	for(int i = 0; i < strlen(r); i++)
	{
		if(r[i] == ch1)
		{
			r[i] = ch2;
		}
	}
}

/**
  第二题 
*/
void Delete(char r[],char ch)
{
	for(int i = 0; i < strlen(r); i++)
	{
		if(r[i] == ch)
		{
			for(int j = i; j < strlen(r); j++)
			{
				r[j] = r[j+1];
			}
			i--;
		}
	}
}

void get_nextval(char son[],int nextval[])
{
	int i,j;
	int len = strlen(son);
	i = 0;
	j = -1;
	nextval[0] = 0;
	while(i < len)
	{
		if(j == -1 || son[i] == son[j])
		{
			i++;
			j++;
			if(son[i] != son[j])	//改进部位：若当前字符与前缀字符不同 
			{
				nextval[i] = j + 1;		//则当前的j为nextval在i位置的值 
			}
			else
				nextval[i] = nextval[j];	//如果与前缀字符相同，则将前缀字符的nextval值赋值给nextval在i位置的值
		}
		else
			j= nextval[j] -1;
	}
}

void KMP(char str[],char son[],int pos)
{
	int i = pos;	//主串中的位置索引
	int j =-1;		//子串中的位置索引
	
	int len1 = strlen(str);
	int len2 = strlen(son);
	
	int next[1000];	//next数组
	get_nextval(son,next);
	
	while(i < len1 && j <len2)
	{
		if(j == -1 || str[i] == son[j])
		{
			i++;
			j++;
		}
		else
		{
			j = next[j] - 1;
		}
	}
	if(j = len2)
	{
		if(pos >= len1-len2 || i >= len1)
		{
			printf("不存在子串\n");
			return;
		}
		printf("查找到子串，起始索引在主串的%d处\n",i-len2);
	}
}


int main()
{
//	char r[100];
//	char ch,ch1,ch2;
//	printf("请输入字符串r:");
//	gets(r);
	
	//第一题 
//	printf("请输入字符ch1 ch2:");
//	scanf("%c %c",&ch1,&ch2);
//	change(r,ch1,ch2); 
//	puts(r);
	
//	//第二题 
//	printf("请输入字符ch:");
//	scanf("%c",&ch);
//	Delete(r,ch);
//	puts(r);
	
	//第三题
	char r1[100],r2[100];
	int index;
	printf("请输入串1:");
	gets(r1);
	printf("请输入串2:");
	gets(r2);
	printf("请输入起始位置:");
	scanf("%d",&index);
	KMP(r1,r2,index);
}

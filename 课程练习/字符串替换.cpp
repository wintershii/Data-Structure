#include<stdio.h>
#include<string.h>

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

void KMPandReplace(char major[],char son[],int pos,char rep[])
{
	int i = pos;	//主串中的位置索引
	int j =-1;		//子串中的位置索引
	
	int len1 = strlen(major);
	int len2 = strlen(son);
	
	int next[1000];	//next数组
	get_nextval(son,next);
	
	while(i < len1 && j <len2)
	{
		if(j == -1 || major[i] == son[j])
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
		if(pos > strlen(major)-len2 + 1|| i >= strlen(major))
		{
			printf("不存在子串了\n");
			return;
		}
		printf("查找到子串，起始索引在主串的%d处\n",i-len2);
		for(int k = strlen(major); k >= i; k--)
		{
			major[k + strlen(rep) - strlen(son)] = major[k];
		}
		
		for(int k = i-len2,g = 0; g < strlen(rep); k++,g++)
		{
			major[k] = rep[g];
		}
		printf("替换成功！\n"); 
		KMPandReplace(major,son,i-len2,rep);
	}
}

int main()
{
	char major[100],son[100],rep[100];
	printf("请输入主串:");
	gets(major);
	printf("请输入子串:");
	gets(son);
	printf("请输入替换串:");
	gets(rep);
	KMPandReplace(major,son,0,rep);
	puts(major);
}

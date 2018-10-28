#include<stdio.h>
#include<string.h>

/**
  ��һ�� 
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
  �ڶ��� 
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
			if(son[i] != son[j])	//�Ľ���λ������ǰ�ַ���ǰ׺�ַ���ͬ 
			{
				nextval[i] = j + 1;		//��ǰ��jΪnextval��iλ�õ�ֵ 
			}
			else
				nextval[i] = nextval[j];	//�����ǰ׺�ַ���ͬ����ǰ׺�ַ���nextvalֵ��ֵ��nextval��iλ�õ�ֵ
		}
		else
			j= nextval[j] -1;
	}
}

void KMP(char str[],char son[],int pos)
{
	int i = pos;	//�����е�λ������
	int j =-1;		//�Ӵ��е�λ������
	
	int len1 = strlen(str);
	int len2 = strlen(son);
	
	int next[1000];	//next����
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
			printf("�������Ӵ�\n");
			return;
		}
		printf("���ҵ��Ӵ�����ʼ������������%d��\n",i-len2);
	}
}


int main()
{
//	char r[100];
//	char ch,ch1,ch2;
//	printf("�������ַ���r:");
//	gets(r);
	
	//��һ�� 
//	printf("�������ַ�ch1 ch2:");
//	scanf("%c %c",&ch1,&ch2);
//	change(r,ch1,ch2); 
//	puts(r);
	
//	//�ڶ��� 
//	printf("�������ַ�ch:");
//	scanf("%c",&ch);
//	Delete(r,ch);
//	puts(r);
	
	//������
	char r1[100],r2[100];
	int index;
	printf("�����봮1:");
	gets(r1);
	printf("�����봮2:");
	gets(r2);
	printf("��������ʼλ��:");
	scanf("%d",&index);
	KMP(r1,r2,index);
}

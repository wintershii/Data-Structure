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

void KMPandReplace(char major[],char son[],int pos,char rep[])
{
	int i = pos;	//�����е�λ������
	int j =-1;		//�Ӵ��е�λ������
	
	int len1 = strlen(major);
	int len2 = strlen(son);
	
	int next[1000];	//next����
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
			printf("�������Ӵ���\n");
			return;
		}
		printf("���ҵ��Ӵ�����ʼ������������%d��\n",i-len2);
		for(int k = strlen(major); k >= i; k--)
		{
			major[k + strlen(rep) - strlen(son)] = major[k];
		}
		
		for(int k = i-len2,g = 0; g < strlen(rep); k++,g++)
		{
			major[k] = rep[g];
		}
		printf("�滻�ɹ���\n"); 
		KMPandReplace(major,son,i-len2,rep);
	}
}

int main()
{
	char major[100],son[100],rep[100];
	printf("����������:");
	gets(major);
	printf("�������Ӵ�:");
	gets(son);
	printf("�������滻��:");
	gets(rep);
	KMPandReplace(major,son,0,rep);
	puts(major);
}

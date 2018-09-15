#include<stdio.h>
#include<stdlib.h>

typedef struct node{//����������ݽṹ�������� 
	int data;
	struct node *next;
}Node,*LinkList;

LinkList Create()//���������� 
{
	int n;//�������е�Ԫ�ظ��� 
	scanf("%d",&n);
	LinkList pHead = NULL;
	LinkList pNew = NULL,pEnd = pHead;
	for(int i = 0; i < n; i++)
	{
		pNew = (LinkList)malloc(sizeof(Node));
		scanf("%d",&pNew->data);
		if(i == 0)//����������ĵ�һ���ڵ�ʱ 
		{
			pNew->next = NULL;
			pHead = pNew;
			pEnd = pHead;
		}
		else
		{
			pNew->next = NULL;
			pEnd->next = pNew;
			pEnd = pNew;
		}
	}
	return pHead;
}

/**
  �㷨��ʵ�ֺ���
  start��la������Ҫɾ���ĵ���ʼ�ڵ�
  end��la������Ҫɾ�������һ���ڵ�
  aPre��la������Ҫɾ���ڵ��ǰһ���ڵ�(��startΪla��һ���ڵ�ʱ��Ҫ���������)
  bPre��lb������start-end�ڵ�Ҫ�������������Ľڵ� 
*/ 
void Solve(LinkList *pa,LinkList *pb,int i,int len,int j)
{
	LinkList temp = *pa;
	LinkList start,end;
	LinkList aPre,bPre;
	if(i == 1)
	{
		start = *pa;
		
		temp = *pa;
		for(int k = 1; k < len; k++)
		{
			temp = temp->next;
		}
		end = temp;
		*pa = end->next;
	}
	else
	{
		for(int k = 1; k < i; k++)
		{
			if(k == i - 1)
			{
				aPre = temp;
			}
			temp = temp->next;
		}
		start = temp;
		
		temp = *pa;
		for(int k = 1; k < len; k++)
		{
			temp = temp->next;
		}
		end = temp;
		aPre->next = end->next;
	}
	
	temp = *pb;
	for(int k = 1; k < j; k++)
	{
		temp = temp->next;
	}
	bPre = temp;
	end->next = bPre->next;
	bPre->next = start;
}

int main()
{
	LinkList la,lb;
	la = (LinkList)malloc(sizeof(Node));
	lb = (LinkList)malloc(sizeof(Node));
	la = Create();
	lb = Create();
	
	int i,len,j;
	scanf("%d %d %d",&i,&len,&j);
	Solve(&la,&lb,i,len,j);
	
	//������ս�� 
	printf("la������");
	while(la != NULL)
	{
		printf("%d ",la->data);
		la = la->next;
	}
	printf("\n");
	printf("lb������");
	while(lb != NULL)
	{
		printf("%d ",lb->data);
		lb = lb->next;
	}
	printf("\n");
	return 0;
}

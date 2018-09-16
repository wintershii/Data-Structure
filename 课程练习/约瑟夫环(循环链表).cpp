#include<stdio.h>
#include<stdlib.h>
#include<time.h>
/**
  ˫��ѭ���������Լɪ������ 
*/ 
typedef struct node{//˫��ѭ����������ݽṹ�������� 
	int id;
	int data;
	struct node *pre,*next;
}Node,*LinkList;

/**
  �������� 
*/ 
LinkList Create(int n)
{
	LinkList pHead = NULL;
	LinkList pNew = NULL,pEnd = NULL;
	for(int i = 0; i < n; i++)
	{
		printf("�������%d���˵����룺",i+1);
		pNew = (LinkList)malloc(sizeof(Node));
		//scanf("%d",&pNew->data);
		pNew->data = rand()%9+1;;
		pNew->id = i+1;
		if(i == 0)
		{
			pHead = pNew;
			pEnd = pHead;
			pHead->next = pHead;
			pHead->pre = pHead;
		}
		else
		{
			pNew->next = pHead;
			pHead->pre = pNew;
			pNew->pre = pEnd;
			pEnd->next = pNew;
			pEnd = pNew;
		}
	}
	return pHead;
}

/**
  Լɪ���㷨ʵ�ֺ���
  ����:p ָ��ͷָ���ָ��; m ���� ;type ����˳ʱ��ת������ʱ��ת
  ˼·:�ݹ�ʵ�֣�ÿ��ɾ�����㵽�Ľڵ㲢�����ֱ��������ֻʣ���һ���ڵ� 
*/ 
void Solve(LinkList *p,int m,int type,int site)
{
	for(int i = 1; i < site; i++)
	{
		(*p) = (*p)->next;
	}
	if(type == 1)
	{
		if((*p)->next == *p)
		{
			printf("��%d����(����%d)���һ����\n",(*p)->id,(*p)->data);
			return;
		}
		LinkList head = *p;
		LinkList temp = head;
		LinkList pre,aft;
		for(int i = 1; i < m; i++)
		{
			temp = temp->next;
		}
		int data = temp->data;
		pre = temp->pre;
		aft = temp->next;
		aft->pre = pre;
		pre->next = aft;
		printf("��%d����(����%d)����\n",temp->id,data);
		free(temp);
		Solve(&aft,data,1,1);
	}
	else
	{
		if((*p)->pre == *p)
		{
			printf("��%d����(����%d)���һ����\n",(*p)->id,(*p)->data);
			return;
		}
		LinkList head = *p;
		LinkList temp = head;
		LinkList pre,aft;
		for(int i = 1; i < m; i++)
		{
			temp = temp->pre;
		}
		int data = temp->data;
		pre = temp->pre;
		aft = temp->next;
		aft->pre = pre;
		pre->next = aft;
		free(temp);
		printf("��%d����(����%d)����\n",temp->id,data);
		Solve(&pre,data,2,1);
	}
}

/**
  ����˫��ѭ������ 
*/
void Print(LinkList head,int type)
{
	LinkList temp = head;
	printf("-----����˫��ѭ������-----\n");
	printf("---ID---  ---PWD---\n");
	if(type == 1)
	{
		while(temp->next != head)
		{
			printf("   %d        %d   \n",temp->id,temp->data);
			temp = temp->next;
		}
		printf("   %d        %d   \n",temp->id,temp->data);
	}
	else
	{
		while(temp->pre != head)
		{
			printf("   %d        %d   \n",temp->id,temp->data);
			temp = temp->pre;
		}
		printf("   %d        %d   \n",temp->id,temp->data);
	}
}

int main()
{
	LinkList pHead;
	int m;
	
	int n;
	printf("����������:");
	scanf("%d",&n);
	pHead = Create(n);
	Print(pHead,1);
	printf("�������ʼ����:");
	scanf("%d",&m);
	printf("˳ʱ����̭:\n");
	srand(time(NULL));
	//Solve(&pHead,m,1);
	int fir = rand()%n+1;
	printf("��%d��ʼ����\n",fir);
	Solve(&pHead,m,1,fir);
	
	printf("����������:");
	scanf("%d",&n);
	pHead = Create(n);
	Print(pHead,2);
	scanf("%d",&m);
	printf("��ʱ����̭:\n");
	Solve(&pHead,m,2,fir);
	return 0;
}

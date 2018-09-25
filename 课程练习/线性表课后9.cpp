#include<stdio.h>
#include<stdlib.h>
/**
  ��������ָ�����ɹ鲢 
*/
typedef struct node{
	int data;
	struct node *next;
}Node,*LinkList;

int Min(int a,int b)
{
	if(a <= b)
		return a;
	return b;
}

LinkList Create(int n)
{
	LinkList pHead = (LinkList)malloc(sizeof(Node));
	LinkList pNew = NULL,pEnd = pHead;
	pHead->next = NULL;
	for(int i = 0; i < n; i++)
	{
		pNew = (LinkList)malloc(sizeof(Node));
		scanf("%d",&pNew->data);
		pNew->next = NULL;
		pEnd->next = pNew;
		pEnd = pNew;
	}
	return pHead;
}

/**
  �ϲ������� 
*/ 
LinkList Merge(LinkList la,LinkList lb,int m,int n)
{
	LinkList aHead , bHead;
	LinkList cHead = (LinkList)malloc(sizeof(Node));
	if(m <= n)
	{
		aHead = la->next;
		bHead = lb->next;
	}
	else
	{
		aHead = lb->next;
		bHead = la->next;
	}
		LinkList pTemp = cHead;
		int t = 1;
		while(t <= Min(m,n))
		{
			pTemp->next = aHead;
			LinkList aftA = aHead->next;
			aHead->next = bHead;
			LinkList aftB = bHead->next;
			aHead = aftA;
			pTemp = bHead;
			bHead = aftB;
			t++;
		}
	return cHead;
}

/**
  ��������������� 
*/ 
void Print(LinkList head)
{
	LinkList temp = head->next;
	while(temp != NULL)
	{
		printf("%d ",temp->data);
		temp = temp->next;
	}
	printf("\n");
}

int main()
{
	LinkList la,lb;
	int m,n;
	scanf("%d",&m);//A��ĳ��� 
	la = Create(m);
	scanf("%d",&n);
	lb = Create(n);//B��ĳ��� 
	printf("LA����");
	Print(la);
	printf("LB����");
	Print(lb);
	
	LinkList cHead = Merge(la,lb,m,n);
	printf("�ϲ�������");
	Print(cHead);
	return 0;
}

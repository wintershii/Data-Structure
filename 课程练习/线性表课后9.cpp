#include<stdio.h>
#include<stdlib.h>
/**
  两单链表按指定规律归并 
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
  合并两链表 
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
  遍历输出链表数据 
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
	scanf("%d",&m);//A表的长度 
	la = Create(m);
	scanf("%d",&n);
	lb = Create(n);//B表的长度 
	printf("LA链表：");
	Print(la);
	printf("LB链表：");
	Print(lb);
	
	LinkList cHead = Merge(la,lb,m,n);
	printf("合并后链表：");
	Print(cHead);
	return 0;
}

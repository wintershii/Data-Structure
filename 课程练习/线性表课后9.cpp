#include<stdio.h>
#include<stdlib.h>
/**
  两单链表按指定规律归并 
*/
typedef struct node{
	int data;
	struct node *next;
}Node,*LinkList;

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

LinkList Merge(LinkList la,LinkList lb,int m,int n)
{
	LinkList aHead = la->next, bHead = lb->next;
	LinkList cHead = (LinkList)malloc(sizeof(Node));
	if(m <= n)
	{
		LinkList pTemp = cHead;
		int t = 1;
		while(t <= m)
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
	}
	else
	{
		LinkList pTemp = cHead;
		int t = 1;
		while(t <= n)
		{
			pTemp->next = bHead;
			LinkList aftB = bHead->next;
			bHead->next = aHead;
			LinkList aftA = aHead->next;
			bHead = aftB;
			pTemp = aHead;
			aHead = aftA;
			t++;
		}
	}
	return cHead;
}

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
	scanf("%d",&m);
	la = Create(m);
	scanf("%d",&n);
	lb = Create(n);
	printf("LA链表：");
	Print(la);
	printf("LB链表：");
	Print(lb);
	
	LinkList cHead = Merge(la,lb,m,n);
	printf("合并后链表：");
	Print(cHead);
	return 0;
}

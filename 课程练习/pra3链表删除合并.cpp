#include<stdio.h>
#include<stdlib.h>

typedef struct node{//单链表的数据结构类型声明 
	int data;
	struct node *next;
}Node,*LinkList;

LinkList Create()//创建单链表 
{
	int n;//单链表中的元素个数 
	scanf("%d",&n);
	LinkList pHead = NULL;
	LinkList pNew = NULL,pEnd = pHead;
	for(int i = 0; i < n; i++)
	{
		pNew = (LinkList)malloc(sizeof(Node));
		scanf("%d",&pNew->data);
		if(i == 0)//创建单链表的第一个节点时 
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
  算法的实现函数
  start：la链表中要删除的的起始节点
  end：la链表中要删除的最后一个节点
  aPre：la链表中要删除节点的前一个节点(当start为la第一个节点时需要分情况讨论)
  bPre：lb链表中start-end节点要被插入在其后面的节点 
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
	
	//输出最终结果 
	printf("la单链表：");
	while(la != NULL)
	{
		printf("%d ",la->data);
		la = la->next;
	}
	printf("\n");
	printf("lb单链表：");
	while(lb != NULL)
	{
		printf("%d ",lb->data);
		lb = lb->next;
	}
	printf("\n");
	return 0;
}

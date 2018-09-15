#include<stdio.h>
#include<stdlib.h>
/**
  单链表的递归翻转 
*/
typedef struct node{//单链表节点数据类型声明 
	int data;
	struct node *next;
}Node,*LinkList;

typedef struct list{//单链表数据结构声明 
	LinkList head;
	int n;
}List;

/**
  创建单链表，参数为单链表中的元素个数 
*/ 
LinkList Create(int n)
{
	LinkList pHead = (LinkList)malloc(sizeof(Node));
	pHead->next = NULL;
	LinkList pNew = NULL,pEnd = pHead;
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
  单链表的翻转函数 
*/
LinkList Reverse(LinkList pHead)
{
	if(pHead->next == NULL)
    {
        return pHead;
    }
    LinkList newhead = Reverse(pHead->next); //递归实现 
    pHead->next->next = pHead;
    pHead->next = NULL;
    return newhead;
}

int main()
{
	LinkList pHead = NULL;
	int n;
	scanf("%d",&n);
	pHead = Create(n);
	List *list = NULL;
	list = (List *)malloc(sizeof(List));
	list->head = pHead;
	list->n = n;
	pHead->next = Reverse(list->head->next);
	list->head = pHead;
	LinkList pTemp = pHead->next;
	for(int i = 0; i < n; i++)
	{
		printf("%d ",pTemp->data);
		pTemp = pTemp->next;
	}
	printf("\n");
	return 0;
}

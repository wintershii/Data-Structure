#include<stdio.h>
#include<stdlib.h>
/**
  ������ĵݹ鷭ת 
*/
typedef struct node{//������ڵ������������� 
	int data;
	struct node *next;
}Node,*LinkList;

typedef struct list{//���������ݽṹ���� 
	LinkList head;
	int n;
}List;

/**
  ��������������Ϊ�������е�Ԫ�ظ��� 
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
  ������ķ�ת���� 
*/
LinkList Reverse(LinkList pHead)
{
	if(pHead->next == NULL)
    {
        return pHead;
    }
    LinkList newhead = Reverse(pHead->next); //�ݹ�ʵ�� 
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

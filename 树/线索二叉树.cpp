#include<stdio.h>
#include<stdlib.h>

typedef enum {Link,Thread} PointerTag;

typedef struct BiThrNode
{
	int data;
	BiThrNode *lchild,*rchild;
	PointerTag LTag;
	PointerTag RTag;
} BiThrNode,*BiThrTree;

BiThrTree pre;

/**
    二叉树中序遍历线索化 
*/
void InThreading(BiThrTree T)
{
	if(T)
	{
		InThreading(T->lchild);
		if(!T->lchild)
		{
			T->LTag = Thread;
			T->lchild = pre;
		}
		if(pre != NULL && !pre->rchild)
		{
			pre->RTag = Thread;
			pre->rchild = T;
		}
		pre = T;
		InThreading(T->rchild);
	}
}

/**
    二叉树的创建 
*/
BiThrTree CreateBiTree(BiThrTree T,int step)
{
	printf("请输入%d层的数据:",++step);
	int data;
	scanf("%d",&data);
	if(data == -1)
	{
		T = NULL;
	}
	else
	{
		T = (BiThrTree)malloc(sizeof(BiThrNode));
		T->data = data;
		T->LTag = Link;
		T->RTag = Link;
		T->lchild = CreateBiTree(T->lchild,step);
		T->rchild = CreateBiTree(T->rchild,step);
	}
	return T;
}

/**
	指定头指针，连接二叉树，并将其线索化后，尾部连接到头指针 
*/
BiThrTree InOrderThreading(BiThrTree pHead,BiThrTree T)
{
	pHead = (BiThrTree)malloc(sizeof(BiThrNode));
	
	pHead->LTag = Link;
	pHead->RTag = Thread;
	pHead->rchild = pHead;
	if(!T)
	{
		pHead->lchild = pHead;
	}
	else
	{
		pHead->lchild = T;
		
		pre = pHead;
		InThreading(T);
		
		pre->RTag = Thread;
		pre->rchild = pHead;
		pHead->rchild = pre;
	}
	return pHead;
}

/**
	线索二叉树的遍历 
*/
void InOrderTraverse(BiThrTree pHead)
{
	BiThrTree T = pHead->lchild;
	while(T != pHead)
	{
		while(T->LTag == Link)
			T = T->lchild;
		printf("%d  ",T->data);
		while(T->RTag == Thread && T->rchild != pHead)
		{
			T = T->rchild;
			printf("%d  ",T->data);
		}
		T = T->rchild;
	}
}

int main()
{
	BiThrTree T;
	T = CreateBiTree(T,0);
	BiThrTree pHead;
	pHead = InOrderThreading(pHead,T);
	InOrderTraverse(pHead);
	return 0;
}

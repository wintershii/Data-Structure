#include<stdio.h>
#include<stdlib.h>

typedef struct BiTNode
{
	int data;
	BiTNode *lchild,*rchild;
}*BiTree;

/**
二叉树的建立 ，输入-1即表示该节点没有数据 
*/
BiTree CreateBiTree(BiTree T,int step)
{
	char num;
	printf("请输入第%d层的数据:",++step);
	scanf("%d",&num); 
	if(num == -1)
	{
		T = NULL;
	}
	else
	{
		T = (BiTree)malloc(sizeof(BiTNode));
		T->data = num;
		T->lchild = CreateBiTree(T->lchild,step);
		T->rchild = CreateBiTree(T->rchild,step);
	}
	return T;
}

/**
二叉树的前序遍历 
*/ 
void PreOrderTraverse(BiTree T)
{
	if(T == NULL)
		return;
	printf("%d  ",T->data);
	PreOrderTraverse(T->lchild);
	PreOrderTraverse(T->rchild);
}

/**
二叉树的中序遍历 
*/ 
void InOrderTraverse(BiTree T)
{
	if(T == NULL)
		return;
	InOrderTraverse(T->lchild);
	printf("%d  ",T->data);
	InOrderTraverse(T->rchild);
}

/**
二叉树的后序遍历 
*/ 
void PostOrderTraverse(BiTree T)
{
	if(T == NULL)
		return;
	PostOrderTraverse(T->lchild);
	PostOrderTraverse(T->rchild);
	printf("%d  ",T->data);
}


int main()
{
	BiTree T;
	int step;
	T = CreateBiTree(T,0);
	printf("前序遍历:"); 
	PreOrderTraverse(T);
	printf("\n");
	
	printf("中序遍历:"); 
	InOrderTraverse(T);
	printf("\n");
	
	printf("后序遍历:"); 
	PostOrderTraverse(T);
	printf("\n");
	
	return 0;
}

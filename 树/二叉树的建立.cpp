#include<stdio.h>
#include<stdlib.h>

typedef struct BiTNode	//节点结构:该节点数据与指向两孩子节点的指针 
{
	int data;
	BiTNode *lchild,*rchild;
}*BiTree;

/**
	二叉树的建立 ，输入-1即表示该节点没有数据 
*/
BiTree CreateBiTree(BiTree T,int step)
{
	int num;
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
		T->lchild = CreateBiTree(T->lchild,step);	//递归对建立左孩子二叉树 
		T->rchild = CreateBiTree(T->rchild,step);	//递归对建立右孩子二叉树
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
	printf("%d  ",T->data);	//先输出，再递归遍历左右孩子 
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
	printf("%d  ",T->data);	//先递归遍历左孩子，再输出，再递归遍历右孩子 
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
	printf("%d  ",T->data);	//先递归左右孩子，再输出 
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

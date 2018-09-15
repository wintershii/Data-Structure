#include<stdio.h>
#include<stdlib.h>

typedef struct BiTNode	//�ڵ�ṹ:�ýڵ�������ָ�������ӽڵ��ָ�� 
{
	int data;
	BiTNode *lchild,*rchild;
}*BiTree;

/**
	�������Ľ��� ������-1����ʾ�ýڵ�û������ 
*/
BiTree CreateBiTree(BiTree T,int step)
{
	int num;
	printf("�������%d�������:",++step);
	scanf("%d",&num); 
	if(num == -1)
	{
		T = NULL;
	}
	else
	{
		T = (BiTree)malloc(sizeof(BiTNode));
		T->data = num;
		T->lchild = CreateBiTree(T->lchild,step);	//�ݹ�Խ������Ӷ����� 
		T->rchild = CreateBiTree(T->rchild,step);	//�ݹ�Խ����Һ��Ӷ�����
	}
	return T;
}

/**
	��������ǰ����� 
*/ 
void PreOrderTraverse(BiTree T)
{
	if(T == NULL)
		return;
	printf("%d  ",T->data);	//��������ٵݹ�������Һ��� 
	PreOrderTraverse(T->lchild);
	PreOrderTraverse(T->rchild);
}

/**
	��������������� 
*/ 
void InOrderTraverse(BiTree T)
{
	if(T == NULL)
		return;
	InOrderTraverse(T->lchild);
	printf("%d  ",T->data);	//�ȵݹ�������ӣ���������ٵݹ�����Һ��� 
	InOrderTraverse(T->rchild);
}

/**
	�������ĺ������ 
*/ 
void PostOrderTraverse(BiTree T)
{
	if(T == NULL)
		return;
	PostOrderTraverse(T->lchild);
	PostOrderTraverse(T->rchild);
	printf("%d  ",T->data);	//�ȵݹ����Һ��ӣ������ 
}


int main()
{
	BiTree T;
	int step;
	T = CreateBiTree(T,0);
	printf("ǰ�����:"); 
	PreOrderTraverse(T);
	printf("\n");
	
	printf("�������:"); 
	InOrderTraverse(T);
	printf("\n");
	
	printf("�������:"); 
	PostOrderTraverse(T);
	printf("\n");
	
	return 0;
}

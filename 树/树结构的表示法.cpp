#include<stdio.h>
#include<stdlib.h>

//˫�ױ�ʾ�� 
typedef struct PTNode
{
	int data;
	int parent
}PTNode;

typedef struct
{
	PTNode nodes[100]; //�ڵ�����
	int r,n	//����λ�úͽڵ��� 
}

//���ӱ�ʾ��
typedef struct CTNode	//���ӽڵ� 
{
	int child;
	struct CTNode *next;
}*ChildPtr;

typedef struct	//��ͷ�ṹ 
{
	int data;
	ChildPtr firstchild;
}CTBox

typedef struct	//���ṹ 
{
	CTBox nodes[100];	//�ڵ����� 
	int r,n;	//����λ�úͽڵ��� 
}CTree;

//���ĺ����ֵܱ�ʾ��
typedef struct CSNode
{
	int data;
	struct CSNode *firstchild,*rightsib;
}CSNode,*CSTree;


int main()
{
	
	return 0;
} 

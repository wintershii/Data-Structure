#include<stdio.h>
#include<stdlib.h>

//双亲表示法 
typedef struct PTNode
{
	int data;
	int parent
}PTNode;

typedef struct
{
	PTNode nodes[100]; //节点数组
	int r,n	//根的位置和节点数 
}

//孩子表示法
typedef struct CTNode	//孩子节点 
{
	int child;
	struct CTNode *next;
}*ChildPtr;

typedef struct	//表头结构 
{
	int data;
	ChildPtr firstchild;
}CTBox

typedef struct	//树结构 
{
	CTBox nodes[100];	//节点数组 
	int r,n;	//根的位置和节点数 
}CTree;

//树的孩子兄弟表示法
typedef struct CSNode
{
	int data;
	struct CSNode *firstchild,*rightsib;
}CSNode,*CSTree;


int main()
{
	
	return 0;
} 

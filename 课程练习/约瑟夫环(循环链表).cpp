#include<stdio.h>
#include<stdlib.h>
#include<time.h>
/**
  双向循环链表求解约瑟夫环问题 
*/ 
typedef struct node{//双向循环链表的数据结构类型声明 
	int id;
	int data;
	struct node *pre,*next;
}Node,*LinkList;

/**
  创建链表 
*/ 
LinkList Create(int n)
{
	LinkList pHead = NULL;
	LinkList pNew = NULL,pEnd = NULL;
	for(int i = 0; i < n; i++)
	{
		pNew = (LinkList)malloc(sizeof(Node));
		//scanf("%d",&pNew->data);
		pNew->data = rand()%9+1;;
		pNew->id = i+1;
		if(i == 0)
		{
			pHead = pNew;
			pEnd = pHead;
			pHead->next = pHead;
			pHead->pre = pHead;
		}
		else
		{
			pNew->next = pHead;
			pHead->pre = pNew;
			pNew->pre = pEnd;
			pEnd->next = pNew;
			pEnd = pNew;
		}
	}
	return pHead;
}

/**
  约瑟夫环算法实现函数
  参数:p 指向头指针的指针; m 密码 ;type 决定顺时针转还是逆时针转
  思路:递归实现，每次删除被点到的节点并输出，直到链表中只剩最后一个节点 
*/ 
void Solve(LinkList *p,int m,int type,int site)
{
	for(int i = 1; i < site; i++)
	{
		(*p) = (*p)->next;
	}
	if(type == 1)
	{
		if((*p)->next == *p)
		{
			printf("第%d个人(密码%d)最后一个挂\n",(*p)->id,(*p)->data);
			return;
		}
		LinkList head = *p;
		LinkList temp = head;
		LinkList pre,aft;
		for(int i = 1; i < m; i++)
		{
			temp = temp->next;
		}
		int data = temp->data;
		pre = temp->pre;
		aft = temp->next;
		aft->pre = pre;
		pre->next = aft;
		printf("第%d个人(密码%d)挂了\n",temp->id,data);
		free(temp);
		Solve(&aft,data,1,1);
	}
	else
	{
		if((*p)->pre == *p)
		{
			printf("第%d个人(密码%d)最后一个挂\n",(*p)->id,(*p)->data);
			return;
		}
		LinkList head = *p;
		LinkList temp = head;
		LinkList pre,aft;
		for(int i = 1; i < m; i++)
		{
			temp = temp->pre;
		}
		int data = temp->data; 
		pre = temp->pre;
		aft = temp->next;
		aft->pre = pre;
		pre->next = aft;
		printf("第%d个人(密码%d)挂了\n",temp->id,data);
		free(temp);
		Solve(&pre,data,2,1);
	}
}

/**
  遍历双向循环链表 
*/
void Print(LinkList head,int type)
{
	LinkList temp = head;
	printf("-----遍历双向循环链表-----\n");
	printf("---ID---     ---PWD---\n");
	if(type == 1)
	{
		while(temp->next != head)
		{
			printf("   %d            %d   \n",temp->id,temp->data);
			temp = temp->next;
		}
		printf("   %d            %d   \n",temp->id,temp->data);
	}
	else
	{
		while(temp->pre != head)
		{
			printf("   %d            %d   \n",temp->id,temp->data);
			temp = temp->pre;
		}
		printf("   %d            %d   \n",temp->id,temp->data);
	}
}

int main()
{
	LinkList pHead;
	int m;
	int n;
	printf("请输入人数:");
	scanf("%d",&n);//总人数 
	pHead = Create(n);
	Print(pHead,1);
	printf("请输入初始密码:");
	scanf("%d",&m);//初始报数的密码 
	srand(time(NULL));
	int fir = rand()%n+1;//随机生成从第几个人开始报数 
	printf("从%d开始报数\n",fir);
	
	printf("顺时针还是逆时针?1-顺时针.2-逆时针\n");
	int choice;
	scanf("%d",&choice);//选择顺时针报数还是逆时针报数 
	Solve(&pHead,m,choice,fir);
	return 0;
}

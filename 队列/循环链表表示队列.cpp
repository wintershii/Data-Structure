#include<stdio.h>
#include<stdlib.h>

typedef struct Node{//循环链表的数据结构声明 
	int data;
	struct Node* next;
}Node,*List;

typedef struct Que{
	List qHead;
	List rear;
}Que,*Queue;

void Init(Queue *que)//初始化函数 
{
	(*que)->qHead = (List)malloc(sizeof(Node));//申请头节点内存空间 
	List qHead = (*que)->qHead;
	qHead->next = qHead;
	(*que)->rear = qHead;//队尾的指针初始化时指向头节点 
}

void Enque(Queue *que,List node)//入队函数 
{
	List qRear = (*que)->rear;//队尾指针 
	List qHead = (*que)->qHead;//头节点指针 
	qRear->next = node;//将队尾指针指向入队的节点 
	node->next = qHead->next;//入队节点指向头节点指向的第一个节点(循环)
	(*que)->rear = node;//设入队的节点为队尾 
	int data = node->data;
	printf("%d元素入队成功！\n",data);
}

void Deque(Queue *que)//出队函数 
{
	List qRear = (*que)->rear;//队尾指针 
	List qHead = (*que)->qHead;//头节点指针 
	
	if(qHead == qRear)//队为空 
	{
		printf("队为空！\n");
		return;
	}
	if(qHead->next == qRear)//队内只有一个元素 
	{
		int data = qRear->data;
		free(qRear);
		qHead->next = qHead;
		(*que)->rear = qHead;
		printf("%d元素出队成功！\n",data);
		return;
	}
	List first = qHead->next;//让头节点连接的第一个节点出队 
	int data = first->data;
	qRear->next = first->next;
	qHead->next = first->next;
	free(first);
	printf("%d元素出队成功！\n",data);
}

void Print(Queue que)//从队首到队尾依次输出队内元素 
{
	if(que->qHead->next == que->qHead)
	{
		printf("目前是空队\n");
		return; 
	}
	List qHead = que->qHead;
	printf("队内元素依次为：");
	List temp = qHead->next;
	printf("%d  ",temp->data);
	temp = temp->next;
	while(temp != qHead->next)
	{
		printf("%d  ",temp->data);
		temp = temp->next;
	}
	printf("\n");
}

int main()
{
	
	Queue que = (Queue)malloc(sizeof(Que));
	Init(&que);
	int choice = -1;
	while(choice != 0)
	{
		printf("1.入队");
		printf("2.出队");
		printf("0.退出");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
			{
				printf("请输入入队元素:");
				int data;
				scanf("%d",&data);//输入新节点内的元素值 
				List node = (List)malloc(sizeof(Node));
				node->data = data;
				Enque(&que,node);//节点入队 
				break;
			}
			case 2:
				Deque(&que);//出队 
				break;
			case 0:
				break;
		}
		Print(que);//打印 
	}
	return 0;
}

#include<stdio.h>
#include<stdlib.h>

typedef struct Node{//ѭ����������ݽṹ���� 
	int data;
	struct Node* next;
}Node,*List;

typedef struct Que{
	List qHead;
	List rear;
}Que,*Queue;

void Init(Queue *que)//��ʼ������ 
{
	(*que)->qHead = (List)malloc(sizeof(Node));//����ͷ�ڵ��ڴ�ռ� 
	List qHead = (*que)->qHead;
	qHead->next = qHead;
	(*que)->rear = qHead;//��β��ָ���ʼ��ʱָ��ͷ�ڵ� 
}

void Enque(Queue *que,List node)//��Ӻ��� 
{
	List qRear = (*que)->rear;//��βָ�� 
	List qHead = (*que)->qHead;//ͷ�ڵ�ָ�� 
	qRear->next = node;//����βָ��ָ����ӵĽڵ� 
	node->next = qHead->next;//��ӽڵ�ָ��ͷ�ڵ�ָ��ĵ�һ���ڵ�(ѭ��)
	(*que)->rear = node;//����ӵĽڵ�Ϊ��β 
	int data = node->data;
	printf("%dԪ����ӳɹ���\n",data);
}

void Deque(Queue *que)//���Ӻ��� 
{
	List qRear = (*que)->rear;//��βָ�� 
	List qHead = (*que)->qHead;//ͷ�ڵ�ָ�� 
	
	if(qHead == qRear)//��Ϊ�� 
	{
		printf("��Ϊ�գ�\n");
		return;
	}
	if(qHead->next == qRear)//����ֻ��һ��Ԫ�� 
	{
		int data = qRear->data;
		free(qRear);
		qHead->next = qHead;
		(*que)->rear = qHead;
		printf("%dԪ�س��ӳɹ���\n",data);
		return;
	}
	List first = qHead->next;//��ͷ�ڵ����ӵĵ�һ���ڵ���� 
	int data = first->data;
	qRear->next = first->next;
	qHead->next = first->next;
	free(first);
	printf("%dԪ�س��ӳɹ���\n",data);
}

void Print(Queue que)//�Ӷ��׵���β�����������Ԫ�� 
{
	if(que->qHead->next == que->qHead)
	{
		printf("Ŀǰ�ǿն�\n");
		return; 
	}
	List qHead = que->qHead;
	printf("����Ԫ������Ϊ��");
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
		printf("1.���");
		printf("2.����");
		printf("0.�˳�");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
			{
				printf("���������Ԫ��:");
				int data;
				scanf("%d",&data);//�����½ڵ��ڵ�Ԫ��ֵ 
				List node = (List)malloc(sizeof(Node));
				node->data = data;
				Enque(&que,node);//�ڵ���� 
				break;
			}
			case 2:
				Deque(&que);//���� 
				break;
			case 0:
				break;
		}
		Print(que);//��ӡ 
	}
	return 0;
}

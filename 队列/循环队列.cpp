#include<stdio.h>
#include<stdlib.h>
#define MAX 20

typedef struct{
	int date[MAX];
	int front;
	int rear;
}SqQueue;

SqQueue *InitQueue(SqQueue *queue){
	queue = (SqQueue *)malloc(sizeof(SqQueue));
	queue->front = 0;
	queue->rear = 0;
	return queue;
}

void Enqueue(SqQueue *queue){
	if((queue->rear+1) % MAX == queue->front){
		printf("����������\n");
		return;
	}
	printf("������������ݣ�");
	scanf("%d",&queue->date[queue->rear]);
	queue->rear = (queue->rear+1) % MAX;
	printf("��ӳɹ���\n");
}

void Dequeue(SqQueue *queue){
	if(queue->front == queue->rear){
		printf("����Ϊ�գ�\n");
		return;
	}
	printf("��Ҫɾ��������Ԫ��Ϊ��%d",queue->date[queue->front]);
	queue->front = (queue->front+1) % MAX;
	printf("���ӳɹ���\n");
}

void print_queue(SqQueue *queue){
	if(queue->front == queue->rear){
		printf("Ŀǰ����Ϊ�գ�\n");
		return;
	}
	printf("Ŀǰ��������%d������Ԫ��\n",(queue->rear-queue->front+MAX)%MAX);
	if(queue->front < queue->rear){
		int index = 1;
		for(int i = queue->front; i <queue->rear; i++){
			printf("��%d������Ϊ��",index++);
			printf("%d\n",queue->date[i]);
		}
	}
	else if(queue->front > queue->rear){
		int index = 1;
		int i;
		for(i = queue->front; i < MAX; i++){
			printf("��%d������Ϊ��",index++);
			printf("%d\n",queue->date[i]);
		}
		for(i = 0; i < queue->rear; i++){
			printf("��%d������Ϊ��",index++);
			printf("%d\n",queue->date[i]);
		}
	}
}

int main(){
	SqQueue *queue;
	queue = InitQueue(queue);
	int choice;
	while(1){
		printf("1.���\n");
		printf("2.����\n");
		printf("3.���\n");
		scanf("%d",&choice);
		switch(choice){
			case 1:Enqueue(queue);
				break;
			case 2:Dequeue(queue);
				break;
			case 3:print_queue(queue);
				break;
		}
	}
	return 0;
}


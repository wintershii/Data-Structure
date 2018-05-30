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
		printf("队列已满！\n");
		return;
	}
	printf("请输入入队数据：");
	scanf("%d",&queue->date[queue->rear]);
	queue->rear = (queue->rear+1) % MAX;
	printf("入队成功！\n");
}

void Dequeue(SqQueue *queue){
	if(queue->front == queue->rear){
		printf("队列为空！\n");
		return;
	}
	printf("你要删除的数据元素为：%d",queue->date[queue->front]);
	queue->front = (queue->front+1) % MAX;
	printf("出队成功！\n");
}

void print_queue(SqQueue *queue){
	if(queue->front == queue->rear){
		printf("目前队列为空！\n");
		return;
	}
	printf("目前队列中有%d个数据元素\n",(queue->rear-queue->front+MAX)%MAX);
	if(queue->front < queue->rear){
		int index = 1;
		for(int i = queue->front; i <queue->rear; i++){
			printf("第%d个数据为：",index++);
			printf("%d\n",queue->date[i]);
		}
	}
	else if(queue->front > queue->rear){
		int index = 1;
		int i;
		for(i = queue->front; i < MAX; i++){
			printf("第%d个数据为：",index++);
			printf("%d\n",queue->date[i]);
		}
		for(i = 0; i < queue->rear; i++){
			printf("第%d个数据为：",index++);
			printf("%d\n",queue->date[i]);
		}
	}
}

int main(){
	SqQueue *queue;
	queue = InitQueue(queue);
	int choice;
	while(1){
		printf("1.入队\n");
		printf("2.出队\n");
		printf("3.输出\n");
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


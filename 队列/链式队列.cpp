#include<stdio.h>
#include<stdlib.h>

typedef struct Qnode{
	int date;
	struct Qnode *next;
}Qnode,*ptr;

typedef struct{
	ptr front;
	ptr rear;
	int count;
}linkqueue;

linkqueue *Initqueue(linkqueue *queue){
	queue = (linkqueue *)malloc(sizeof(linkqueue));
	ptr pHead = (ptr)malloc(sizeof(Qnode));
	pHead->next = NULL;
	queue->front = pHead;
	queue->rear = pHead;
	queue->count = 0;
	return queue;
}

void Enqueue(linkqueue *queue){
	ptr pnew = (ptr)malloc(sizeof(Qnode));
	printf("������������ݣ�");
	scanf("%d",&pnew->date);
	pnew->next = NULL;
	queue->rear->next = pnew;
	queue->rear = pnew;
	queue->count++;
	printf("��ӳɹ���\n");
}

void Dequeue(linkqueue *queue){
	if(queue->front == queue->rear){
		printf("����ĿǰΪ�գ�\n");
		return;
	}
	ptr temp = queue->front->next;
	printf("��Ҫɾ��������Ϊ��%d",temp->date);
	queue->front->next = temp->next;
	if(queue->rear == temp)
		queue->rear = queue->front;
	free(temp);
	queue->count--;
	printf("���ӳɹ���\n");
}

void print_queue(linkqueue *queue){
	if(queue->front == queue->rear){
		printf("ĿǰΪ�ն��У�\n");
		return;
	}
	printf("Ŀǰ�����й���%d������\n",queue->count);
	int index = 1;
	ptr temp = queue->front->next;
	while(temp != NULL){
		printf("��%d�����ݣ�",index++);
		printf("%d\n",temp->date);
		temp = temp->next;
	}
}

int main(){
	linkqueue *queue;
	queue = Initqueue(queue);
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


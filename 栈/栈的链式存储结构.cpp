#include<stdio.h>
#include<stdlib.h>

typedef struct STACKNODE{			//ջ�ṹ�ĵ����� 
	int date;
	struct STACKNODE *next;
}stacknode,*linkstack;

typedef struct LinkStack{			//ջ�ṹ 
	linkstack top;
	int count;
}link;

link *Initstack(link *stack){						//��ʼ��ջ����ջ��ָ�븳ֵNULL 
	stack = (link *)malloc(sizeof(struct LinkStack));
	stack->count = 0;
	stack->top = NULL;
	return stack;
}

void push(link *stack){
	linkstack pnew = (linkstack)malloc(sizeof(stacknode));
	printf("������ѹջ���ݣ�");
	scanf("%d",&pnew->date);
	pnew->next = stack->top;
	stack->top = pnew;
	stack->count++;
	printf("ѹջ�ɹ���\n");
}

void pop(link *stack){
	linkstack temp;
	if(stack->top == NULL){
		printf("ĿǰΪ��ջ��\n");
		return;
	}
	printf("��Ҫ��ջ������Ϊ��%d",stack->top->date);
	temp = stack->top;
	stack->top = stack->top->next;
	free(temp);
	stack->count--;
	printf("��ջ�ɹ���\n");
}

void print_stack(link *stack){
	linkstack temp;
	if(stack->top == NULL){
		printf("ĿǰΪ��ջ��\n");
		return;
	}
	temp = stack->top;
	int index = 1;
	while(temp != NULL){
		printf("��%d������:",index++);
		printf("%d\n",temp->date);
		temp = temp->next;
	}
}

int main(){
	link *stack;
	stack = Initstack(stack);
		int choice = -1;
	while(choice != 0){
		printf("1. ѹջ\n");
		printf("2. ��ջ\n");
		printf("3. ���\n");
		scanf("%d",&choice);
		switch(choice){
			case 1: push(stack);
				break;
			case 2: pop(stack);
				break;
			case 3: print_stack(stack);
				break;
		}
	}
}

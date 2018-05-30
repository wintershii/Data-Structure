#include<stdio.h>
#include<stdlib.h>
#define MAX 20

typedef struct{
	int date[MAX];
	int top;
}SqStack;

SqStack *InitStack(SqStack *stack){					//��ʼ��ջ�������ڴ�ռ䣬����top��-1 
	stack = (SqStack *)malloc(sizeof(SqStack));           
	stack->top = -1;
	printf("��ʼ���ɹ���\n");
	return stack;
}     

void push(SqStack *stack){
	int index = stack->top+1;			
	if(index == MAX-1){						//��ջ���� 
		printf("Ŀǰջ����\n");
		return;
	}
	printf("������Ҫѹջ�����ݣ�");
	scanf("%d",&stack->date[index]);
	stack->top++;						//ѹջ�ɹ���ջ����Ǽ�һ 
	printf("ѹջ�ɹ���\n");
}

void pop(SqStack *stack){
	printf("%d\n",stack->top);
	int index = stack->top;
	if(index == -1){					//��ջ���� 
		printf("ĿǰΪ��ջ!\n");
		return;
	}
	printf("Ҫ��ջ������Ϊ��%d ",stack->date[index]);
	stack->top--;					//��ջ�ɹ���ջ����Ǽ�һ 
	printf("��ջ�ɹ���\n");
}

void print_stack(SqStack *stack){			//����ջ������ 
	printf("%d\n",stack->top);
	int index = stack->top;
	if(index == -1 ){
		printf("ĿǰΪ��ջ!\n");
		return;
	}
	for(int i = 0; i <= index; i++){
		printf("��%d������Ϊ��",i+1);
		printf("%d\n",stack->date[i]);
	}
}

int main(){
	SqStack *stack;
	stack = InitStack(stack);
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
	return 0;
} 

#include<stdio.h>
#include<stdlib.h>
#define MAX 20

typedef struct{
	int date[MAX];
	int top1;
	int top2;
}doublestack;

doublestack *Initstack(doublestack *stack){					//��ʼ����ջ���� 
	stack = (doublestack *)malloc(sizeof(doublestack));		//��top1 = -1��top2 = MAX 
	stack->top1 = -1;
	stack->top2 = MAX;
	return stack;
}

void push(doublestack *stack){					//ѡ��ѹ1ջ��2ջ 
	int index;
	while(1){
		if(stack->top1 + 1 == stack->top2){
			printf("Ŀǰջ�����޷�����ѹջ\n");
			return;
		} 
		int choice;
		printf("��ѡ��ѹ1ջ��ѹ2ջ��\n");
		scanf("%d",&choice);
		if(choice == 1){
			index = ++stack->top1;
			printf("����ѹ1ջ�����ݣ�");
			scanf("%d",&stack->date[index]);
			printf("ѹջ�ɹ���\n");
			return;
		}
		else if(choice == 2){
			index = --stack->top2;
			printf("������ѹ2ջ�����ݣ�");
			scanf("%d",&stack->date[index]);
			printf("ѹջ�ɹ���\n");
			return;
		}
		else{
			printf("�������");
			continue;
		}
	}
}

void pop(doublestack *stack){
	int index;
	while(1){
		int choice;
		printf("��ѡ��1ջ��2ջ��\n");
		scanf("%d",&choice);
		if(choice == 1){
			index = stack->top1;
			if(index == -1){
				printf("1ջΪ��ջ��\n");
				continue;
			}
			printf("Ҫ��ջ������Ϊ��%d",stack->date[index]);
			stack->top1--;
			printf("��ջ�ɹ���\n");
			return;
		}
		else if(choice == 2){
			index = stack->top2;
			if(index == MAX){
				printf("2ջΪ��ջ��\n");
				continue;
			}
			printf("Ҫ��ջ������Ϊ��%d",stack->date[index]);
			stack->top2++;
			printf("��ջ�ɹ���\n");
			return;
		}
		else{
			printf("��������\n");
			continue;
		}
		
	}
}

void print_stack(doublestack *stack){
	int index;
	index = stack->top1;
	if(index == -1)
		printf("1ջΪ��ջ��\n");
	else{
		printf("1ջ��\n");
		for(int i = 0; i <= index; i++){
			printf("��%d������Ϊ��",i+1);
			printf("%d\n",stack->date[i]);
		}
	}
	index = stack->top2;
	if(index == MAX)
		printf("2ջΪ��ջ��\n");
	else{
		printf("2ջ��\n");
		for(int i = MAX-1; i >= index; i--){
			printf("��%d������Ϊ��",MAX-i);
			printf("%d\n",stack->date[i]);
		}
	}
	return;
}

int main(){
	doublestack *stack;
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
	return 0;
}

#include<stdio.h>
#include<stdlib.h>
#define MAX 20

typedef struct{
	int date[MAX];
	int top1;
	int top2;
}doublestack;

doublestack *Initstack(doublestack *stack){					//初始化两栈数组 
	stack = (doublestack *)malloc(sizeof(doublestack));		//令top1 = -1，top2 = MAX 
	stack->top1 = -1;
	stack->top2 = MAX;
	return stack;
}

void push(doublestack *stack){					//选择压1栈或2栈 
	int index;
	while(1){
		if(stack->top1 + 1 == stack->top2){
			printf("目前栈满！无法继续压栈\n");
			return;
		} 
		int choice;
		printf("请选择压1栈或压2栈？\n");
		scanf("%d",&choice);
		if(choice == 1){
			index = ++stack->top1;
			printf("输入压1栈的数据：");
			scanf("%d",&stack->date[index]);
			printf("压栈成功！\n");
			return;
		}
		else if(choice == 2){
			index = --stack->top2;
			printf("请输入压2栈的数据：");
			scanf("%d",&stack->date[index]);
			printf("压栈成功！\n");
			return;
		}
		else{
			printf("输入错误！");
			continue;
		}
	}
}

void pop(doublestack *stack){
	int index;
	while(1){
		int choice;
		printf("请选择弹1栈或弹2栈？\n");
		scanf("%d",&choice);
		if(choice == 1){
			index = stack->top1;
			if(index == -1){
				printf("1栈为空栈！\n");
				continue;
			}
			printf("要弹栈的数据为：%d",stack->date[index]);
			stack->top1--;
			printf("弹栈成功！\n");
			return;
		}
		else if(choice == 2){
			index = stack->top2;
			if(index == MAX){
				printf("2栈为空栈！\n");
				continue;
			}
			printf("要弹栈的数据为：%d",stack->date[index]);
			stack->top2++;
			printf("弹栈成功！\n");
			return;
		}
		else{
			printf("输入有误！\n");
			continue;
		}
		
	}
}

void print_stack(doublestack *stack){
	int index;
	index = stack->top1;
	if(index == -1)
		printf("1栈为空栈！\n");
	else{
		printf("1栈：\n");
		for(int i = 0; i <= index; i++){
			printf("第%d个数据为：",i+1);
			printf("%d\n",stack->date[i]);
		}
	}
	index = stack->top2;
	if(index == MAX)
		printf("2栈为空栈！\n");
	else{
		printf("2栈：\n");
		for(int i = MAX-1; i >= index; i--){
			printf("第%d个数据为：",MAX-i);
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
		printf("1. 压栈\n");
		printf("2. 弹栈\n");
		printf("3. 输出\n");
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

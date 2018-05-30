#include<stdio.h>
#include<stdlib.h>

typedef struct STACKNODE{			//栈结构的单链表 
	int date;
	struct STACKNODE *next;
}stacknode,*linkstack;

typedef struct LinkStack{			//栈结构 
	linkstack top;
	int count;
}link;

link *Initstack(link *stack){						//初始化栈，给栈顶指针赋值NULL 
	stack = (link *)malloc(sizeof(struct LinkStack));
	stack->count = 0;
	stack->top = NULL;
	return stack;
}

void push(link *stack){
	linkstack pnew = (linkstack)malloc(sizeof(stacknode));
	printf("请输入压栈数据：");
	scanf("%d",&pnew->date);
	pnew->next = stack->top;
	stack->top = pnew;
	stack->count++;
	printf("压栈成功！\n");
}

void pop(link *stack){
	linkstack temp;
	if(stack->top == NULL){
		printf("目前为空栈！\n");
		return;
	}
	printf("你要弹栈的数据为：%d",stack->top->date);
	temp = stack->top;
	stack->top = stack->top->next;
	free(temp);
	stack->count--;
	printf("弹栈成功！\n");
}

void print_stack(link *stack){
	linkstack temp;
	if(stack->top == NULL){
		printf("目前为空栈！\n");
		return;
	}
	temp = stack->top;
	int index = 1;
	while(temp != NULL){
		printf("第%d个数据:",index++);
		printf("%d\n",temp->date);
		temp = temp->next;
	}
}

int main(){
	link *stack;
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
}

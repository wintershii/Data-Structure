#include<stdio.h>
#define MAX 1000

typedef struct{
	int date;
	int cur;
}node,list[MAX];												             	 //静态链表 

void InitList(list space){
	for(int i = 0; i < MAX-1; i++)
		space[i].cur = i+1;
	space[MAX-1].cur = 0;
}

void creat(list space){
	int index;
	int i; 
	printf("请输入数据元素个数：");
	scanf("%d",&index);
	for(i = 1; i <= index; i++)
		scanf("%d",&space[i].date);
	space[i-1].cur = 0;
	space[0].cur = index+1;
	space[MAX-1].cur = 1;
}

void print_list(list space){
	int index = 0;
	int end = MAX-1;
	while(space[end].cur != 0){
		end = space[end].cur;
		printf("第%d个数据元素：",++index);
		printf("%d\n",space[end].date);
	}
}

int malloc_node(list space){
	int i = space[0].cur;
	if(space[0].cur)
		space[0].cur = space[i].cur;
		
	return i;
}

void insert(list space){
	int site;
	int elem;
	int pre = MAX-1;
	int obj = malloc_node(space);
	printf("请输入要插入的位置：");
	scanf("%d",&site);
	printf("请输入要插入的数据：");
	scanf("%d",&elem);
	if(obj){
		space[obj].date = elem;
		for(int i = 1; i <= site-1; i++)
			pre = space[pre].cur;
		space[obj].cur = space[pre].cur;
		space[pre].cur = obj;
	}
	printf("插入成功！\n");
}

void free_node(list space,int k){
	space[k].cur = space[0].cur;
	space[0].cur = k;
}

void delete_node(list space){
	int site;
	int pre = MAX-1;
	printf("请输入要删除的位置：");
	scanf("%d",&site);
	for(int i = 1; i <= site-1; i++)
		pre = space[pre].cur;
	int now = space[pre].cur;
	space[pre].cur = space[now].cur;
	free_node(space,now);
	printf("删除成功！\n");
}

int main(){
	list space;
	InitList(space);
	creat(space);
	print_list(space);
	insert(space);
	print_list(space);
	delete_node(space);
	print_list(space);
	return 0;
}


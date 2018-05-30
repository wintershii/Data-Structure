#include<stdio.h>
#define MAX 1000

typedef struct{
	int date;
	int cur;
}node,list[MAX];												             	 //��̬���� 

void InitList(list space){
	for(int i = 0; i < MAX-1; i++)
		space[i].cur = i+1;
	space[MAX-1].cur = 0;
}

void creat(list space){
	int index;
	int i; 
	printf("����������Ԫ�ظ�����");
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
		printf("��%d������Ԫ�أ�",++index);
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
	printf("������Ҫ�����λ�ã�");
	scanf("%d",&site);
	printf("������Ҫ��������ݣ�");
	scanf("%d",&elem);
	if(obj){
		space[obj].date = elem;
		for(int i = 1; i <= site-1; i++)
			pre = space[pre].cur;
		space[obj].cur = space[pre].cur;
		space[pre].cur = obj;
	}
	printf("����ɹ���\n");
}

void free_node(list space,int k){
	space[k].cur = space[0].cur;
	space[0].cur = k;
}

void delete_node(list space){
	int site;
	int pre = MAX-1;
	printf("������Ҫɾ����λ�ã�");
	scanf("%d",&site);
	for(int i = 1; i <= site-1; i++)
		pre = space[pre].cur;
	int now = space[pre].cur;
	space[pre].cur = space[now].cur;
	free_node(space,now);
	printf("ɾ���ɹ���\n");
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


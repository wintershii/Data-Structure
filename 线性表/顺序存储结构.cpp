#include<stdio.h>
#define MAX 20

typedef struct {
	int date[MAX];
	int length;
}SqList;

SqList Creat(SqList list){
	printf("请输入数据元素个数：");
	scanf("%d",&list.length);
	for(int i = 0; i < list.length; i++)
		scanf("%d",&list.date[i]);
	return list;
}

void print_list(SqList list){
	for(int i = 0; i < list.length; i++){
		printf("表中第%d个数据元素：",i+1);
		printf("%d\n",list.date[i]);
	}
}

SqList insert(SqList list){
	if(list.length == 0){
		printf("目前为空表！");
		return list;
	}
	int site;
	int elem;
	printf("请输入要插入的位置：");
	scanf("%d",&site);
	if(site < 1 || site > list.length){
		printf("位置输入有误！");
		return list;
	}
	printf("要插入的数据：");
	scanf("%d",&elem);
	for(int i = list.length-1; i >= site-1; i--)
		list.date[i+1] = list.date[i];
	list.date[site-1] = elem;
	list.length++;
	printf("插入成功！");
	return list;
}

SqList delete_elem(SqList list){
	if(list.length == 0){
		printf("目前为空表！");
		return list;
	}
	int site;
	printf("请输入要删除的位置：");
	scanf("%d",&site);
	if(site < 1 || site > list.length){
		printf("位置输入有误！");
		return list;
	}
	for(int i = site-1; i < list.length; i++)
		list.date[i] = list.date[i+1];
	list.length--;
	return list;
}

int main(){
	SqList list;
	list = Creat(list);
	print_list(list);
	list = insert(list);
	print_list(list);
	list = delete_elem(list);
	print_list(list);
	return 0;
} 


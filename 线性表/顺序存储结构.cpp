#include<stdio.h>
#define MAX 20

typedef struct {
	int date[MAX];
	int length;
}SqList;

SqList Creat(SqList list){
	printf("����������Ԫ�ظ�����");
	scanf("%d",&list.length);
	for(int i = 0; i < list.length; i++)
		scanf("%d",&list.date[i]);
	return list;
}

void print_list(SqList list){
	for(int i = 0; i < list.length; i++){
		printf("���е�%d������Ԫ�أ�",i+1);
		printf("%d\n",list.date[i]);
	}
}

SqList insert(SqList list){
	if(list.length == 0){
		printf("ĿǰΪ�ձ�");
		return list;
	}
	int site;
	int elem;
	printf("������Ҫ�����λ�ã�");
	scanf("%d",&site);
	if(site < 1 || site > list.length){
		printf("λ����������");
		return list;
	}
	printf("Ҫ��������ݣ�");
	scanf("%d",&elem);
	for(int i = list.length-1; i >= site-1; i--)
		list.date[i+1] = list.date[i];
	list.date[site-1] = elem;
	list.length++;
	printf("����ɹ���");
	return list;
}

SqList delete_elem(SqList list){
	if(list.length == 0){
		printf("ĿǰΪ�ձ�");
		return list;
	}
	int site;
	printf("������Ҫɾ����λ�ã�");
	scanf("%d",&site);
	if(site < 1 || site > list.length){
		printf("λ����������");
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


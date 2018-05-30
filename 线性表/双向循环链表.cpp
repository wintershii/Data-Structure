#include<stdio.h>
#include<stdlib.h>

struct NODE{
	int date;
	struct NODE *prior;
	struct NODE *next;
};
typedef struct NODE *node;
int count = 0;
 
node Creat(node pHead){
	int index;
	node pNew = NULL,pEnd = NULL;
	pHead = (node)malloc(sizeof(struct NODE));
	pHead->next = pHead;
	pHead->prior = pHead;
	pEnd = pHead;
	printf("请输入数据元素个数：");
	scanf("%d",&index);
	for(int i = 0; i < index; i++){
		count++;
		pNew = (node)malloc(sizeof(struct NODE));
		scanf("%d",&pNew->date);
		pNew->next = pHead;
		pHead->prior = pNew;
		pEnd->next = pNew;
		pNew->prior = pEnd;
		pEnd = pNew;
	}
	return pHead;
}

void print_list(node pHead){
	int choice;
	int index = 0;
	node pRear,pTemp;
	pRear = pHead->prior;
	pTemp = pHead->next;
	printf("请选择1.正序输出  或  2.倒序输出\n");
	scanf("%d",&choice);
	if(choice == 1){
		while(pTemp != pHead){
			printf("第%d个数据元素：",++index);
			printf("%d\n",pTemp->date);
			pTemp = pTemp->next;
		}
	}
	else if(choice == 2){
		while(pRear != pHead){
			printf("第%d个数据元素：",count-index++);
			printf("%d\n",pRear->date);
			pRear = pRear->prior;
		}
	}
}

node insert(node pHead){
	int site;
	node pNew,pTemp,pPre;
	pTemp = pHead->next;
	printf("请输入要插入的位置：");
	scanf("%d",&site);
	for(int i = 1; i < site; i++)
		pTemp = pTemp->next;
	pNew = (node)malloc(sizeof(struct NODE));
	printf("请输入要插入的数据：");
	scanf("%d",&pNew->date);
	pPre = pTemp->prior;
	pNew->prior = pPre;
	pNew->next = pTemp;
	pTemp->prior = pNew;
	pPre->next = pNew;
	count++;
	printf("插入成功！\n");
	return pHead;
}

node delete_node(node pHead){
	int site;
	node pTemp,pPre;
	pTemp = pHead->next;
	printf("请输入要删除的位置：");
	scanf("%d",&site);
	for(int i =1; i < site;i++)
		pTemp = pTemp->next;
	pPre = pTemp->prior;
	pPre->next = pTemp->next;
	pTemp->next->prior = pPre;
	free(pTemp);
	printf("删除成功！\n");
	return pHead;
}

int main(){
	node pHead = NULL;
	pHead = Creat(pHead);	
	print_list(pHead);
	pHead = insert(pHead);
	print_list(pHead);
	delete_node(pHead);
	print_list(pHead);
	return 0;
}

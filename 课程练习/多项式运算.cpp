#include<stdio.h>
#include<stdlib.h>
#include<math.h>

typedef struct node{
	float coef;
	int expn;
	struct node *next;
}Node,*LinkList;

LinkList Create()
{
	LinkList pHead = (LinkList)malloc(sizeof(Node));
	pHead->next = NULL;
	LinkList pNew = NULL,pEnd = pHead;
	pNew = (LinkList)malloc(sizeof(Node));
	scanf("%f,%d",&pNew->coef,&pNew->expn);
	while(pNew->coef != 0)
	{
		pNew->next = NULL;
		pEnd->next = pNew;
		pEnd = pNew;
		pNew = (LinkList)malloc(sizeof(Node));
		scanf("%f,%d",&pNew->coef,&pNew->expn);
	}
	return pHead;
}

void Print(LinkList head)
{
	LinkList temp = head->next;
	while(temp->next != NULL)
	{
		if(temp->coef == 0.00)
		{
			temp = temp->next;
			continue;
		}
		printf("%.2f",temp->coef);
		if(temp->expn == 0)
		{
			if(temp->next->coef >= 0)
				printf("+");
			else
				printf("");
		}
		else if(temp->expn == 1)
		{
			if(temp->next->coef >= 0)
				printf("X+");
			else
				printf("X");
		}
		else
		{
			if(temp->next->coef >= 0)
				printf("X^%d+",temp->expn);
			else
				printf("X^%d",temp->expn);
		}
		temp = temp->next;
	}
	printf("%.2f",temp->coef);
	if(temp->expn == 1)
	{
		printf("X");
	}
	else
	{
		printf("X^%d",temp->expn);
	}
	printf("\n");
}

LinkList Add(LinkList la,LinkList lb)
{
	LinkList qa = la->next;
	LinkList qb = lb->next;
	LinkList cHead = (LinkList)malloc(sizeof(Node));
	LinkList qc = cHead;
	while(qa != NULL && qb != NULL)
	{
		if(qa->expn < qb->expn)
		{
			LinkList pNew = (LinkList)malloc(sizeof(Node));
			pNew->coef = qa->coef;
			pNew->expn = qa->expn;
			qc->next = pNew;
			qc = qc->next;
			qa = qa->next;
		}
		else if(qa->expn == qb->expn)
		{
			LinkList pNew = (LinkList)malloc(sizeof(Node));
			pNew->coef = qa->coef + qb->coef;
			pNew->expn = qa->expn;
			qc->next = pNew;
			qc = qc->next;
			qa = qa->next;
			qb = qb->next;
		}
		else
		{
			LinkList pNew = (LinkList)malloc(sizeof(Node));
			pNew->coef = qb->coef;
			pNew->expn = qb->expn;
			qc->next = pNew;
			qc = qc->next;
			qb = qb->next;
		}
	}
	if(qa == NULL)
	{
		qc->next = qb;
	}
	if(qb == NULL)
	{
		qc->next = qa;
	}
	return cHead;
}

LinkList Sub(LinkList la,LinkList lb)
{
	LinkList qa = la->next;
	LinkList qb = lb->next;
	LinkList dHead = (LinkList)malloc(sizeof(Node));
	LinkList qd = dHead;
	while(qa != NULL && qb != NULL)
	{
		if(qa->expn < qb->expn)
		{
			LinkList pNew = (LinkList)malloc(sizeof(Node));
			pNew->coef = qa->coef;
			pNew->expn = qa->expn;
			qd->next = pNew;
			qd = qd->next;
			qa = qa->next;
		}
		else if(qa->expn == qb->expn)
		{
			LinkList pNew = (LinkList)malloc(sizeof(Node));
			pNew->coef = qa->coef - qb->coef;
			pNew->expn = qa->expn;
			qd->next = pNew;
			qd = qd->next;
			qa = qa->next;
			qb = qb->next;
		}
		else
		{
			LinkList pNew = (LinkList)malloc(sizeof(Node));
			pNew->coef = -qb->coef;
			pNew->expn = qb->expn;
			qd->next = pNew;
			qd = qd->next;
			qb = qb->next;
		}
	}
	if(qa == NULL)
	{
		while(qb != NULL)
		{
			LinkList pNew = (LinkList)malloc(sizeof(Node));
			pNew->coef = -qb->coef;
			qd->next = pNew;
			qd = qd->next;
		}
		qd->next = NULL;
	}
	if(qb == NULL)
	{
		qd->next = qa;
	}
	return dHead;
}

void Solve(LinkList head,float x)
{
	float sum = 0;
	LinkList temp = head->next;
	while(temp != NULL)
	{
		sum += temp->coef * pow(x,temp->expn);
		temp = temp->next;
	}
	printf("求得结果为: %.2f\n",sum);
}

LinkList derivative(LinkList head)
{
	LinkList temp = head->next;
	LinkList eHead = (LinkList)malloc(sizeof(Node));
	LinkList le = eHead;
	while(temp != NULL)
	{
		if(temp->expn == 0)
		{
			temp = temp->next;
			continue;
		}
		int p = temp->expn;
		temp->expn--;
		temp->coef *= p;
		le->next = temp;
		le = le->next;
		temp = temp->next;
	}
	return eHead;
}

int main()
{
	LinkList la,lb;
	la = Create();
	lb = Create();
	printf("LA: ");
	Print(la);
	printf("LB: ");
	Print(lb);
	
	printf("LA与LB之和: ");
	LinkList lc = Add(la,lb);
	Print(lc); 
	
	printf("LA与LB之差: ");
	LinkList ld = Sub(la,lb);
	Print(ld);
	
	float x;
	scanf("%f",&x);
	printf("LA");Solve(la,x);
	printf("LB");Solve(lb,x);
	
	printf("LA求导:");
	LinkList e1 = derivative(la);
	Print(e1);
	printf("LB求导:");
	LinkList e2 = derivative(lb);
	Print(e2);
	return 0;
}

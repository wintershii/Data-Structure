#include<stdio.h>
#include<stdlib.h>
#include<math.h>

typedef struct node{//����ʽÿ��Ľڵ�����ݽṹ�������� 
	float coef;
	int expn;
	struct node *next;
}Node,*LinkList;

LinkList Create()//��������ʽ 
{
	LinkList pHead = (LinkList)malloc(sizeof(Node));
	pHead->next = NULL;
	LinkList pNew = NULL,pEnd = pHead;
	pNew = (LinkList)malloc(sizeof(Node));
	scanf("%f,%d",&pNew->coef,&pNew->expn);
	while(pNew->coef != 0)//����0ʱֹͣ¼�� 
	{
		pNew->next = NULL;
		pEnd->next = pNew;
		pEnd = pNew;
		pNew = (LinkList)malloc(sizeof(Node));
		scanf("%f,%d",&pNew->coef,&pNew->expn);
	}
	return pHead;
}

void Print(LinkList head)//�������ʽ 
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
	else if(temp->expn == 0);
	else
	{
		printf("X^%d",temp->expn);
	}
	printf("\n");
}

LinkList Add(LinkList la,LinkList lb)//����ʽ��� 
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

LinkList Sub(LinkList la,LinkList lb)//����ʽ��� 
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
			pNew->expn = qb->expn;
			qd->next = pNew;
			qd = qd->next;
			qb = qb->next;
		}
		qd->next = NULL;
	}
	if(qb == NULL)
	{
		qd->next = qa;
	}
	return dHead;
}

void Solve(LinkList head,float x)//����ʽ��� 
{
	float sum = 0;
	LinkList temp = head->next;
	while(temp != NULL)
	{
		sum += temp->coef * pow(x,temp->expn);
		temp = temp->next;
	}
	printf("��ý��Ϊ: %.2f\n",sum);
}

LinkList derivative(LinkList head)//����ʽ�� 
{
	LinkList temp = head->next;
	LinkList eHead = (LinkList)malloc(sizeof(Node));
	eHead->next = NULL;
	LinkList le = eHead;
	while(temp != NULL)
	{
		if(temp->expn == 0)
		{
			if(temp->next == NULL)
			{
				printf("0\n");
				return eHead;
			}
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

void Mult(LinkList la,LinkList lb)//����ʽ��� 
{
	LinkList qa = la->next;
	LinkList tHead = (LinkList)malloc(sizeof(Node));
	tHead->next = NULL;
	while(qa != NULL)
	{
		LinkList Rp = (LinkList)malloc(sizeof(Node));
		LinkList temp = Rp;
		LinkList qb = lb->next;
		float coef = qa->coef;
		int expn = qa->expn;
		while(qb != NULL)
		{
			LinkList pNew = (LinkList)malloc(sizeof(Node));
			pNew->coef = coef * qb->coef;
			pNew->expn = expn + qb->expn;
			pNew->next = NULL;
			temp->next = pNew;
			temp = temp->next;
			qb = qb->next;
		}
		tHead = Add(tHead,Rp);
		qa = qa->next;
		LinkList t1 = Rp->next;
		LinkList t2 = Rp;
		while(t1 != NULL)
		{
			free(t2);
			t2 = t1;
			t1 = t1->next;
		}
		free(temp);
	}
	printf("LA��LB���:");
	Print(tHead);
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
	
	printf("LA��LB֮��: ");
	LinkList lc = Add(la,lb);
	Print(lc); 
	
	printf("LA��LB֮��: ");
	LinkList ld = Sub(la,lb);
	Print(ld);
	
	Mult(la,lb);
	
	printf("������Ҫ�����X��ֵ:");
	float x;
	scanf("%f",&x);
	printf("LA");Solve(la,x);
	printf("LB");Solve(lb,x);
	
	printf("LA��:");
	LinkList e1 = derivative(la);
	Print(e1);
	printf("LB��:");
	LinkList e2 = derivative(lb);
	Print(e2);
	
	
	return 0;
}

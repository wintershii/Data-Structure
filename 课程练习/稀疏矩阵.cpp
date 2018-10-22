#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 100

typedef struct{
	int row,col;
	int value;
}Triple;

typedef struct{
	Triple data[MAX];
	int rows,cols,nums;
}TSMatrix;

void Init(TSMatrix *tsm,int m,int n,int array[][MAX])
{
	tsm->rows = m;
	tsm->cols = n;
	int nums = 0;
	for(int i = 0; i < m; i++)
	{
		for(int j = 0; j < n; j++)
		{
			if(array[i][j] != 0)
			{
				tsm->data[nums].row = i;
				tsm->data[nums].col = j;
				tsm->data[nums].value = array[i][j];
				nums++;
			}
		}
	}
	tsm->nums = nums;
}

void Print(TSMatrix *tsm)
{
	int n = tsm->nums;
	printf("row  col  value\n");
	for(int i = 0; i < n; i++)
	{
		printf("%d  %d  %d\n",tsm->data[i].row,tsm->data[i].col,tsm->data[i].value);
	}
}

int Comparator(const void *a, const void *b)//设定比较器 
{
	if((*(Triple *)a).row == (*(Triple *)b).row)
	{
		return (*(Triple *)a).col - (*(Triple *)b).col;
	}
	else
	{
		return (*(Triple *)a).row - (*(Triple *)b).row;
	}
}

void Transpose1(TSMatrix *a,TSMatrix *b)//列序递增转置1 
{
	b->rows = a->cols;
	b->cols = a->rows;
	b->nums = a->nums;
	int nums = b->nums;
	if(b->nums > 0)
	{
		for(int i = 0; i < nums; i++)
		{
			b->data[i].row = a->data[i].col;
			b->data[i].col = a->data[i].row;
			b->data[i].value = a->data[i].value;
		}
		qsort(b->data,nums,sizeof(b->data[0]),Comparator);//调用快排函数 
	}
}

void Transpose2(TSMatrix a,TSMatrix *b)//列序递增转置优化 
{
	int i,j,min;
	b->cols = a.rows;
	b->rows = a.cols;
	b->nums = a.nums;
	int nums = a.nums;
	i = 0;
	while(i < nums)
	{
		min = 0;
		for(j = 1; j < nums; j++)
		{
			if(a.data[j].col < a.data[min].col)
			{
				min = j;
			}
		}
		b->data[i].row = a.data[min].col;
		b->data[i].col = a.data[min].row;
		b->data[i].value = a.data[min].value;
		i++;
		a.data[min].col = a.cols + 1;
	}
}

void Transpose3(TSMatrix *a,TSMatrix *b)//一次定位快速转置
{
	int num[MAX],pos[MAX];
	b->cols = a->rows;
	b->rows = a->cols;
	b->nums = a->nums;
	if(b->nums)
	{
		memset(num,0,MAX);
		for(int i = 0; i < a->nums; i++)
		{
			num[a->data[i].col]++;
		}
		pos[0] = 0;
		for(int i = 1; i < a->cols; i++)
		{
			pos[i] = pos[i-1]+num[i-1];
		}
		for(int i = 0; i < a->nums; i++)
		{
			int col = a->data[i].col;
			int q = pos[col];
			b->data[q].row = a->data[i].col;
			b->data[q].col = a->data[i].row;
			b->data[q].value = a->data[i].value;
			pos[col]++;
		}
	}
}

int main()
{
	int array[MAX][MAX];
	int m,n;
	printf("请输入矩阵行列数:");
	scanf("%d %d",&m,&n);
	printf("%d,%d\n",m,n);
	printf("请输入矩阵:\n");
	for(int i = 0; i < m; i++)
	{
		for(int j = 0; j < n; j++)
		{
			scanf("%d",&array[i][j]);
		}
	}
	TSMatrix *tsm = (TSMatrix *)malloc(sizeof(TSMatrix));
	Init(tsm,m,n,array);
	Print(tsm);
	printf("转置后三元组:\n");
	TSMatrix *tsm2 = (TSMatrix *)malloc(sizeof(TSMatrix));
//	Transpose1(tsm,tsm2);
//	Print(tsm2);
//	Transpose2(*tsm,tsm2);
//	Print(tsm2);
	Transpose3(tsm,tsm2);
	Print(tsm2);
	return 0;
}

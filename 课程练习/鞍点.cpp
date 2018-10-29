#include<stdio.h>
#include<string.h>

#define max(a,b) a>b?a:b;
#define min(a,b) a<b?a:b;

void solve(int m,int n)
{
	int array[100][100];
	int row[100],col[100];
	memset(row,-1,sizeof(row));
	memset(col,-1,sizeof(col));
	for(int i = 0; i < m; i++)
	{
		for(int j = 0; j < n; j++)
		{
			scanf("%d",&array[i][j]);
			if(row[i] < 0)  row[i] = array[i][j];
				else row[i] = min(row[i],array[i][j]);
			if(col[j] < 0)  col[j] = array[i][j];
				else col[j] = max(col[j],array[i][j]);
		}
	}
	int sum = 0;
	for(int i = 0; i < m; i++)
	{
		for(int j = 0; j < n; j++)
		{
			if(array[i][j] == row[i] && array[i][j] == col[j])
			{
				printf("��%d������:i=%d,j=%d,ֵΪ:%d\n",++sum,i,j,array[i][j]);
			}
		}
	}
	if(sum == 0)
	{
		printf("�������ް���\n");
	}
	else
	{
		printf("����%d������\n",sum);
	}
}

int main()
{
	int m,n;
	printf("����������m n:");
	scanf("%d %d",&m,&n);
	solve(m,n);
}

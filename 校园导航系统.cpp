#include<cstdio>
#include<cstring>
#include<limits.h>
#define MaxL 0x3f3f3f3f //����ط�Ҫע�⣬������0x7fffffff��INF_MAX����Ϊ�ں��������ʱ����������ָ��������� 
#define Max_size 50

FILE *pf; 
int n;//�������
int G[Max_size][Max_size];
int flag[Max_size];//��־����,�Ƿ��Ѿ�����
int dis[Max_size];//��㵽����������̾��� 
int pre[Max_size]; //���·�� �����浱ǰ���ǰ�� 

void dijkstra(int v)//vΪ���ҵ�
{
	int i,j,t;
	int min;
	for(i=0;i<n;i++)
	{
		dis[i]=G[v][i];//��ʼ��ֵ 
		flag[i]=0; 
		if(dis[i]!=MaxL) pre[i]=v;//�����벻Ϊ����󣬼����Ե���Ϳ����ǰ���ǰ��Ϊ��ʼ�� 
	}
	pre[v]=NULL;
	flag[v]=1;//��ʼ�� 
	for(i=1;i<n;i++)//����ʣ���n-1���� 
	{
		min=MaxL;
		for(j=0;j<n;j++)//�Ҿ���v����ĵ� 
		{
			if(flag[j]==0&&dis[j]<min)
			{
				t=j;
				min=dis[j];
			}
		}
		flag[t]=1;
		for(j=0;j<n;j++)//����·������̾��� 
		{
			if(flag[j]==0&&(min+G[t][j]<dis[j]))
			{
				dis[j]=min+G[t][j];
				pre[j]=t;
			}
		}
	}
 } 

int main()
{
	pf=fopen("�ɹ���У԰��ͼ.txt","r");
	int i,j,m,p;//mΪҪ��ĵ㣬pΪͼ��·������
	char c;//cΪ����ĵ�ַ 
	int start,end,lon; 
	
	fscanf(pf,"%d%d",&n,&p);
	for(i=0;i<n;i++)
	  for(j=0;j<n;j++)
	    G[i][j]=MaxL;//��ʼ�� 
	for(i=0;i<p;i++)
	{
		fscanf(pf,"%d%d%d",&start,&end,&lon);
		G[start][end]=lon;
	}
	for(i=0;i<n;i++)  G[i][i]=0;//�Լ����Լ��ľ���Ϊ0
	
	printf("A:a,b¥����\nB:һʳ�ú��ۺ�¥\nC:c,d,e����¥\nD:��ʳ��\nE:������\nF:����¥\nG:��Զ¥\nH:�Ż�¥\nI:����¥\nJ:ͼ���\n");
	
	printf("��������㣺\n");
	scanf("%c",&c);
	m=c-'A';
	 
	dijkstra(m);
	
	for(i=0;i<n;i++)
	{
		if(dis[i]==MaxL)
		{
			printf("�����Ե���%c\n",i+'A');
			continue; 
		}
		printf("��%c�ľ���Ϊ��%d\n",i+'A',dis[i]);
		printf("    ���·��Ϊ��");
		for(j=i;;j=pre[j])//���·��,�䱾���Ƕ�������� 
		{
			if(j==i)
			  printf("%c",j+'A');
			else printf("<-%c",j+'A');
			if(j==m)
			  break;
		}
		printf("\n");
	}
	return 0;
 } 

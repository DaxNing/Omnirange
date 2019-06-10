#include<cstdio>
#include<cstring>
#include<limits.h>
#define MaxL 0x3f3f3f3f //这个地方要注意，不能用0x7fffffff和INF_MAX，因为在函数中相加时会溢出，出现负数！！！ 
#define Max_size 50

FILE *pf; 
int n;//顶点个数
int G[Max_size][Max_size];
int flag[Max_size];//标志数组,是否已经访问
int dis[Max_size];//起点到其余各点的最短距离 
int pre[Max_size]; //最短路径 ，保存当前点的前驱 

void dijkstra(int v)//v为查找点
{
	int i,j,t;
	int min;
	for(i=0;i<n;i++)
	{
		dis[i]=G[v][i];//初始赋值 
		flag[i]=0; 
		if(dis[i]!=MaxL) pre[i]=v;//若距离不为无穷大，即可以到达，就可以令当前点的前驱为起始点 
	}
	pre[v]=NULL;
	flag[v]=1;//初始化 
	for(i=1;i<n;i++)//查找剩余的n-1个点 
	{
		min=MaxL;
		for(j=0;j<n;j++)//找距离v最近的点 
		{
			if(flag[j]==0&&dis[j]<min)
			{
				t=j;
				min=dis[j];
			}
		}
		flag[t]=1;
		for(j=0;j<n;j++)//更新路径和最短距离 
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
	pf=fopen("辽工大校园地图.txt","r");
	int i,j,m,p;//m为要查的点，p为图的路径条数
	char c;//c为输入的地址 
	int start,end,lon; 
	
	fscanf(pf,"%d%d",&n,&p);
	for(i=0;i<n;i++)
	  for(j=0;j<n;j++)
	    G[i][j]=MaxL;//初始化 
	for(i=0;i<p;i++)
	{
		fscanf(pf,"%d%d%d",&start,&end,&lon);
		G[start][end]=lon;
	}
	for(i=0;i<n;i++)  G[i][i]=0;//自己到自己的距离为0
	
	printf("A:a,b楼宿舍\nB:一食堂和综合楼\nC:c,d,e宿舍楼\nD:二食堂\nE:体育馆\nF:行政楼\nG:静远楼\nH:耘慧楼\nI:尔雅楼\nJ:图书馆\n");
	
	printf("请输入起点：\n");
	scanf("%c",&c);
	m=c-'A';
	 
	dijkstra(m);
	
	for(i=0;i<n;i++)
	{
		if(dis[i]==MaxL)
		{
			printf("不可以到达%c\n",i+'A');
			continue; 
		}
		printf("到%c的距离为：%d\n",i+'A',dis[i]);
		printf("    最短路径为：");
		for(j=i;;j=pre[j])//输出路径,其本质是对树的输出 
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

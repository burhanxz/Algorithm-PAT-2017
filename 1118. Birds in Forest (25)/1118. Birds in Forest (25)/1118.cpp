#include <cstdio>
#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>
#define INPUT
using namespace std;
const int maxn = 10000 + 1;
int N,k,m,Q;
int arr[maxn];
vector<int>G[maxn];
bool vis[maxn];
int x,y;
int u,v;
int num,totl;
void dfs(int s)
{
	if(vis[s]) return;
	vis[s] = true;
	arr[s] = num;
	for(int i = 0;i != G[s].size();i++)
	{
		dfs(G[s][i]);
	}
}
int main()
{
#ifdef INPUT
	freopen("C:\\Users\\xuzhong\\Desktop\\pat\\input\\1118. Birds in Forest (25).txt","r",stdin);
#endif
	while (scanf("%d",&N) != EOF)
	{
		m = 0;
		for(int i = 0;i != maxn;i++)G[i].clear();
		for(int i = 0;i != N;i++)
		{
			scanf("%d",&k);
			for(int j = 0;j != k;j++)
			{
				scanf("%d",&x);
				m = max(m,x);
				if(j == 0)
				{
					u = x;
				}
				else
				{
					if(find(G[u].begin(),G[u].end(),x) == G[u].end())
					{
						G[u].push_back(x);
						G[x].push_back(u);
					}
				}
			}
		}
		memset(vis,0,sizeof(vis));
		memset(arr,-1,sizeof(arr));
		num = totl = 0;
		for(int i = 1;i <= m;i++)
		{
			if(!vis[i])
			{
				totl++;
				dfs(i);
				num++;
			}
		}
		printf("%d %d\n",totl,m);
		scanf("%d",&Q);
		for(int i = 0;i != Q;i++)
		{
			scanf("%d %d",&x,&y);
//			printf("%d %d\n",arr[x],arr[y]);
			if(arr[x] == arr[y])
				printf("Yes\n");
			else
				printf("No\n");
		}
	}
#ifdef INPUT
	while(1){}
	fclose(stdin);
#endif
}
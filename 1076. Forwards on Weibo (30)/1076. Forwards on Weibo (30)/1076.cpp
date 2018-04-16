#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#define INPUT
using namespace std;
vector<int>G[1001];
int N,L,K;
int n,x;
bool vis[1001];
int count_potl;
void dfs(int s,int level)
{
	if(vis[s]) return;
	vis[s] = true;
	count_potl++;
	if(!G[s].empty())
	{
		for(int i = 0;i != G[s].size();i++)
		{
			if(level + 1 <= L)
				dfs(G[s][i],level + 1);
		}
	}
}
int Count(int s)
{
	memset(vis,0,sizeof(vis));
	count_potl = 0;
	dfs(s,0);
	return --count_potl;
}
int main()
{
#ifdef INPUT
	freopen("C:\\Users\\xuzhong\\Desktop\\pat\\input\\1076. Forwards on Weibo (30).txt","r",stdin);
#endif
	while(scanf("%d%d",&N,&L) != EOF)
	{
		for(auto i = 1;i <= N;i++)
		{
			scanf("%d",&n);
			for(auto j = 0;j != n;j++)
			{
				scanf("%d",&x);
				G[x].push_back(i);
			}
		}
		scanf("%d",&K);
		for(auto i = 0;i != K;i++)
		{
			scanf("%d",&x);
			printf("%d\n",Count(x));
		}
	}
#ifdef INPUT
	while(1){}
	fclose(stdin);
#endif
}
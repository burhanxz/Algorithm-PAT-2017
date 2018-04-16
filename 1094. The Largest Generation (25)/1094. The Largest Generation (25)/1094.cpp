#include <vector>
#include <cstring>
#include <cstdio>
//#define INPUT
using namespace std;
const int maxn = 100;
int N,M;
int num[maxn];
vector<int>G[maxn];
int u,v,k;
bool vis[maxn];
void dfs(int s,int level)
{
	if(vis[s]) return;
	vis[s] = true;
	++num[level];
	for(int i = 0;i != G[s].size();i++)
	{
		dfs(G[s][i],level + 1);
	}
}
int main()
{
#ifdef INPUT
	freopen("C:\\Users\\xuzhong\\Desktop\\pat\\input\\1094. The Largest Generation (25).txt","r",stdin);
#endif
	while (scanf("%d%d",&N,&M) != EOF)
	{
		for(int i = 1;i <= N;i++) G[i].clear();
		for(int i = 0;i != M;i++)
		{
			scanf("%d%d",&u,&k);
			for(int j = 1;j <= k;j++)
			{
				scanf("%d",&v);
				G[u].push_back(v);
			}
		}
		memset(vis,0,sizeof(vis));
		memset(num,0,sizeof(num));
		dfs(1,1);
		int m = 0;
		int L = 1;
		for(int i = 1;num[i] != 0;i++)
		{
			if(m < num[i])
			{
				L = i;
				m = num[i];
			}
		}
		printf("%d %d\n",m,L);
	}
#ifdef INPUT
	while(1){}
	fclose(stdin);
#endif
}
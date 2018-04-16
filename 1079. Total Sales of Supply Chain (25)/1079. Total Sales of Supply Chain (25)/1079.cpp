#include <iostream>
#include <vector>
#include <map>
#include <cstring>
//#define INPUT
using namespace std;
const int MAXN = 100000 + 5;
vector<int>G[MAXN];
map<int,long long> prod;
double rate;
double unit;
int N;
int K;
int x;
long long y;
double totl;
bool vis[MAXN];
void dfs(int s,double r)
{
	if(vis[s]) return;
	vis[s] = true;
	if(G[s].empty())
	{
		totl += prod[s] * unit * r;
	}
	for(auto i = 0;i != G[s].size();i++)
	{
		dfs(G[s][i],r * (1 + rate / 100.0));
	}
}
double Count()
{
	totl = 0;
	memset(vis,0,sizeof(vis));
	dfs(0,1);
	return totl;
}
int main()
{
#ifdef INPUT
	freopen("C:\\Users\\xuzhong\\Desktop\\pat\\input\\1079. Total Sales of Supply Chain (25).txt","r",stdin);
#endif
	while (scanf("%d%lf%lf",&N,&unit,&rate) != EOF)
	{
		for(int i = 0;i != N;i++)G[i].clear();
		for(auto i = 0;i != N;i++)
		{
			scanf("%d",&K);
			if(K == 0)
			{
				scanf("%lld",&y);
				prod[i] = y;
			}
			else
				for(auto j = 0;j != K;j++)
				{
					scanf("%d",&x);
					G[i].push_back(x);
				}
		}
		printf("%.1lf\n",Count());

	}
#ifdef INPUT
	while(1){}
	fclose(stdin);
#endif
}
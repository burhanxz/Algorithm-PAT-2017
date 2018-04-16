#include <vector>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <memory>
//#define INPUT
using namespace std;
const int maxn = 100000 + 5;
int N;
double p,r;
bool vis[maxn];
vector<int>G[maxn];
vector<double>vec;
void dfs(int s,double x)
{
	if(vis[s]) return;
	vis[s] = true;
	if(G[s].empty()) vec.push_back(p * x / (1.0 + r / 100.0));
	else
		for(int i = 0;i != G[s].size();i++)
		{
			dfs(G[s][i],x * (1.0 + r / 100.0));
		}
}
void Count()
{
	vec.clear();
	memset(vis,0,sizeof(vis));
	dfs(0,1.0);
}
int main()
{
#ifdef INPUT
	freopen("C:\\Users\\xuzhong\\Desktop\\pat\\input\\1090. Highest Price in Supply Chain (25).txt","r",stdin);
#endif
	while (scanf("%d%lf%lf",&N,&p,&r)!= EOF)
	{
		for(int i = 0;i != N;i++) G[i].clear();
		for(int i = 0;i != N;i++)
		{
			int x;
			scanf("%d",&x);
			G[x+1].push_back(i + 1);
		}
		Count();
		sort(vec.begin(),vec.end(),
			[](const double &lhs,const double &rhs)->bool{return lhs > rhs;});
		double maxP = vec.front();
		int num = 0;
		for_each(vec.begin(),vec.end(),[&num,maxP](const double &x)->void{if(x == maxP) num++;});
		printf("%.2f %d\n",maxP,num);
	}
#ifdef INPUT
	while(1){}
	fclose(stdin);
#endif
}
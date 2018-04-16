#include <vector>
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <set>
#define INPUT
using namespace std;
const int maxn = 10000;
const int INF = 1 << 30;
vector<int>G[maxn];
double area[maxn];
double est[maxn];
struct Family
{
	int id;
	int num;
	double aveS;
	double aveA;
	Family(int _id,int _num,double _aveS,double _aveA):
		id(_id),num(_num),aveS(_aveS),aveA(_aveA){}
};
vector<Family>ans;
int N;
int u,v;
int k;
double x,y;
bool vis[maxn];
int _num,_id;
double _area,_est;
set<int>vertex;
void dfs(int s)
{
	if(vis[s]) return;
	vis[s] = true;
	_num++;
	_id = min(_id,s);
	_area += area[s];
	_est += est[s];
	for(int i = 0;i != G[s].size();i++)
	{
		dfs(G[s][i]);
	}
}
int main()
{
#ifdef INPUT
	freopen("C:\\Users\\xuzhong\\Desktop\\pat\\input\\1114. Family Property (25).txt","r",stdin);
#endif
	while(scanf("%d",&N) != EOF)
	{
		memset(area,0,sizeof(area));
		memset(est,0,sizeof(est));
		vertex.clear();
		for(int i = 0;i != N;i++)
		{
			scanf("%d",&u);
			vertex.insert(u);
			scanf("%d",&v);
			if(v != -1) 
			{
				G[u].push_back(v);
				G[v].push_back(u);
				vertex.insert(v);
			}
			scanf("%d",&v);
			if(v != -1) 
			{
				G[u].push_back(v);
				G[v].push_back(u);
				vertex.insert(v);
			}
			scanf("%d",&k);
			for(int j = 0;j != k;j++)
			{
				scanf("%d",&v);
				vertex.insert(v);
				G[u].push_back(v);
				G[v].push_back(u);
			}
			scanf("%lf%lf",&x,&y);
			est[u] = x;
			area[u] = y;
		}
		memset(vis,0,sizeof(vis));
		for(auto iter = vertex.begin();iter != vertex.end();iter++)
		{
			if(!vis[*iter])
			{
				_num = 0;_id = INF;
				_area = _est = 0.0;
				dfs(*iter);
				ans.push_back(Family(_id, _num, _est / _num, _area / _num));
			}
		}
		sort(ans.begin(),ans.end(),
			[](const Family &lhs,const Family &rhs)->bool
			{
				if(lhs.aveA != rhs.aveA)
					return lhs.aveA > rhs.aveA;
				else return lhs.id < rhs.id;
			});
		printf("%d\n",ans.size());
		for(auto iter = ans.begin();iter != ans.end();iter++)
		{
			printf("%04d %d %.3lf %.3lf\n",iter->id,iter->num,iter->aveS,iter->aveA);
		}
	}
#ifdef INPUT
	while(1){}
	fclose(stdin);
#endif
}
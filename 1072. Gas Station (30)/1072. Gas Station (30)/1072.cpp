#include <queue>
#include <vector>
#include <iostream>
#include <cstring>
#include <utility>
#include <algorithm>
//#define INPUT
using namespace std;
const int MAXN = 10000 + 5;
const int INF = 10000;
char ch[10];
int N,M,K,Ds,D;
int x,y;
vector<int>ans;
float ave[MAXN];
float min_dist[MAXN];
bool cmp(const int &lhs,const int &rhs)
{
	if(min_dist[lhs] != min_dist[rhs]) return min_dist[lhs] > min_dist[rhs];
	else if(ave[lhs] != ave[rhs]) return ave[lhs] < ave[rhs];
	else return lhs < rhs;
}
struct HeapNode 
{
	int u,d;
	HeapNode(int _u,int _d):u(_u),d(_d){}
	bool operator<(const HeapNode &rhs)const
	{
		return d > rhs.d;
	}
};
struct Edge
{
	int from,to,dist;
	Edge(int _u,int _v,int _d):from(_u),to(_v),dist(_d){}
};
struct Dijkstra
{
	vector<Edge>edges;
	vector<int>G[MAXN];
	bool vis[MAXN];
	int path[MAXN];
	int d[MAXN];

	void init()
	{
		memset(path,0,sizeof(path));
		for(auto i = 0;i != MAXN;i++) G[i].clear();
		edges.clear();
	}
	
	void AddEdge(int _u,int _v,int _dist)
	{
		edges.push_back(Edge(_u,_v,_dist));
		G[_u].push_back(edges.size() - 1);
		edges.push_back(Edge(_v,_u,_dist));
		G[_v].push_back(edges.size() - 1);
	}
	void dijkstra(int s)
	{
		priority_queue<HeapNode>Q;
		memset(vis,0,sizeof(vis));
		for(int i = 0;i != N + M + 1;i++) d[i] = INF;
		Q.push(HeapNode(s,0));
		d[s] = 0;
		while (!Q.empty())
		{
			auto h = Q.top();Q.pop();
			auto u = h.u; 
			if(vis[u]) continue;
			vis[u] = true;
			for(auto i = 0;i != G[u].size();i++)
			{
				auto e = edges[G[u][i]];
				auto dist = e.dist;
				auto v = e.to;
				if(d[u] + dist < d[v])
				{
					path[v] = u;
					d[v] = d[u] + dist; 
					Q.push(HeapNode(v,d[v]));
				}
			}
		}
	}
};
int main()
{
#ifdef INPUT
	freopen("C:\\Users\\xuzhong\\Desktop\\pat\\input\\1072. Gas Station (30).txt","r",stdin);
#endif
	while (scanf("%d%d%d%d",&N,&M,&K,&Ds) != EOF)
	{
		Dijkstra Di;
		Di.init();
		ans.clear();

		for(auto i = 0;i != K;i++)
		{
			scanf("%s",ch);
			if(ch[0] != 'G') x = atoi(ch);
			else x = atoi(ch + 1) + N;
			scanf("%s",ch);
			if(ch[0] != 'G') y = atoi(ch);
			else y = atoi(ch + 1) + N;
			scanf("%d",&D);
//			cout << x << " " << y << " " <<D << endl;
			Di.AddEdge(x,y,D);
		}
		for(auto i = N + 1;i <= N + M;i++)
		{
			auto ret = i;
			auto minD = 10000.0;
			auto _ave = 0.0;
			Di.dijkstra(ret);
			bool ok = true;
			for(auto j = 1;j <= N;j++)
			{
				if(Di.d[j] > Ds) {ok = false;break;}
				if(Di.d[j] < minD) minD = Di.d[j];
				_ave += Di.d[j];
			}
			if(!ok) continue;
			ans.push_back(ret);
			ave[ret] = _ave / N;
			min_dist[ret] = minD;
		}
		if(ans.empty())
		{
			printf("No Solution\n");
			continue;
		}
		sort(ans.begin(),ans.end(),cmp);
		printf("G%d\n",ans[0] - N);
		printf("%.1lf %.1lf\n",min_dist[ans[0]],(int)((ave[ans[0]] * 10 + 0.5)) / 10.0);

	}
#ifdef INPUT
	while (1){}
	fclose(stdin);
#endif
}
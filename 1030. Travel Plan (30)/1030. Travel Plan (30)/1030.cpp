#include <iostream>
#include <cstring>
#include <string>
#include <stdlib.h>
#include <queue>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <stack>
/*#define INPUT*/
using namespace std;
const int maxn = 500 + 1;
const int INF = 0x7fffffff;
int N,M,S,D;
struct Edge
{
	int u,v,dist,cost;
	Edge(int _u,int _v,int _dist,int _cost):u(_u),v(_v),dist(_dist),cost(_cost){}
};
struct HeapNode
{
	int u,d;//当前，源点到u的距离是d
	HeapNode(int _u,int _d):u(_u),d(_d){}
	bool operator < (const HeapNode &rhs) const//优先队列中降序排序
	{
		return d > rhs.d;
	}
};
struct Dijkstra
{
	int n;//顶点数目
	int m;//边的编号
	vector<int>G[maxn];//存储指定顶点连接的所有边
	vector<Edge>edges;//储存所有边
	/*G[]和edges所储存的边被统一编号*/
	bool vis[maxn];
	int path[maxn];
	int d[maxn];
	int c[maxn];
	void init(int _n)
	{
		n = _n;
		for(int i = 0;i != n;i++)G[i].clear();
		edges.clear();
	}
	void AddEgde(int _u,int _v,int _dist,int _cost)
	{
		edges.push_back(Edge(_u,_v,_dist,_cost));
		m = edges.size();
		G[_u].push_back(m-1);
	}
	void dijkstra(int s)
	{
		priority_queue<HeapNode>Q;
		for(int i = 0;i != n;i++){d[i] = INF;c[i] = INF;}
		c[s] = d[s] = 0;
		memset(vis,0,sizeof(vis));
		Q.push(HeapNode(s,0));
		while (!Q.empty())
		{
			HeapNode h = Q.top();Q.pop();
			int u = h.u;
			if(vis[u])continue;
			vis[u] = true;
			for(int i = 0;i != G[u].size();i++)
			{
				Edge e = edges[G[u][i]];
				int v = e.v;
				if(d[v] > d[u] + e.dist)
				{
					d[v] = d[u] + e.dist;
					c[v] = c[u] + e.cost;
					path[v] = G[u][i];
					Q.push(HeapNode(v,d[v]));
				}
				else if(d[v] == d[u] + e.dist && c[v] > c[u] + e.cost)
				{
					c[v] = c[u] + e.cost;
					path[v] = G[u][i];
					Q.push(HeapNode(v,d[v]));
				}
			}
		}
	}
};
stack<int>pathOutput;
int main()
{
#ifdef INPUT
	freopen("C:\\Users\\xuzhong\\Desktop\\pat\\input\\1030. Travel Plan (30).txt","r",stdin);
#endif
	while (scanf("%d%d%d%d",&N,&M,&S,&D) != EOF)
	{
		Dijkstra Dij;
		Dij.init(N);
		int _u,_v,_dist,_cost;
		for(int i = 0;i != M;i++)
		{
			scanf("%d%d%d%d",&_u,&_v,&_dist,&_cost);
			Dij.AddEgde(_u,_v,_dist,_cost);
		}
		Dij.dijkstra(S);

		while (!pathOutput.empty()) pathOutput.pop();
		int v = D;
		while (v != S)
		{
			pathOutput.push(v);
			v = Dij.edges[Dij.path[v]].u;
		}
		pathOutput.push(S);
		while(!pathOutput.empty())
			{cout << pathOutput.top() << " ";pathOutput.pop();}
		cout << Dij.d[D] << " " << Dij.c[D] << endl;
	}
#ifdef INPUT
	while(1){}
	fclose(stdin);
#endif
}
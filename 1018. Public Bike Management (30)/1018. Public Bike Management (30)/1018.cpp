#include <iostream>
#include <queue>
#include<algorithm>
#include <vector>
#include<string>
#include<cstring>
#include <list>
//#define DEBUG
using namespace std;
const int SIZE = 501;
const int INF = 100000;
int C,N,S,M;
struct Edge
{
	int from,to,dist;
	Edge(int u,int v,int d):from(u),to(v),dist(d){}
};
struct HeapNode
{
	int d,u;
	HeapNode(int _d,int _u):d(_d),u(_u){}
	bool operator<(const HeapNode &rhs)const
	{
		return d > rhs.d;
	}
};
struct Dijkstra
{
	vector<Edge> edges;
	vector<int> G[SIZE];
	int d[SIZE];
	int p[SIZE];
	int c[SIZE];
	int a[SIZE];
	bool vis[SIZE];
	int n;
	void init()
	{
		edges.clear();
		for(int i = 0; i != SIZE;i++) G[i].clear();
		n = 0;
	}
	void AddEdge(int u,int v,int dist)
	{
		edges.push_back(Edge(u,v,dist));
		G[u].push_back(n++);
	}
	void setC(int _u,int _c)
	{
		c[_u] = _c;
	}
	void dijkstra(int s)
	{
		priority_queue<HeapNode>Q;
		memset(p,0,sizeof(p));
		for(int i = 0; i!=SIZE; i++){vis[i] = false;d[i] = INF;}
		Q.push(HeapNode(0,s));
		a[s] = 0;
		d[s] = 0;
		while (!Q.empty())
		{
			HeapNode h = Q.top();Q.pop(); //反复出错点，如果使用 HeapNode &h = Q.top(),则h的值会随top()改变而改变，而pop()之后top()就变了
			int u = h.u;
#ifdef DEBUG
			cout << "u=" << u << endl;
#endif
			if(vis[u])continue;
			vis[u] = true;
			for(int i = 0;i != G[u].size();i++)
			{
				Edge &e = edges[G[u][i]]; 
				int v = e.to;
				if(d[u] + e.dist < d[v])
				{
					d[v] = d[u] + e.dist;
					a[v] = a[u] + c[v];
					p[v] = u;
					Q.push(HeapNode(d[v],v));
				}
				else if(d[u] + e.dist == d[v])
				{
					if(a[u] + c[v] > a[v])
					{
						a[v] = a[u] + c[v];
						p[v] = u;
						Q.push(HeapNode(d[v],v));
					}
			    }
#ifdef DEBUG
				cout << "d[" << v << "]=" << d[v] <<", "<< "a[" << v << "]=" << a[v] <<", "<< "p[" << v << "]=" << p[v] <<endl;
#endif		
		    }
	    }
	}
};
Dijkstra solve;
list<int>path;
void findPath(int s)
{
	int _u = solve.p[s];
	path.push_front(_u);
	if(_u != 0) findPath(_u);
}
int main()
{
	while (cin >> C >> N >> S >> M)
	{
		solve.init();
		path.clear();
		for (int i = 1; i <= N; i++)
		{
			int _c;
			cin >> _c;
			solve.setC(i,_c);
		}
		for (int i = 0; i != M;i++)
		{
			int _u,_v,_dist;
			cin >> _u >> _v >> _dist;
			solve.AddEdge(_u,_v,_dist);
		}
		//输入
		solve.dijkstra(0);
		findPath(S);
		int perfectNum = C / 2;
		int x = (path.size() - 1) * perfectNum;
		int y;
		int z;
		if(solve.a[S] >= x)
		{
			if(solve.a[S] - x >= perfectNum)
			{
				y = 0;
				z = solve.a[S] - x - perfectNum;
			}
			else 
			{
				y = perfectNum - (solve.a[S] - x);
				z = 0;
			}
		}
		else 
		{
			y = (x - solve.a[S]) + perfectNum;
			z = 0;
		}
		cout << y << " ";
		for(list<int>::const_iterator iter = path.begin();iter != path.end();iter++)
			cout << *iter <<"->";
		cout << S << " " << z << endl;

	}
}
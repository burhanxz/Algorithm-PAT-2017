#include <vector>
#include <map>
#include <iostream>
#include <string>
#include <cstring>
#include <queue>
#include <stack>
//#define INPUT
using namespace std;
const int maxn = 201;
const int INF = 10000000;
map<string,int>iMap;
string hash_to_string[maxn];
stack<string>path_to_rome;
int N,K;
string s;
string s1,s2;
int x;
int happiness[maxn];
struct HeapNode
{
	int u,d;
	HeapNode(int _u,int _d):u(_u),d(_d){}
	bool operator < (const HeapNode &rhs) const
	{
		return d > rhs.d;
	} 
};
struct Edge
{
	int from,to,dist;
	Edge(int u,int v,int d):from(u),to(v),dist(d){}
};
struct Dijkstra
{
	vector<Edge>edges;
	vector<int>G[maxn];
	int d[maxn];
	int p[maxn];
	int np[maxn];
	int path[maxn];
	int happ[maxn];
	int vis[maxn];
	double ave[maxn];
	void init()
	{
		edges.clear();
		for(int i = 1;i <= N;i++) G[i].clear();
	}
	void AddEdge(int u,int v,int dist)
	{
		edges.push_back(Edge(u,v,dist));
		G[u].push_back(edges.size() - 1);
		edges.push_back(Edge(v,u,dist));
		G[v].push_back(edges.size() - 1);
	}
	void dijkstra(int s)
	{
		priority_queue<HeapNode>Q;
		for(int i = 1;i <= N;i++) d[i] = INF;
		memset(vis,0,sizeof(vis));
		memset(happ,0,sizeof(happ));
		memset(p,0,sizeof(p));
		memset(ave,0,sizeof(ave));
		memset(np,0,sizeof(np));
		d[s] = 0;
		happ[s] = 0;
		p[s] = 0;
		ave[s] = 0;
		np[s] = 1;
		Q.push(HeapNode(s,0));
		while (!Q.empty())
		{
			HeapNode h = Q.top();Q.pop();
			int u = h.u;
			if(vis[u]) continue;
			vis[u] = true;
			for(int i = 0;i != G[u].size();i++)
			{
				Edge e = edges[G[u][i]];
				int v = e.to;
				int dist = e.dist;
				if(d[v] > d[u] + dist)
				{
					d[v] = d[u] + dist;
					happ[v] = happ[u] + happiness[v];
					p[v] = p[u] + 1;
					ave[v] = happ[v] / p[v];
					path[v] = u;
					np[v] = np[u];
					Q.push(HeapNode(v,d[v]));
				}
				else if(d[v] == d[u] + dist)
				{
					np[v] += np[u];
					if(happ[v] < happ[u] + happiness[v])
					{
						happ[v] = happ[u] + happiness[v];
						p[v] = p[u] + 1;
						ave[v] = happ[v] / p[v];
						path[v] = u;
					}
					else if(happ[v] == happ[u] + happiness[v])
					{
						if(happ[v] / p[v] < (happ[u] + happiness[v]) / (p[u] + 1))
						{
							happ[v] = happ[u] + happiness[v];
							p[v] = p[u] + 1;
							ave[v] = happ[v] / p[v];
							path[v] = u;
						}
					}
				}
			}
		}
	}
};
void find_path(const Dijkstra &Di,int u)
{
	if(u == 1) 
	{
		path_to_rome.push(hash_to_string[u]);
		return;
	}
	else 
	{
		path_to_rome.push(hash_to_string[u]);
		u = Di.path[u];
		find_path(Di,u);
	}
}
int main()
{
#ifdef INPUT
	freopen("C:\\Users\\xuzhong\\Desktop\\pat\\input\\1087. All Roads Lead to Rome (30).txt","r",stdin);
#endif
	while (cin >> N >> K >> s)
	{
		Dijkstra Di;
		Di.init();
		iMap.clear();
		iMap[s] = 1;
		hash_to_string[1] = s;
		for(int i = 0;i != N - 1;i++)
		{
			cin >> s >> happiness[i + 2];
			iMap[s] = i + 2;
			hash_to_string[i + 2] = s;
		}
		for(int i = 0;i != K;i++)
		{
			cin >> s1 >> s2 >> x;
			Di.AddEdge(iMap[s1],iMap[s2],x);
		}
		Di.dijkstra(1);
		int des = iMap["ROM"];
		while (!path_to_rome.empty())
		{
			path_to_rome.pop();
		}
		find_path(Di,des);
		cout << Di.np[des] << " "<< Di.d[des] <<" "<< Di.happ[des] << " "<< Di.ave[des] << endl;
		bool isFirst = true;
		while (!path_to_rome.empty())
		{
			string temp = path_to_rome.top();
			path_to_rome.pop();
			if(isFirst) 
			{
				isFirst = false;
				cout << temp;
			}
			else cout << "->" << temp;
		}
		cout << endl;
	}
#ifdef INPUT
	while(1){}
	fclose(stdin);
#endif
}
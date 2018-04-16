#include <iostream>
#include<vector>
#include<queue>
#include <cstring>
using namespace std;
const int maxn = 505;//��󶥵���
const int INF = 0xffffff;//�����

int d[505];//Դ�㵽��һ�����·��
int p[505];//ĳ�������·���ϵ�ǰ��
bool vis[505];//ĳ���Ƿ���ʹ�
struct Edge{     //����һ����
	int from,to,dist;
	Edge(int u, int v, int d):from(u),to(v),dist(d){}
	bool operator<(const Edge &e)const
	{
		return dist > e.dist;
	}
};

vector<Edge>G[maxn]; //�����ڽӱ�

void dijkstra(int s) //dijkstra�㷨
{
	priority_queue<Edge>Q;
	memset(vis,0,sizeof(vis));
	vis[s] = true;
	for (int i = 0; i<=500; i++)
		d[i] = INF;
	d[s] = 0;
	for (int i = 0; i != G[s].size(); i++)
	{
		Q.push(G[s][i]);
	}
	d[Q.top().to] = Q.top().dist;


	while (!Q.empty())
	{
		Edge &e = Q.top();Q.pop();
		if (vis[e.to]) continue;
		vis[e.to] = true;
		p[e.to] = e.from;

		for (int i = 0; i != G[e.to].size(); i++)
		{
			if (d[e.to] + G[e.to][i].dist < d[G[e.to][i].to] )
			{
				d[G[e.to][i].to] = d[e.to] + G[e.to][i].dist;
				Q.push(G[e.to][i]);
			}
			
		}
	}
	

	Q.clear();
}

int res[505];
int main()
{
	int u,v,d;
	int n,m,c1,c2;
	while (cin >> n >> m >> c1 >> c2)
	{
		for (int i = 0; i != n; i++)
		{
			cin >> res[i];
		}
		for (int i = 0; i != m; i++)
		{
			cin >> u >> v >> d;
			G[u].push_back( Edge(u, v, d) );
		}
		dijkstra(c1);
		cout << d[c2] << endl;
	}
}
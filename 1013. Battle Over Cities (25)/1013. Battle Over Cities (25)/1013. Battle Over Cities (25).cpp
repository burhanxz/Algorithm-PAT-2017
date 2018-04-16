#include <iostream>
#include <cstring>
#include<string>
using namespace std;
int G[1000][1000];
int vis[1000];
int ans;
int n,m,k;
int u,v;
int temp[1000];
void dfs(int t)
{
	vis[t] = 1;
	for(int i = 1;i<=n;i++)
	{
		if(vis[i] == 0 && G[t][i] == 1)
			dfs(i);
	}
}
int main()
{
	while (cin >> n >> m >> k)
	{
		for(int i = 0; i != 1000;i++)
			for(int j = 0; j != 1000;j++)G[i][j] = 0;
		for(int i = 0; i != m; i++){cin >> u >> v;G[u][v] = 1;G[v][u] = 1; }

		for (int i = 0; i != k;i++) cin >> temp[i];
		for (int i = 0; i != k;i++)
		{
			memset(vis, 0 ,sizeof(vis));
			vis[temp[i]] = 1;
			int num = 0;
			for(int j = 1; j <= n;j++)
			{
				if (vis[j] == 0)
				{
					dfs(j);
					num ++;
				}
			}
			cout << num - 1 << endl;;
		}

	}
}
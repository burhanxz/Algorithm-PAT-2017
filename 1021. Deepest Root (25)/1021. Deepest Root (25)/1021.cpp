#include <iostream>
#include <string>
#include <stdio.h>
#include<vector>
#include <algorithm>
#define DEBUG
#define INPUT
using namespace std;
vector<int>G[10002];
bool vis[10002];
int deep[10002];
int N;
void read_graph()//读入数据形成图
{
	for(int i = 0;i != 10002;i++)G[i].clear();
	int u,v;
	for(int i = 0;i != N - 1;i++)
	{
		cin >> u >> v;
		G[u].push_back(v);
		G[v].push_back(u);
	}
}
void dfs(int u)//component_num()驱动程序
{
	vis[u] = true;
	for(int i = 0;i != G[u].size();i++)
	{
		int v = G[u][i];
		if(!vis[v]) dfs(v);
	}
}
int component_num()//判断图中连通分量的数目
{
	for(int i = 0;i != 10002;i++)vis[i] = false;
	int componentNum = 0;
	for(int i = 1;i <= N;i++) 
		if (!vis[i])
		{
			++componentNum;
			dfs(i);
		}
	return componentNum;
}
int do_dfs(int u)//setDeep()驱动程序
{
	vis[u] = true;
	int d = 0;
	if(!G[u].size())return 1;
	else
	{
		for(int i = 0;i != G[u].size();i++)
		{
			int v = G[u][i];
			if(!vis[v]) d = max(d,do_dfs(v));
		}
		return d + 1;
	}
}
void setDeep()//在图是树的情况下，计算最大深度
{
	for(int i = 1;i <= N;i++)
	{
		for(int j = 0;j != 10002;j++)vis[j] = false;
		deep[i] = do_dfs(i);
#ifdef DEBUG
		cout << "deep["<<i<<"]= "<< deep[i] <<endl;
#endif
	}
		
	sort(deep + 1,deep + N + 1);
	int maxDeep = deep[N];
	for(int i = 1; i <= N;i++)
		if(deep[i] == maxDeep) cout << i << endl;
}
int main()
{
#ifdef INPUT
	freopen("C:\\Users\\xuzhong\\Desktop\\pat\\input\\1021. Deepest Root (25).txt","r",stdin);
#endif
	while (cin >> N)
	{
		read_graph();
		if(component_num() == 1) setDeep();
		else cout << "Error: "<< component_num() <<" components" << endl;
	}
#ifdef INPUT
	while(1){}
	fclose(stdin);
#endif
}
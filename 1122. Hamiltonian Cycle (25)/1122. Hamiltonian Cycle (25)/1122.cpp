#include <vector>
#include <iostream>
#include <cstring>
#include <set>
#define INPUT
using namespace std;
const int maxn = 201;
vector<int>G[maxn];
int num;
int arr[maxn];
int _index[maxn];
bool vis[maxn];
int N,M,K,n;
int u,v;
void dfs(int s)
{
	if(vis[s]) return;
	vis[s] = true;
	arr[num]++;
	_index[s] = num;
	for(int i = 0;i != G[s].size();i++)
	{
		dfs(G[s][i]);
	}
}
set<int>S;
int main()
{
#ifdef INPUT
	freopen("C:\\Users\\xuzhong\\Desktop\\pat\\input\\1122. Hamiltonian Cycle (25).txt","r",stdin);
#endif
	while(scanf("%d%d",&N,&M) != EOF)
	{
		memset(arr,0,sizeof(arr));
		memset(_index,-1,sizeof(_index));
		S.clear();
		for(int i = 0;i != maxn;i++)G[i].clear();
		for(int i = 0;i != M;i++)
		{
			scanf("%d%d",&u,&v);
			G[u].push_back(v);
			G[v].push_back(u);
		}
		memset(vis,0,sizeof(vis));
		num = 0;
		for(int i = 1;i <= N;i++)
		{
			if(!vis[i])
			{
				dfs(i);
				num++;
			}
		}
// 		for(int i = 0;i != num;i++)
// 			cout << "arr[" << i << "]=" << arr[i] << endl;
 		scanf("%d",&K);
		bool ok = true;
		int first,last;
		for(int i = 0;i != K;i++)
		{
			ok = true;
			scanf("%d",&n);
			S.clear();
			for(int j = 0;j != n;j++)
			{
				scanf("%d",&u);
				if(u > N) ok = false;
				if(j == 0)
				{
					first = u;
					S.insert(u);
					if(arr[_index[u]] != n - 1)
						ok = false;
				}
				else if(j == n - 1)
				{
					if(u != first)
						ok = false;
				}
				else 
				{
					if(S.count(u)) 
						ok = false;
					S.insert(u);
					if(_index[u] != _index[first])
						ok = false;
				}
				last = u;
			}
			if(ok) printf("YES\n");
			else printf("NO\n");
		}
	}
#ifdef INPUT
	while(1){}
	fclose(stdin);
#endif
}
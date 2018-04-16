#include <iostream>
#include<vector>
#include<queue>
#include <cstring>
#include <algorithm>
using namespace std;
const int INF = 1000;
int d[502][502];
int d1[502][502];
int res[502];
inline int _min(int a,int b){return a < b ? a : b;}
int main()
{
	int u,v,_d;
	int n,m,c1,c2;
	while (cin >> n >> m >> c1 >> c2)
	{
		for(int i = 0; i < n; i++)
			for(int j = 0; j < n; j++) {d[i][j] = INF;d1[i][j] = INF;}
		for (int i = 0; i != 500; i++)
		{
			d[i][i] = 0;d1[i][i] = 0;
		}
		//初始化d
		for (int i = 0; i != n; i++)
		{
			cin >> res[i];
		}
		for (int i = 0; i != m; i++)
		{
			cin >> u >> v >> _d;
			d[u][v] = _d;
			d1[u][v] = res[u] * -1;
		}
		//输入
		for (int k = 0; k < n; k++)
			for(int i = 0; i < n; i++)
				for(int j = 0; j < n; j++)
				{
						d[i][j] = _min(d[i][j],d[i][k]+d[k][j]);
						d1[i][j] = _min(d1[i][j],d1[i][k]+d1[k][j]);
// 						cout << "d["<<i<<"]["<<j<<"]=" <<d[i][j]<<endl;
// 						cout << "d1["<<i<<"]["<<j<<"]=" <<d1[i][j]<<endl;
				}
		//floyd算法求最短路和最长路
		cout << d[c1][c2] <<" "<<(d1[c1][c2])*(-1)+res[c2]<<endl;
			
	}

}
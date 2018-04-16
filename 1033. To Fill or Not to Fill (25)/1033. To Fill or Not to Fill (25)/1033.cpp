#include <iostream>
#include <stdio.h>
#include <iomanip>
#include <algorithm>
#include<vector>
#include <utility>
#define INPUT
#define DEBUG
using namespace std;
const int SIZE = 500 + 5;
const float INF = (1 << 30) * 1.0;
float cost[SIZE];
float price[SIZE];
float use[SIZE];
int dist[SIZE];
bool vis[SIZE];
float _price;
int _dist;
int C,D,N;
float Davg;
bool cmp(const pair<float,int> &lhs,const pair<float,int> &rhs)
{
	return lhs.second < rhs.second;
}
float solve(int n)
{
#ifdef DEBUG
	cout << "n="<< n << endl;
#endif
	if(vis[n]) return cost[n];
	else
	{
		if(n == 0) return 0.0;
		else
		{
			float minCost = INF;
			for(int i = n - 1;i >= 0;i--)
				minCost = min(minCost,solve(i) + (use[n] - use[i]) * price[i]);
			cost[n] = minCost;
			vis[n] = true;
#ifdef DEBUG
			cout << "cost["<< n << "]=" << cost[n] << endl;
#endif
			return minCost;
		}
	}
}
vector< pair<float,int> > vec;
int main()
{
#ifdef INPUT
	freopen("C:\\Users\\xuzhong\\Desktop\\pat\\input\\1033. To Fill or Not to Fill (25).txt","r",stdin);
#endif
	while (scanf("%d%d%f%d",&C,&D,&Davg,&N)!=EOF)
	{
		vec.clear();
		for(int i = 0;i != N;i++)
		{
			scanf("%f%d",&_price,&_dist);
			vec.push_back(pair<float,int>(_price,_dist));
		}
		sort(vec.begin(),vec.end(),cmp);
		for(int i = 0;i != vec.size();i++)
		{
			price[i] = vec[i].first;
			dist[i] = vec[i].second;
		}
		for(int i = 0;i != N;i++) 
		{
			use[i] = dist[i] / Davg;
		}
		dist[N] = D;
		use[N] = dist[N] / Davg;

		int s;
		bool ok = true;
		if(dist[N - 1] != D) s = N;
		else s = N - 1;
		for(int i = 1;i <= N;i++) 
			if(use[i] - use[i - 1] > 50.0) 
			{
				int maxDist = 50 * Davg + dist[i - 1];
				ok = false;
				cout << "The maximum travel distance = " << maxDist << endl;
			} 

#ifdef DEBUG
			for(int i = 0;i <= s;i++)
			{
				cout << "use[" << i << "]= "<<use[i] << endl;
				if(i < s)cout << "price[" << i << "]=" << price[i] << endl;
				cout << "dist[" << i << "]=" << dist[i] << endl;
			}
#endif

		if(!ok) continue;
		for(int i = 0;i  <= s;i++) vis[i] = false;
		cost[0] = 0.0;
		cout << solve(s) << endl;
	}
#ifdef INPUT
	while(1){}
	fclose(stdin);
#endif
}
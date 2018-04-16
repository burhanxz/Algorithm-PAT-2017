#include <vector>
#include <string>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <string.h>
#include <cstring>
// #define INPUT
// #define DEBUG
using namespace std;
vector<int>G[100];
vector<int>vec[101];
int vec_num;
int N,M,S;
int w[100];
int path[100];
int order[101];
int u,v,k;

void dfs(int u,int level)
{
	path[level] = u;
	if(G[u].empty())
	{
		int sum = 0;
		for(int i = 0;i <= level;i++) sum += w[path[i]];
		if(sum == S)
		{
			for(int i = 0;i <= level;i++) vec[vec_num].push_back(w[path[i]]);
			vec_num++;
		}
	}
	else
	{
		int SIZE = G[u].size();
		for(int i = 0;i != SIZE;i++)
		{
			int v = G[u][i];
			dfs(v,level + 1); 
		}
	}
}
bool cmp(const int &lhs,const int &rhs)
{
	string s1,s2;
	stringstream ss;
	string ap;
	for(int i = 0;i != vec[lhs].size();i++)
	{
		ss << vec[lhs][i];ss >> ap; ss.clear();ss.str("");
		s1.append(ap);
	}
	for(int i = 0;i != vec[rhs].size();i++)
	{
		ss << vec[rhs][i];ss >> ap; ss.clear();ss.str("");
		s2.append(ap);
	}
	int SIZE = max(s1.size(),s2.size());
	while(s1.size() < SIZE) s1.push_back('0');
	while(s2.size() < SIZE) s2.push_back('0');
	return s1 > s2;
}
int main()
{
#ifdef INPUT
	freopen("C:\\Users\\xuzhong\\Desktop\\pat\\input\\1053. Path of Equal Weight (30).txt","r",stdin);
#endif
	while(scanf("%d%d%d",&N,&M,&S) != EOF)
	{
		for(int i = 0;i != N;i++){G[i].clear();vec[i].clear();}
		memset(path,0,sizeof(path));
 
		for(int i = 0;i != N;i++) scanf("%d",w + i);

		if(N == 1 && w[0] == S) {printf("%d\n",S);continue;}

		for(int i = 0;i != M;i++)
		{
			scanf("%d%d",&u,&k);
			for(int j = 0;j != k;j++)
			{
				scanf("%d",&v);
				G[u].push_back(v);
			}
		}
		
		vec_num = 0;
		dfs(0,0);
		for(int i = 0;i != vec_num;i++)order[i] = i;
		sort(order,order + vec_num,cmp);

		for(int i = 0; i != vec_num;i++)
		{
			int x = order[i];
			for(int j = 0;j != vec[x].size();j++)
			{
				if(j == 0){printf("%d",vec[x][j]);continue;}
				printf(" %d",vec[x][j]);
			}
			printf("\n");
		}
	}
#ifdef INPUT
	while(1){}
	fclose(stdin);
#endif
}
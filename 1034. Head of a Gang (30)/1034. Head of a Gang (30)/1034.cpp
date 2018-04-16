#include <string>
#include <map>
#include <utility>
#include <iostream>
#include <set>
#include <algorithm>
#include <vector>
#include <cstring>
#define INPUT
using namespace std;
map< pair<int,int>, int> iMap;
set<int>S;
int N,K;
char ch1[5],ch2[5];
int x;
int toInt(char ch[])
{
	return (ch[0] - 'A') * 26 * 26 + (ch[1] - 'A') * 26 + ch[2] - 'A';
}
void toString(int x, char (&ch)[5])
{
	ch[0] = x / (26 * 26) + 'A';
	x %= (26 * 26);
	ch[1] = x / 26 + 'A';
	ch[2] = x % 26 + 'A';
	ch[3] = '\0';
};
vector<pair<char*,int>> ans;
int father[10000];
int callTime[10000];
int maxTime[10000];
int gang[10000];
int totl[10000];
int num[10000];
int findFather(int x)
{
	while (x != father[x])
	{
		x = father[x];
	}
	return x;
}
void Union(int a,int b)
{
	int faA = findFather(a);
	int faB = findFather(b);
	if(faA != faB)
	{
		father[faA] = faB;
		totl[faB] += totl[faA];
		char _ch1[5];
		char _ch2[5];
		toString(faA,_ch1);
		toString(faB,_ch2);
		printf("%s is %s 's father\n",_ch2,_ch1);
		num[faB] += num[faA];
		if(maxTime[faA] > maxTime[faB])
		{
			maxTime[faB] = maxTime[faA];
			gang[faB] = faA;
		}
	}
}
int main()
{
#ifdef INPUT
	freopen("C:\\Users\\xuzhong\\Desktop\\pat\\input\\1034. Head of a Gang (30).txt","r",stdin);
#endif
	fill(callTime, callTime + 10000,0);
	fill(maxTime, maxTime + 10000,0);
	fill(num,num + 10000,0);
	scanf("%d%d",&N,&K);
	for(int i = 0;i != N;i++)
	{
		scanf("%s %s %d",ch1,ch2,&x);
		int u = toInt(ch1);
		int v = toInt(ch2);
		callTime[u] += x;
		callTime[v] += x;
		printf("%s=%d, %s=%d\n",ch1,u,ch2,v);
		S.insert(u);
		S.insert(v);
		pair<int, int> p;
		if(u < v)
			 p = make_pair(u,v);
		else p = make_pair(v,u);
		if(!iMap.count(p))
		{
			iMap.insert(make_pair(p,0));
			iMap[p] += x;
		}
		else iMap[p] += x;
	}
	for(int i = 0;i != 10000;i++)
	{
		father[i] = i;
		maxTime[i] = callTime[i];
		totl[i] = callTime[i];
		gang[i] = i;
		num[i] = 1;
	}
	for(auto iter = iMap.begin();iter != iMap.end();iter++)
	{
// 		char _ch1[5];
// 		char _ch2[5];
// 		toString(iter->first.first,_ch1);
// 		toString(iter->first.second,_ch2);
// 		printf("%s %s %d\n",_ch1,_ch2,iter->second);
		Union(iter->first.first,iter->first.second);
	}
	for(auto iter = S.begin();iter != S.end();iter++)
	{
		if(*iter == father[*iter]) 
		{
			printf("%d\n",*iter);
			char ch[5];
			toString(gang[*iter],ch);
			if(totl[*iter] > K)
			{
				printf("%d\n",totl[*iter]);
				ans.push_back(make_pair(ch,num[*iter]));
			}
		}	
	}
	sort(ans.begin(),ans.end(),
		[](const pair<char*,int> &lhs, const pair<char*,int> &rhs)
		{
			return strcmp(lhs.first,rhs.first) < 0;
		}
		);
	printf("%d\n",ans.size());
	if(!ans.empty())
	{
		for(auto iter = ans.begin();iter != ans.end();iter++)
		{
			printf("%s %d\n",iter->first,iter->second);
		}
	}
#ifdef INPUT
	while(1){}
	fclose(stdin);
#endif
}
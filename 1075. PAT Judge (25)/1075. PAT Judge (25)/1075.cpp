#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <string>
#define INPUT
using namespace std;
int p[6];
int N,K,M;
int x,y,z;
struct Person
{
	int ID;
	int score[6];
	bool isSummited;
	int perf;
	int totl;
	void init(int _i)
	{
		memset(score,-1,sizeof(score));
		isSummited = false;
		perf = 0; 
		totl = 0;
		ID = _i;
	}
	void AddScore(int _i,int _s)
	{
		if(_s != -1 && !isSummited) 
		{
			isSummited = true;

		}
		if(_s == -1) score[_i] = 0;
		if(_s > score[_i])
		{
			if(score[_i] != -1)
				totl -= score[_i];
			score[_i] = _s;
			totl += _s;
		}
		if(score[_i] == p[_i]) perf++;
	}
};
Person person[100000];
bool cmp(const Person &lhs,const Person &rhs)
{
	if(lhs.totl != rhs.totl) return lhs.totl > rhs.totl;
	else if(lhs.perf != rhs.perf) return lhs.perf > rhs.perf;
	else return lhs.ID < rhs.ID;
}
int main()
{
#ifdef INPUT
	freopen("C:\\Users\\xuzhong\\Desktop\\pat\\input\\1075. PAT Judge (25).txt","r",stdin);
#endif
	while (scanf("%d%d%d",&N,&K,&M) != EOF)
	{
		for(int i = 1;i <= N;i++)
			person[i].init(i);
		p[0] = 0;
		for(int i = 1;i <= K;i++)
			scanf("%d",p + i);
		for(int i = 0;i != M;i++)
		{
			scanf("%d%d%d",&x,&y,&z);
			person[x].AddScore(y,z);
//			printf("%05d %d %d %d %d\n",person[x].ID,person[i].score[1],person[i].score[2],person[i].score[3],person[i].score[4]);
		}
		sort(person + 1,person + N + 1,cmp);
		int ranks = 1;
		int rranks = 1;
		int sscore = person[1].totl;
		for(auto i = 1; person[i].isSummited; i++)
		{
			if(person[i].totl < sscore) {ranks = rranks;sscore = person[i].totl;}
			printf("%d %05d %d",ranks,person[i].ID,person[i].totl);
			for(auto j = 1;j <= K;j++)
			{
				if(person[i].score[j] == -1)
					printf(" -" );
				else printf(" %d",person[i].score[j]);
			}
			printf("\n");
			rranks++;
		}
	}
#ifdef INPUT
	while(1){}
	fclose(stdin);
#endif
}
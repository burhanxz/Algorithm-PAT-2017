#include <set>
#include <iostream>
#include <iomanip>
//#define INPUT
using namespace std;
set<int>S[50];
int N,M,x,K;
int a,b;
int Nc,Nt;
int main()
{
#ifdef INPUT
	freopen("C:\\Users\\xuzhong\\Desktop\\pat\\input\\1063. Set Similarity (25).txt","r",stdin);
#endif
	while (scanf("%d",&N) != EOF)
	{
		for(int i = 0;i != N;i++)
		{
			scanf("%d",&M);
			S[i].clear();
			for(int j = 0;j != M;j++)
			{
				scanf("%d",&x);
				S[i].insert(x);
			}
		}
		scanf("%d",&K);
		for(int i = 0;i != K;i++)
		{
			scanf("%d%d",&a,&b);
			a--;b--;
			int c = S[a].size() > S[b].size() ? b : a;
			int d = S[a].size() <= S[b].size() ? b : a;
			Nt = S[d].size();
			Nc = 0;
			set<int>::iterator iter;
			for(iter = S[c].begin();iter != S[c].end();iter++)
			{
				if(S[d].find(*iter) != S[d].end()) Nc++;
				else Nt++;
			}
			float y = Nc * 1.0 / Nt * 100.0;
			y = ((int)(y * 10 + 0.5)) / 10.0;
			printf("%.1f%%\n",y);
		}
		
	}
#ifdef INPUT
	while(1){}
	fclose(stdin);
#endif
}
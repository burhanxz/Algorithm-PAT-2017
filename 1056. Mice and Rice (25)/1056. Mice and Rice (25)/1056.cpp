#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
//#define INPUT
using namespace std;
int w[1000];
int order[1000];
int ranked[1000];
int NP,NG;
list<int>L[1000];

int main()
{
#ifdef INPUT
	freopen("C:\\Users\\xuzhong\\Desktop\\pat\\input\\1056. Mice and Rice (25).txt","r",stdin);
#endif
	while (scanf("%d%d",&NP,&NG) != EOF)
	{
		
		for(int i = 0;i != NP;i++) L[i].clear();
		for(int i = 0;i != NP;i++)
			scanf("%d",w + i);
		for(int i = 0;i != NP;i++)
		{
			scanf("%d",order + i);
			L[0].push_back(order[i]);
		}
		int n = 0;
		while (L[n].size() != 1)
		{
			list<int>::iterator iter = L[n].begin();
			list<int>::iterator iter1,iter2;
			int maxW;
			bool isEnd = false;
			while (1)
			{
				iter1 = iter;	
				for(int i = 1; i <= NG;i++)
				{
					iter1++; 
					if(iter1 == L[n].end()) {isEnd = true;break;}
				}
				maxW = 0;
				for(iter2 = iter;iter2 != iter1;iter2++)
				{
					if(w[*iter2] >= maxW) 
					{
						maxW = w[*iter2];
						iter = iter2;
					}
				}

				L[n + 1].push_back(*iter);
				L[n].erase(iter);
				iter = iter1;
				if(isEnd) break;
			}
			n++;
		}
//		cout << "n=" << n << endl;
		ranked[L[n].front()] = 1;
		int sum = 1;
		for(int i = n - 1;i >= 0;i--)
		{
			for(list<int>::iterator iter = L[i].begin();iter != L[i].end();iter++)
			{
				ranked[*iter] = sum + 1;
			}
			sum += L[i].size();
		}
		printf("%d",ranked[0]);
		for(int i = 1;i != NP;i++)
			printf(" %d",ranked[i]);
		printf("\n");
	}
#ifdef INPUT
	while(1){}
	fclose(stdin);
#endif
}
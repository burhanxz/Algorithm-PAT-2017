#include <map>
#include <cstdio>
#include <set>
#include <utility>
#include <cmath>
#define INPUT
using namespace std;
int N,K;
int x,ranks;
map<int,int>iMap;
set<int>S;
bool isPrime(int x)
{
	if(x == 1) return false;
	int maxi = (int)sqrt(x * 1.0) + 1;
	for(int i = 2;i <= maxi;i++)
	{
		if(x % i == 0) return false;
	}
	return true;
}
int main()
{
#ifdef INPUT
	freopen("C:\\Users\\xuzhong\\Desktop\\pat\\input\\1116. Come on! Let's C (20).txt","r",stdin);
#endif
	while (scanf("%d", &N) != EOF)
	{
		iMap.clear();
		S.clear();
		for(int i = 1;i <= N;i++)
		{
			scanf("%d",&x);
			iMap.insert(make_pair(x,i));
		}
		scanf("%d",&K);
		for(int i = 0;i != K;i++)
		{
			scanf("%d",&x);
			if(!iMap.count(x))
			{
				printf("%04d: Are you kidding?\n",x);
				continue;
			}
			if(!S.count(x))
			{
				S.insert(x);
				if(iMap[x] == 1) 
				{
					printf("%04d: Mystery Award\n",x);
				}
				else if(isPrime(iMap[x]))
				{
					printf("%04d: Minion\n",x);
				}
				else 
					printf("%04d: Chocolate\n",x);
			}
			else
			{
				printf("%04d: Checked\n",x);
			}
		}
	}
#ifdef INPUT
	while(1){}
	fclose(stdin);
#endif
}
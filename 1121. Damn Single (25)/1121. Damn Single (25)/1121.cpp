#include <iostream>
#include <set>
#include <cstring>
#define INPUT
using namespace std;
const int maxn = 100000;
set<int>S,ans;
int N,M;
int arr[maxn];
int x,y;
int main()
{
#ifdef INPUT
	freopen("C:\\Users\\xuzhong\\Desktop\\pat\\input\\1121. Damn Single (25).txt","r",stdin);
#endif
	while (scanf("%d",&N) != EOF)
	{
		memset(arr,-1,sizeof(arr));
		S.clear();
		ans.clear();
		for(int i = 0;i != N;i++)
		{
			scanf("%d%d",&x,&y);
			arr[x] = y;
			arr[y] = x;
		}
		scanf("%d",&M);
		for(int i = 0;i != M;i++)
		{
			scanf("%d",&x);
			S.insert(x);
		}
		for(auto iter = S.begin();iter != S.end();iter++)
		{
			if(arr[*iter] == -1 || !S.count(arr[*iter]))
				ans.insert(*iter);
		}
		printf("%d\n",ans.size());
		if(!ans.empty())
		{
			for(auto iter = ans.begin();iter != ans.end();iter++)
			{
				if(iter == ans.begin()) printf("%05d",*iter);
				else printf(" %05d",*iter);
			}
			printf("\n");
		}
	}
#ifdef INPUT
	while(1){}
	fclose(stdin);
#endif
}
#include <iostream>
#include <string.h>
#include<stdlib.h>
#include <stdio.h>
/*#define INPUT*/
using namespace std;
const int SIZE = 100000 + 5;
int d[SIZE];
int c[SIZE];
int N,M;
int u,v;
int S;
int a;
int findPath(int x,int y)
{
	int u = min(x,y);
	int v = max(x,y);
	int sum1,sum2;
	sum1 = sum2 = 0;
	sum1 = c[v] - c[u];
// 	for(int i = u;i != v;i++)
// 		sum1 += d[i];
	sum2 = S - sum1;
// 	for(int i = 1;i != u;i++)
// 		sum2 += d[i];
// 	for(int i = v;i <= N;i++)
// 		sum2 += d[i];
	return min(sum1,sum2);
}
int main()
{
#ifdef INPUT
	freopen("C:\\Users\\xuzhong\\Desktop\\pat\\input\\1046. Shortest Distance (20).txt","r",stdin);
#endif
	while(scanf("%d",&N) != EOF)
	{
		S = 0;
		c[1] = 0;
		for (int i = 1;i <= N;i++)
		{
			scanf("%d",&a);
			S += a;
			d[i] = a;
			c[i + 1] = c[i] + d[i];
		}
			
		scanf("%d",&M);
		for (int i = 0;i != M;i++)
		{
			scanf("%d%d",&u,&v);
			cout << findPath(u,v) << endl;
		}
	}
#ifdef INPUT
	while (1){}
	fclose(stdin);
#endif
}
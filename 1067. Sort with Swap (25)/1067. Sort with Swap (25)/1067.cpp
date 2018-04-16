#include <cstdio>
#include <memory.h>
using namespace std;
//#define INPUT
int arr[100005];
int order[100005];
int N;
int x;

void _swap(int x,int y)
{
	int temp;
	temp = arr[x];
	arr[x] = arr[y];
	arr[y] = temp;
	order[arr[y]] = y;
	order[arr[x]] = x;
}
int is_not(int y)
{
	if(arr[0] != 0) return 1;
	else
		for(int i = y;i != N;i++)if(arr[i] != i) return i;
	return 0;
}
int main()
{
#ifdef INPUT
	freopen("C:\\Users\\xuzhong\\Desktop\\pat\\input\\1067. Sort with Swap (25).txt","r",stdin);
#endif
	while (scanf("%d",&N) != EOF)
	{
		for(int i = 0; i != N;i++)
		{
			scanf("%d",arr + i);
			order[arr[i]] = i;
		}
		x = 0;
		int y = 1;
		while (y)
		{
			if(order[0] != 0) 
			{
				_swap(order[0],order[order[0]]);
				x++;
			}
			else 
			{
				_swap(order[0],y);
				x++;
			}
			y = is_not(y);
// 			for(int i = 0;i != N;i++) cout <<  arr[i] <<" ";
// 			cout << endl;
		}
			
		printf("%d\n",x);
	}
#ifdef INPUT
	while(1){}
	fclose(stdin);
#endif
}
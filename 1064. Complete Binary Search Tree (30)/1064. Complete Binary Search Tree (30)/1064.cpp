#include <iostream>
#include <algorithm>
//#define INPUT
using namespace std;
int arr[1000];
int bst[1000];
int N;
void in_order(int n)
{
	static int x = 1;
	if(n <= N)
	{
		in_order(n * 2);
		bst[n] = arr[x++];//对完全二叉搜索树的中序遍历顺序和上升子序列的顺序一致
		in_order(n * 2 + 1);
	}
}
int main()
{
#ifdef INPUT
	freopen("C:\\Users\\xuzhong\\Desktop\\pat\\input\\1064. Complete Binary Search Tree (30).txt","r",stdin);
#endif
	while(scanf("%d",&N) != EOF)
	{
		for(int i = 1;i <= N;i++)
			scanf("%d",arr + i);
		sort(arr + 1,arr + N + 1);
		in_order(1);
		printf("%d",bst[1]);
		for(int i = 2;i <= N;i++)
			printf(" %d",bst[i]);
		printf("\n");
	}
#ifdef INPUT
	while(1){}
	fclose(stdin);
#endif
}
#include <iostream>
#include <algorithm>
//#define INPUT
using namespace std;
long long arr[100001];
long long p;
int N;
int len,maxL;
int main()
{
#ifdef INPUT
	freopen("C:\\Users\\xuzhong\\Desktop\\pat\\input\\1085. Perfect Sequence (25).txt","r",stdin);
#endif
	while (scanf("%d%ld",&N,&p) != EOF)
	{
		for(auto i = 0;i != N;i++)
		{
			scanf("%ld",arr + i);
		}
		sort(arr,arr + N);
		size_t left = 0;
		size_t right = 0;
		len =  maxL =0;
		for(;right != N;right++)
		{
			if(arr[right] <= p * arr[left]) 
			{
				len = right - left + 1;
				maxL = max(len,maxL);
				continue;
			}
			else
				for(;left != right;left++)
				{
					if(arr[right] <= p * arr[left])
					{
						len = right - left + 1;
						maxL = max(len,maxL);
						break;
					}
				}
		}
		printf("%d\n",maxL);
	}
#ifdef INPUT
	while(1){}
	fclose(stdin);
#endif
}
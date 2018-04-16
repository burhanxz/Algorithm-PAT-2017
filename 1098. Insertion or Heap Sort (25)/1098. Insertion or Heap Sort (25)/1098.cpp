#include <cstdio>
#include <vector>
#include <algorithm>
#define INPUT
using namespace std;
int arr[101],arr1[101];
int temp[101];
int N;
bool isSort(int data[],int a,int b)
{
	for(int i = a;i != b;i++) temp[i] = data[i];
	sort(temp + a,temp + b);
	for(int i = a;i != b;i++)
	{
		if(temp[i] != data[i])
			return false;
	}
	return true;
}
int main()
{
#ifdef INPUT
	freopen("C:\\Users\\xuzhong\\Desktop\\pat\\input\\1098. Insertion or Heap Sort (25).txt","r",stdin);
#endif
	scanf("%d",&N);
	for(int i = 0;i != N;i++)
		scanf("%d",arr + i);
	for(int i = 0;i != N;i++)
		scanf("%d",arr1 + i);
	int maxi;
	for(int i = 0;i != N;i++)
	{
		if(!isSort(arr1,0,i))
		{
			maxi = i;
			break;
		}
	}
	bool isInsertion = true;
	for(int i = maxi;i != N;i++)
	{
		if(arr1[i] != arr[i])
		{
			isInsertion = false;
			break;
		}
	}
	if(isInsertion)
	{
		printf("Insertion Sort\n");
		sort(arr1,arr1 + maxi + 1);
		for(int i = 0;i != N;i++)
		{
			if(i == 0) printf("%d",arr1[i]);
			else printf(" %d",arr1[i]);
		}
		printf("\n");
	}
	else
	{
		printf("Heap Sort\n");
		make_heap(arr,arr + N);
		bool ok = true;
		int _N = N;
		while (_N)
		{
			pop_heap(arr,arr + _N);
			_N--;
			ok = true;
// 			for(int i = 0;i != N;i++)
// 			{
// 				if(i == 0) printf("%d",arr[i]);
// 				else printf(" %d",arr[i]);
// 			}
// 			printf("\n");
			for(int i = 0;i != N;i++)
			{
				if(arr[i] != arr1[i])
				{
					ok = false;
					break;
				}
			}
			if(ok) 
			{
				pop_heap(arr,arr + _N);
				for(int i = 0;i != N;i++)
				{
					if(i == 0) printf("%d",arr[i]);
					else printf(" %d",arr[i]);
				}
				printf("\n");
				break;
			}
		}
	}
#ifdef INPUT
	while(1){}
	fclose(stdin);
#endif
	return 0;
}
#include <algorithm>
#include <iostream>
#include <cstring>
#include <memory>
#define INPUT
using namespace std;
int arr[101],arr1[101];
int N;
bool isSorted(int data[],int m,int n)
{
	for(int i = m;i <= n;i++)
	{
		if(i >m)
		{
			if(data[i] < data[i - 1])
				return false;
		}
	}
	return true;
}
int main()
{
#ifdef INPUT
	freopen("C:\\Users\\xuzhong\\Desktop\\pat\\input\\1089. Insert or Merge (25).txt","r",stdin);
#endif
	
	scanf("%d",&N);
	for(int i = 0;i != N;i++)
		scanf("%d",arr + i);
	for(int i = 0;i != N;i++)
		scanf("%d",arr1 + i);
	int maxi = 0;
	for(int i = 1;i != N;i++)
	{
		if(!isSorted(arr1,0,i)) 
		{
			maxi = i;
			break;
		}
	}
	bool ok = true;
	for(int i = maxi;i != N;i++)
	{
		if(arr1[i] != arr[i])
		{
			ok = false;
			break;
		}
	}
	if(ok) 
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
		printf("Merge Sort\n");
		int p,q;
		int len;
		for(int i = 1;i <= N/2;i++)
		{
			p = 0;q = i;
			bool ok = true;
			while (p < N)
			{
				if(q < N)
				{
					if(!isSorted(arr1,p,q))
					{
						ok = false;
						break;
					}
				}
				else
				{
					if(!isSorted(arr1,p,N-1))
					{
						ok = false;
						break;
					}
				}
				p = q + 1;
				q += i + 1;
			}
			if(ok) 
				len = i + 1;
			else break;
		}
		len *= 2;
/*		cout << "len=" <<  len <<endl;*/
		p = 0;q =len;
		while (p < N)
		{
			if(q < N)
				sort(arr1 + p,arr1 + q);
			else
				sort(arr1 + p,arr1 + N);
			p = q;
			q += len;
		}
		for(int i = 0;i != N;i++)
		{
			if(i == 0) printf("%d",arr1[i]);
			else printf(" %d",arr1[i]);
		}
		printf("\n");
	}
#ifdef INPUT
	while(1){}
	fclose(stdin);
#endif
}
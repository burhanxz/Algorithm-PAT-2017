#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>
#include <utility>
#define INPUT
using namespace std;
vector<int> vec;
vector< pair<int,int> > ans;
long int N;
bool isPrime(int x)
{
	if(x == 1) return false;
	int maxi = (int)sqrt(x * 1.0);
	for (int i = 2;i <= maxi;i++)
	{
		if(x % i == 0) return false;
	}
	return true;
}
int main()
{
#ifdef INPUT
	freopen("C:\\Users\\xuzhong\\Desktop\\pat\\input\\1059. Prime Factors (25).txt","r",stdin);
#endif

	scanf("%ld",&N);
	if(N == 1) 
	{
		printf("1=1\n");
		return 0;
	}
	if(isPrime(N))
	{
		printf("%d=%d\n",N,N);
		return 0;
	}
	int maxi = (int)sqrt(N * 1.0);
	for(int i = 2;i <= maxi;i++)
	{
		if(isPrime(i)) vec.push_back(i);
	}
	int n = N;
	for(auto iter = vec.begin();iter != vec.end();)
	{
		int x = *iter;
		if(n % x == 0) ans.push_back(make_pair(x,0));
		while(n % x == 0)
		{
			++ans.back().second;
			n /= x;
		}
		iter++;
	}
	printf("%ld=",N);
	for(auto iter = ans.begin();iter != ans.end();iter++)
	{
		if(iter->second == 1)
		{
			if(iter == ans.begin()) printf("%d",iter->first);
			else printf("*%d",iter->first);
		}
		else 
		{
			if(iter == ans.begin()) printf("%d^%d",iter->first,iter->second);
			else printf("*%d^%d",iter->first,iter->second);
		}
	}
	printf("\n");
	
#ifdef INPUT
	while(1){}
	fclose(stdin);
#endif
	return 0;
}
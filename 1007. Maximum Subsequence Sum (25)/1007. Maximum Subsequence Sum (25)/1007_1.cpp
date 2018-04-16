#include <iostream>
#include <vector>
using namespace std;
int arr[10005];
int dp[10005];
int N;
vector<int>vec;
int DP(int s)
{
	if(s == 0) return dp[0] = arr[0];
	return dp[s] = max(DP(s - 1) + arr[s],arr[s]);
}
int main()
{
	scanf("%d",&N);
	for(int i = 0;i != N;i++)
		scanf("%d",arr + i);
	DP(N - 1);
	int maxDp = 0;
	int maxi = 0;
	for(int i = 0;i != N;i++)
	{
		if(dp[i] > maxDp)
		{
			maxDp = dp[i];
			maxi = i;
		}
	}
	for(int i = maxi;i >= 0;i--)
	{
		if(arr[i] > 0)
			vec.push_back(arr[i]);
	}
	printf("%d %d %d\n",maxDp,vec.back(),vec.front());
	system("pause");
}

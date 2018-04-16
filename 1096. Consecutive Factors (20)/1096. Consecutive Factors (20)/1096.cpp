#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
vector<int>vec[100];
const int INF = (1 << 31) - 1;
int N;
bool isPrime(int x)
{
	if(x == 1) return false;
	if(x == 2 || x == 3) return true;
	int y = (int)sqrt(x * 1.0);
	for(int i = 2;i <= y;i++)
	{
		if(x % i == 0) return false;
	}
	return true;
}
int main()
{
	while (scanf("%d",&N) != EOF)
	{
		for(int i = 0;i != 100;i++)vec[i].clear();
		if(isPrime(N)) 
		{
			printf("1\n");
			printf("%d\n",N);
			continue;
		}
		int maxn = (int)sqrt(N * 1.0) + 1;
//		cout << "maxn=" << maxn << endl;
		int x = 0;
		int last = 0;
		int _N = N;
		bool ok = false;
		for(int i = 2;i <= maxn;i++)
		{
			if(_N % i == 0) 
			{
				_N /= i;
				if(last == 0)
				{
					last = i;
					ok = true;
				}
				else 
				{
					if(ok) 
						vec[x].push_back(last);
					ok = false;
					vec[x].push_back(i);
					last = i;
				}
			}
			else 
			{
				_N = N;
				last = 0;
				if(!vec[x].empty())
					x++;
			}
		}
		if(vec[0].empty())
		{
			for(int i = 2;i <= maxn;i++)
			{
				if(N % i == 0)
				{
					printf("1\n");
					printf("%d\n",i);
					break;
				}
			}
			continue;
		}
		int maxL = 0;
		int maxX = 0;
		for(int i = 0;i != x;i++)
		{
			if(vec[i].size() > maxL)
			{
				maxL = vec[i].size();
				maxX = i;
			}
		}
		printf("%d\n",maxL);
		printf("%d",vec[maxX][0]);
		for(int i = 1;i < maxL;i++)
		{
			printf("*%d",vec[maxX][i]);
		}
		printf("\n");
	}
}
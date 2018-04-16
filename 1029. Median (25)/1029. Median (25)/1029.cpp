#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <vector>
//#define INPUT
using namespace std;
vector<long int>vec;
int N,M;
long int x;
int main()
{
#ifdef INPUT
	freopen("C:\\Users\\xuzhong\\Desktop\\pat\\input\\1029. Median (25).txt","r",stdin);
#endif
	while(cin >> N)
	{
		for(int i = 0;i != N;i++)
		{
			scanf("%ld",&x);
			vec.push_back(x);
		}	
		cin >> M;
		for (int i = N + 0;i != N + M;i++)
		{
			scanf("%ld",&x);
			vec.push_back(x);
		}
		sort(vec.begin(),vec.end());
		cout << vec[(vec.size()-1)/2] <<endl;
	}
#ifdef INPUT
	while(1){}
	fclose(stdin);
#endif
}
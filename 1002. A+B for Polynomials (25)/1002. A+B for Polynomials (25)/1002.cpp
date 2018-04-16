#include <iostream>
#include <iomanip>
#include <algorithm>
#include <iomanip>
#include <cstring>
#include <map>
using namespace std;
int K;
float n1[1001];
float n2[1001];
float n3[1001];
int main()
{
	while (cin >> K)
	{
		memset(n1,0,sizeof(n1));
		memset(n2,0,sizeof(n2));
		memset(n3,0,sizeof(n3));
		for(int i = 0;i != K; i++)
		{
			int _n;
			float _a;
			cin >> _n >> _a;
			n1[_n] = _a;
		}
		cin >> K;
		for(int i = 0;i != K; i++)
		{
			int _n;
			float _a;
			cin >> _n >> _a;
			n2[_n] = _a;
		}
		int sum = 0;
		int maxK = 0;
		for (int i = 0;i != 1001;i++)
		{
			n3[i] = n1[i] + n2[i];
			if(n3[i] != 0) {sum++;maxK = i;}
		}
		cout<< sum;
		for (int i = maxK;i >= 0;i--)
		{
			if(n3[i])
			{
				float _a = n3[i];
				if(_a > 0) _a = (int)(_a * 10 + 0.5) / 10.0;
				else _a = (int)(_a * 10 - 0.5) / 10.0;          //注意！！正负数的四舍五入是不同的
				cout<<" "<< i << " ";
				cout<< setiosflags(ios::fixed) << setprecision(1) << _a;
			}
		}
		cout << endl;
	}
}

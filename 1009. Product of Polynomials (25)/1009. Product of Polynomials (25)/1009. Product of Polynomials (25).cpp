#include<iostream>
#include <cstring>
using namespace std;
float p1[1001];
float p2[1001];
float p[2002];
int main()
{
	int k;
	int a,maxn;float b;
	while (cin >> k)
	{
		for (int i = 0; i <= 1000 ; i++)
		{
			p1[i] = 0.0;p2[i] = 0.0; 
		}
		for (int i = 0; i <= 2001 ; i++)
		{
			p[i] = 0.0; 
		}
		maxn = 0;

		for (int i = 0;i != k;i++)
		{
			cin >> a >> b;
			p1[a] = b;
		}
		cin >> k;
		for (int i = 0;i != k;i++)
		{
			cin >> a >> b;
			p2[a] = b;
		}
		// ‰»Î
		for (int i = 0; i <= 1000;i++)
			for(int j = 0; j <= 1000;j++)
			{
				p[i + j] += p1[i] * p2[j];
				if(p[i + j] != 0.0)maxn = ((i + j) > maxn ? (i + j):maxn);
			}
// 		for (int i = 0;i != 10;i++)
// 		{
// 			cout << "p="<<p[i]<<","<< "p1="<<p1[i]<<","<< "p2="<<p2[i]<<endl;
// 		}
		int sum = 0;
		for (int i = maxn; i >= 0; i--) if(p[i] != 0) sum++;
		cout << sum;
		for (int i = maxn; i >= 0; i--)
		{
			if(p[i] != 0)
			{
				int x=p[i] ;
				if(x - p[i] == 0)cout << " " << i << " " << p[i]<<".0"; 
				else cout << " " << i << " " << p[i]; 
			}
				
		}
		cout << endl;
	}
}
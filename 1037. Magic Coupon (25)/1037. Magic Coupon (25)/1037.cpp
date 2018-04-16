#include <iostream>
#include <algorithm>
// #define DEBUG
// #define INPUT
using namespace std;
const int SIZE = 100000 + 5;
int NC,NP;
int c[SIZE];
int p[SIZE];
int sum;
int main()
{
#ifdef INPUT
	freopen("C:\\Users\\xuzhong\\Desktop\\pat\\input\\1037. Magic Coupon (25).txt","r",stdin);
#endif	
	while (cin >> NC)
	{
		sum = 0;
		for(int i = 0;i != NC;i++)
		{
			cin >> c[i];
		}
		cin >> NP;
		for(int i = 0;i != NP;i++)
		{
			cin >> p[i];
		}
		sort(c,c + NC);
		sort(p,p + NP);
		for(int i = 0,j = 0;i != NC,j != NP;i++,j++)
		{
			if(c[i] >= 0 || p[j] >= 0) break;
			if(c[i] < 0 && p[j] < 0) sum += c[i] * p[j];
		}
		for(int i = NC - 1,j = NP - 1;i >= 0,j >= 0;i--,j--)
		{
			if(c[i] <= 0 || p[j] <= 0) break;
			if(c[i] > 0 && p[j] > 0) sum += c[i] * p[j];
		}
		cout << sum << endl;
	}
#ifdef INPUT
	while (1){}
	fclose(stdin);
#endif
}
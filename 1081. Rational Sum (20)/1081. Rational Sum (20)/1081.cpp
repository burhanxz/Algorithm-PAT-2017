#include <iostream>
#include <string>
#include <sstream>
#include <cmath>
//#define INPUT
using namespace std;
int N;
int nume[101];
int deno[101];
char ch[100];
string s;
stringstream ss;
int gcd(int a,int b)
{
	int x = min(a,b);
	int y = max(a,b);
	int z;
	while (1)
	{
		z = y % x;
		if(z == 0) return x;
		else 
		{
			y = x;
			x = z;
		}
	}
}
int main()
{
#ifdef INPUT
	freopen("C:\\Users\\xuzhong\\Desktop\\pat\\input\\1081. Rational Sum (20).txt","r",stdin);
#endif
	while (cin >> N)
	{
		for(int i = 0;i != N;i++)
		{
			int x,y;
			cin >> s;
			auto pos = s.find('/');
			ss << string(s.begin(),s.begin() + pos);ss >> x;ss.clear();ss.str("");
			nume[i] = x;
			ss << string(s.begin() + pos + 1,s.end());ss >> y;ss.clear();ss.str("");
			deno[i] = y;
		}
		int sum  = 1,num = 0;
		for(int i = 0;i != N;i++)
			sum *= deno[i];
		for(int i = 0;i != N;i++)
		{
			nume[i] *= (sum / deno[i]);
			num += nume[i];
		}
// 		for(int i = 0;i != N;i++)
// 		{
// 			printf("%d/%d ",nume[i],deno[i]);
// 		}
// 		printf("\n");
		if(abs(num) % sum == 0) {printf("%d\n",num / sum);continue;}
		int _gcd = gcd(abs(num),sum);
		num /= _gcd;
		sum /= _gcd;
		if(abs(num) < sum) 
		{
			printf("%d/%d\n",num,sum);
		}
		else
		{
			int x;
			printf("%d ",num / sum);
			x = abs(num) % sum;
			printf("%d/%d\n",x,sum);
		}
	}
#ifdef INPUT
	while(1){}
	fclose(stdin);
#endif
}
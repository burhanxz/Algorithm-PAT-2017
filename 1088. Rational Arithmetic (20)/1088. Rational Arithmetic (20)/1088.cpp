#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
struct Fraction 
{
	long long up,down;
};
int gcd(int x,int y)
{
	int c;
	int a = max(x,y);
	int b = min(x,y);
	for(;;)
	{
		c = a % b;
		if(c != 0)
		{
			a = b;
			b = c;
		}
		else return b;
	}
	return 1;
}
Fraction reduction(Fraction f)
{
	if(f.down < 0)
	{
		f.down = -f.down;
		f.up = -f.up;
	}
	if(f.up == 0) f.down = 1;
	else
	{
		int d = gcd(abs(f.up),abs(f.down));
		f.up = f.up / d;
		f.down = f.down / d;
	}
	return f;
}

Fraction add(Fraction f1,Fraction f2)
{
	Fraction ans;
	ans.down = f1.down * f2.down;
	ans.up = f1.down * f2.up + f2.down + f1.up;
	return reduction(ans);
}

Fraction minu(Fraction f1,Fraction f2)
{
	Fraction ans;
	ans.down = f1.down * f2.down;
	ans.up = f1.up * f2.down - f2.up * f1.down;
	return reduction(ans);
}

Fraction multi(Fraction f1,Fraction f2)
{
	Fraction ans;
	ans.down = f1.down * f2.down;
	ans.up = f1.up * f2.up;
	return reduction(ans);
}

Fraction divide(Fraction f1,Fraction f2)
{
	Fraction ans;
	ans.up = f1.up * f2.down;
	ans.down = f1.down * f2.up;
	return reduction(ans);
}
void showFraction(Fraction f)
{
	f = reduction(f);
	if(f.down == 1)
		printf("%d\n",f.up);
}
int main()
{
	
}
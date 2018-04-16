#include <string>
#include <cstring>
#include <iostream>
#include <stdio.h>
#define INPUT
#define DEBUG
using namespace std;
int N;
int k,n;
string s;
int main()
{
#ifdef INPUT
	freopen("C:\\Users\\xuzhong\\Desktop\\pat\\input\\1031. Hello World for U (20).txt","r",stdin);
#endif
	while (getline(cin,s))
	{
		if(s.length() > 80 || s.length() < 5 || s.find(" ") != s.npos)continue;
		int N = s.length() - 2;
		int maxk = 0;
		for(int i = 3;i <= N;i++)
		{
			if((N+2-i)%2==0 && i >= (N+2-i)/2)
				maxk = max(maxk,(N+2-i)/2);
		}
		n = N + 2 - 2 * maxk;
		k = maxk;
#ifdef DEBUG
		cout<<"length=" << s.length() << endl;
		cout << "maxk=" << maxk << endl;
		cout << "n=" << n << endl;
#endif
		for(int i = 0;i != k;i++)
		{
			cout << s[i];
			for(int j = 0;j != n - 2;j++)cout << " ";
			cout << s[N + 1 - i] << endl;
		}
		string _s(s.begin()+k,s.begin()+k+n);
		cout << _s << endl;
	}
#ifdef INPUT
	while (1){}
	fclose(stdin);
#endif
}
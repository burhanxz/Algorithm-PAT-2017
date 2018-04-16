#include <iostream>
#include <sstream>
#include <string>
#include <cstring>
/*#define DEBUG*/
using namespace std;
stringstream ss;
string s;
int a[10];
int b[10];
int c[20];
int d[21];
int main()
{
	while (getline(cin, s))
	{
		memset(a,0,sizeof(a));
		memset(b,0,sizeof(b));
		memset(c,0,sizeof(c));
		memset(d,0,sizeof(d));
		int temp;
		int maxn = s.size() - 1;
		for (int i = maxn;i >= 0;i--)
		{
			ss << s[i];ss >> temp;ss.clear();ss.str("");
			c[i] = temp;
			a[temp]++;
		}          
		for(int i = maxn; i >= 0;i--)
		{
			int x = c[i];
			x *= 2;
			if(x >= 10) {d[i + 1] += (x - 10);d[i]++;}
			else d[i + 1] += x;
		}
		s.clear();
		char ch;
		for(int i = 0; i <= maxn + 1; i++)
		{
			if(i == 0 && d[0] == 0) continue;
			ss << d[i];ss >> ch;ss.clear();ss.str("");
			s.push_back(ch);
		}
		for (int i = s.size() - 1;i >= 0;i--)
		{
			ss << s[i];ss >> temp;ss.clear();ss.str("");
			b[temp]++;
		} 
#ifdef DEBUG
		for(int i = 0; i != 10;i++) cout << "a["<<i<<"]="<<a[i]<<", "<<"b["<<i<<"]="<<b[i]<<endl;
#endif
		bool ok = true;
		for(int i = 0; i != 10;i++)
		{
			if(a[i] != b[i]) {ok = false;break;}
		}
		if(ok) cout << "Yes" << endl;
		else cout << "No" << endl;
		cout << s << endl;
		s.clear();
	}
}
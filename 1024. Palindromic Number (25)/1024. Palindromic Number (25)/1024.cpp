#include <iostream>
#include <algorithm>
#include <sstream>
#include <string>
#include <cstring>
/*#define DEBUG*/
using namespace std;
int K;
string s;
stringstream ss;
bool isPalindromic(string s)
{
	string _s(s);
	reverse(_s.begin(),_s.end());
	bool is = true;
	for(int i = 0;i != s.size(); i++)
	{
		if(s[i] != _s[i]) {is = false;break;}
	}
	return is;
}
string add(string s)
{
	string _s(s);
	reverse(_s.begin(),_s.end());
	string s1;
	int t1,t2,t,ca = 0;
	char ch;
	for(int i = s.size() - 1;i >= 0;i--)
	{
		ss << s[i];ss >> t1;ss.clear();ss.str("");
		ss << _s[i];ss >> t2;ss.clear();ss.str("");
		if(ca) t = t1 + t2 + 1;
		else t = t1 + t2;
		if(t >= 10) 
		{
			ca = 1;
			ss << (t - 10);ss >> ch;ss.clear();ss.str("");
		}
		else 
		{
			ca = 0;
			ss << t;ss >> ch;ss.clear();ss.str("");
		}
		s1.push_back(ch);
	}
	if(ca) s1.push_back('1');
	reverse(s1.begin(),s1.end());

	return s1;
}
int main()
{
	while (getline(cin,s,' '))
	{
		cin >> K;
		int times = 0;
		if(isPalindromic(s)) {cout << s << endl;cout << times;}
		else
		{
			for(int i = 1; i <= K;i++)
			{
				s = add(s);
				cout << "i="<< i << " ,s=" << s << endl;
				times = i;
				if(isPalindromic(s)) break;
			}
			cout << s << endl;cout << times << endl;
			s.clear();
		}
	}
}
#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <cstring>
#include <cctype>
using namespace std;
map<char,int>Map1;
map<char,int>Map2;
string s1,s2;
string s;
int main()
{
	while (cin >> s1)
	{
		s.clear();
		Map1.clear();
		Map2.clear();
		cin >> s2;
		for(auto i = 0;i != s2.size();i++)
			Map1[s2[i]] = 1;
		for(auto i = 0;i != s1.size();i++)
		{
			if(!Map1.count(s1[i]))
			{
				auto c = s1[i];
				if(isalpha(c)) c = toupper(c);
				if(!Map2.count(c))
				{
					s.push_back(c);
					Map2[c] = 1;
				}
			}
		}
		cout << s << endl;
	}
}
#include <string>
#include <cstring>
#include <cctype>
#include <iostream>
#include <map>
#include <algorithm>
#include <utility>
#include <vector>
//#define INPUT
using namespace std;
string s;
string _s;
bool cmp(const pair<string,int> &lhs,const pair<string,int> &rhs)
{
	if(lhs.second != rhs.second) return lhs.second > rhs.second;
	else return lhs.first < rhs.first;
}
map<string,int>Map;
vector<pair<string,int>>vec;
int main()
{
#ifdef INPUT
	freopen("C:\\Users\\xuzhong\\Desktop\\pat\\input\\1071. Speech Patterns (25).txt","r",stdin);
#endif
	while (getline(cin,s))
	{
		Map.clear();
		s += " ";
		for(auto i = 0;i != s.size();i++)
		{
			auto c = s[i];
			if(!isalpha(c) && !isdigit(c)) 
			{
				if(!_s.empty()) 
				{
					auto ret = Map.insert(make_pair(_s,1));
					if(!ret.second)
						++ret.first->second;
				}	
				_s.clear();
				continue;
			}
			else 
			{
				if(isalpha(c)) c = tolower(c);
				_s.push_back(c);
			}
		}
//		if(Map.empty()) printf("\n");
		for(auto iter = Map.begin();iter != Map.end();iter++)
		{
			vec.push_back(make_pair(iter->first,iter->second));
//			cout << "s:" << iter->first << "  num:" << iter->second << endl;
		}
		sort(vec.begin(),vec.end(),cmp);
		printf("%s %d\n",vec[0].first.c_str(),vec[0].second);
	}
#ifdef INPUT
	while(1){}
	fclose(stdin);
#endif
}
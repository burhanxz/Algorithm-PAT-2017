#include <stack>
#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
#include <sstream>
//#define INPUT
using namespace std;
stack<char>S;
stringstream ss;
string s;
string ans;
char sign1,sign2;
int move_char;
int main()
{
#ifdef INPUT
	freopen("C:\\Users\\xuzhong\\Desktop\\pat\\input\\1073. Scientific Notation (20).txt","r",stdin);
#endif
	while (getline(cin,s))
	{
		auto pos = s.rfind('E');
		sign1 = s[0];
		sign2 = s[pos + 1];
		ss << string(s.begin() + pos + 2,s.end());
		ss >> move_char;
		ss.str("");
		for(auto i = pos - 1;i >= 1;i--)
			S.push(s[i]);
		if(sign1 == '-') ans.push_back(sign1);
		if(sign2 == '+')
		{
			auto x = 1;
			auto ok = false;
			ans.push_back(S.top());S.pop();S.pop();
			while (!S.empty())
			{
				if(x - 1 == move_char)
				{
					ans.push_back('.');
					ok = true;
				}
				auto c = S.top();S.pop();
				ans.push_back(c);
				x++;
			}
			if(!ok)
				while (x - 1 < move_char)
				{
					ans.push_back('0');
					x++;
				}
		}
		if(sign2 == '-')
		{
			ans.append("0.");
			for(auto i = 0;i != move_char - 1;i++)
				ans.push_back('0');
			ans.push_back(S.top());S.pop();S.pop();
			while (!S.empty())
			{
				auto c = S.top();S.pop();
				ans.push_back(c);
			}
		}
		printf("%s\n",ans.c_str());
	}
#ifdef INPUT
	while(1){}
	fclose(stdin);
#endif
}
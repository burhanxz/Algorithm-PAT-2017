#include <string>
#include <sstream>
#include <iostream>
#include <vector>
//#define INPUT
using namespace std;
string NUM[10] = {"ling","yi","er","san","si","wu","liu","qi","ba","jiu"};
string WEI[8] = {"Yi","Qian","Bai","Shi","Wan","Qian","Bai","Shi"};
stringstream ss;
string s;
vector<string>vec;
int main()
{
#ifdef INPUT
	freopen("C:\\Users\\xuzhong\\Desktop\\pat\\input\\1082. Read Number in Chinese (25).txt","r",stdin);
#endif
	while (cin >> s)
	{
		if(s == "0") 
		{
			cout << "ling" << endl;
			continue;
		}
		vec.clear();
		if(s[0] == '-') 
		{
			vec.push_back("Fu");
			string _s(s.begin() + 1,s.end());
			s = _s;
		}
		int x;
		for(int i = 9 - s.size(),j = 0;j != s.size();i++,j++)
		{
			ss << s[j];ss >> x;ss.clear();ss.str("");
			bool ok = true;
			if(x == 0)
			{
				ok = false;
				for (auto pos = j + 1;(s.size() - pos) % 4 != 0;pos++)
				{
					if(s[pos] != '0') ok = true;
				}
			}
			if(ok) vec.push_back(NUM[x]);
			if((x != 0 || i == 0 || i == 4) && (i != 8))
			{
				vec.push_back(WEI[i]);
			}
		}
// 		ss << s.back();ss >> x;ss.clear();ss.str("");
// 		if(x != 0) vec.push_back(NUM[x]);
		string last = vec.front();
		for(auto iter = vec.begin();iter != vec.end();iter++)
		{
			if(iter == vec.begin()) cout << *iter;
			else
			{
				if(!(*iter == "ling" && last == "ling") && !(*iter == "Wan" && last == "Yi")) 
					cout << " " << *iter ;
			}
			last = *iter;	
		}
		cout << endl;
	}
#ifdef INPUT
	while(1){}
	fclose(stdin);
#endif
}
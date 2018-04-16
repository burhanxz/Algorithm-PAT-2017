#include <set>
#include <sstream>
#include <string>
#include <iostream>
using namespace std;
string s;
stringstream ss;
int N;
int x,sum;
set<int>S;
int main()
{
	while (cin >> N)
	{
		S.clear();
		for(int i = 0;i != N;i++)
		{
			cin >> s;
			sum = 0;
			for(int j = 0;j != s.size();j++)
			{
				ss << s[j];ss >> x;ss.clear();ss.str("");
				sum += x;
			}
			S.insert(sum);
		}
		cout << S.size() << endl;
		for(auto iter = S.begin();iter != S.end();iter++)
		{
			if(iter == S.begin()) cout << *iter;
			else cout << " " << *iter;
		}
		cout << endl;
	}
}
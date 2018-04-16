#include <cstring>
#include <iostream>
#include <sstream>
#include <algorithm>
using namespace std;
int main()
{
	string s,s1;
	stringstream ss;
	int a ,b;
	while(getline(cin,s))
	{
		string num1(s.begin() , s.begin()+s.find(" "));
		string num2(s.begin() + s.find(" ") + 1, s.end());
		ss.str(num1);ss >> a;ss.clear();ss.str("");
		ss.str(num2);ss >> b;ss.clear();ss.str("");
		int c = a + b;
		ss << c;ss >> s;ss.clear();ss.str("");

//		cout << s << endl;

		for (int i = s.size() - 1,n = 0; i != -1; --i)
		{
			++n;
			s1.push_back(s[i]);
			if(n % 3 == 0 && i != 0 && ((i == 1 && s[0] != '-')||(i >= 2))) s1.push_back(',');
//			cout << s1 << endl;
		}
		reverse(s1.begin(),s1.end());
		cout << s1 << endl;
		s.clear();
		s1.clear();
		a = 0;
		b = 0;
	}
	

	system("pause");
}
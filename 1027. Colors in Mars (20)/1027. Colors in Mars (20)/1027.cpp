#include <iostream>
#include <sstream>
#include <algorithm>
#include <stdio.h>
//#define INPUT
using namespace std;
string convert_to_13(int x)
{
	string s;
	stringstream ss;
	int c;
	char ch;
	int y = x;
	while (y)
	{
		c = y % 13;
		y = y / 13;
		if(c == 10) s.push_back('A');
		else if(c == 11) s.push_back('B');
		else if(c == 12) s.push_back('C');
		else 
		{
			ss << c;ss >> ch;ss.clear();ss.str("");
			s.push_back(ch);
		}	
	}
	if(x < 13 && x != 0) s.push_back('0');
	else if(!x) {s.push_back('0');s.push_back('0');}
	reverse(s.begin(),s.end());
	return s;
}
int a,b,c;
int main()
{
#ifdef INPUT
	freopen("C:\\Users\\xuzhong\\Desktop\\pat\\input\\1027. Colors in Mars (20).txt","r",stdin);
#endif
	while (cin >> a >> b >> c)
	{
		cout << "#" << convert_to_13(a) << convert_to_13(b) << convert_to_13(c) << endl;
	}
#ifdef INPUT
	while (1){}
	fclose(stdin);
#endif
}
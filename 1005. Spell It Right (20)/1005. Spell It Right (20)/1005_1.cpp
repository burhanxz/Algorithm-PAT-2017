#include <iostream>
#include<cstring>
#include <sstream>
using namespace std;
void print_s(int a)
{
	switch(a)
	{
		case 0:cout<<"zero";break;
		case 1:cout<<"one";break;
		case 2:cout<<"two";break;
		case 3:cout<<"three";break;
		case 4:cout<<"four";break;
		case 5:cout<<"five";break;
		case 6:cout<<"six";break;
		case 7:cout<<"seven";break;
		case 8:cout<<"eight";break;
		case 9:cout<<"nine";break;
	}
}
int main()
{
	stringstream ss;
	string s;
	int a,sum;
	while (getline(cin,s))
	{
		sum = 0;
		for (int i = 0;i != s.size(); i++)
		{
			ss << s[i];ss >> a;ss.clear();ss.str("");
			sum += a;
		}
		s.clear();
		ss << sum;ss >> s;ss.clear();ss.str("");
		for (int i = 0; i != s.size(); i++)
		{
			ss << s[i];ss >> a;ss.clear();ss.str("");
			if(i != 0)cout<<" ";
			print_s(a);
		}
		cout<<endl;
		s.clear();
	}
}
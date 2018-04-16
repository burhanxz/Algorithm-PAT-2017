#include <iostream>
#include <cmath>
#include <cstring>
#include <string>
#include <sstream>
#include <algorithm>
using namespace std;
int N,D;
bool isPrime(int a)
{
	if(a == 0 || a == 1 || a == 2) return false;
	for (int i = 2;i < sqrt((double)a);i++)
	{
		if(a % i == 0)return false;
	}
	return true;
}
int conv(int a,int b)
{
	stringstream ss;
	string s;
	char ch;
	int c;
	while(a)
	{
		c = a % b;
		a = a / b;
		ss << c;ss>>ch;ss.clear();ss.str("");
		s.push_back(ch);
	}
	int ans = 0;
	for (int i = s.size() - 1,j = 0; i >= 0; i--,j++)
	{
		ss << s[i];ss >> c;ss.clear();ss.str("");
		ans += c * (int)pow(b*1.0,j);
	}
	return ans;
}
int main()
{
	
	while (cin >> N)
	{
		if(N >= 0) 
		{
			cin >> D;
			if (isPrime(N) && isPrime(conv(N,D)))
			{
				cout << "Yes" <<endl;
			}
			else cout << "No" << endl;//´íÔÚ°ÉYesÐ´³ÉYES£¬NoÐ´³ÉNO¡£¡£

		}
		
	}
}
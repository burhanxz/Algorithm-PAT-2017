#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
// #define INPUT
// #define DEBUG
using namespace std;
string s;
int maxL;
int isSymmetric(int left,int right)
{
	string s1(s.begin() + left,s.begin() + right + 1);
	string s2(s1);
	reverse(s2.begin(),s2.end());
#ifdef DEBUG
	cout << "s1=" << s1 << "," << "s2=" << s2 << endl;
#endif
	if(s1 == s2) return right - left + 1;
	else return 0;
}
int main()
{
#ifdef INPUT
	freopen("C:\\Users\\xuzhong\\Desktop\\pat\\input\\1040. Longest Symmetric String (25).txt","r",stdin);
#endif
	while (getline(cin,s))
	{
		maxL = 0;
		for(int i = 0;i != s.size();i++)
		{
			for (int j = i;j != s.size();j++)
			{
				int _is = isSymmetric(i,j);
				 maxL = max(maxL,_is);
			}
		}
		cout << maxL << endl;
	}
#ifdef INPUT
	while(1){}
	fclose(stdin);
#endif
}
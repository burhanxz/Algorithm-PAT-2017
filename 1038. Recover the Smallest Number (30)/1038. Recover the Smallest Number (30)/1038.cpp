#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <stdlib.h>
// #define INPUT
// #define DEBUG
using namespace std;
vector<string> vec;
int N;
string s;
bool cmp(const string &lhs,const string &rhs)
{
	string s1 = lhs + rhs;
	string s2 = rhs + lhs;
	return s1 < s2;
}
int main()
{
#ifdef INPUT
	freopen("C:\\Users\\xuzhong\\Desktop\\pat\\input\\1038. Recover the Smallest Number (30).txt","r",stdin);
#endif
	while(cin >> N)
	{
		vec.clear();
		for(int i = 0;i != N;i++)
		{
			cin >> s;
			vec.push_back(s);
		}
		sort(vec.begin(),vec.end(),cmp);

		int n;//��¼��һ�����㴮��λ��
		for(n = 0;n != vec.size();n++)
		{
			int a = atoi(vec[n].c_str());
			if(a != 0) break;
		}
		if(n == vec.size()) {cout << "0" << endl;continue;} //�����㴮

		int pos;//��¼��һ�����㴮�ĵ�һ������λ
		for(pos = 0;pos != vec[n].size();pos++)
		{
			if(vec[n][pos] != '0') break; 
		}
		string sn(vec[n].begin() + pos,vec[n].end());

		for(int i = n;i != vec.size();i++)
		{
			if(i == n) cout << sn;
			else cout << vec[i];
		}
		cout << endl;
	}
#ifdef INPUT
	while(1){}
	fclose(stdin);
#endif
}
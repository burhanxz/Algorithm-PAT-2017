#include <iostream>
#include<string>
#include <utility>
#include <vector>
// #define INPUT
// #define DEBUG
using namespace std;
int N;
string s1,s2;
vector< pair<string,string> >vec;
vector<int> outputI;
int num;
bool modify(string &s)
{
	bool isModified = false;
	for (int i = 0; i != s.size();i++)
	{
		switch(s[i])
		{
			case '1':s[i] = '@';isModified = true;
				break;
			case '0':s[i] = '%';isModified = true;
				break;
			case 'l':s[i] = 'L';isModified = true;
				break;
			case 'O':s[i] = 'o';isModified = true;
				break;
		}
	}
	return isModified;
}
int main()
{
#ifdef INPUT
	freopen("C:\\Users\\xuzhong\\Desktop\\pat\\input\\1035. Password (20).txt","r",stdin);
#endif
	while(cin >> N)
	{
		vec.clear();
		outputI.clear();
		if (N == 1)
		{
			cout << "There is 1 account and no account is modified" << endl;
			continue;
		}
		for(int i = 0;i != N;i++)
		{
			cin >> s1 >> s2;
			vec.push_back(pair<string,string>(s1,s2));
		}
		num = 0;
		for (int i = 0;i != vec.size();i++)
		{
			if(modify(vec[i].second)) 
			{
				num++;
				outputI.push_back(i);
			}
		}
		if(!num) {cout << "There are "<< vec.size() <<" accounts and no account is modified" << endl;continue;}
		cout << num << endl;
		for(int i = 0;i != outputI.size();i++)
		{
			int u = outputI[i];
			cout << vec[u].first << " " << vec[u].second << endl;
		}
	}
#ifdef INPUT
	while(1){}
	fclose(stdin);
#endif
}
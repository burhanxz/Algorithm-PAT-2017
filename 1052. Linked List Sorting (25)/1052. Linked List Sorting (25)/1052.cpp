#include <iostream>
#include <utility>
#include <vector>
#include <string>
#include <algorithm>
#include <sstream>
//#define INPUT
using namespace std;
int N;
int x;
string s1,s2,s;
int ad,nx,fs;
vector< pair<string,int> >vec;

bool cmp(const pair<string,int> &lhs,const pair<string,int> &rhs)
{
	return lhs.second < rhs.second;
}
struct Node
{
	int data;
	int next;
};
Node link_list[100000];
string valid(int n)
{
	stringstream ss;
	string s;
	if(n > 9999) {ss << n;ss >> s;ss.clear();ss.str("");return s;}
	else 
	{
		ss << n;ss >> s;ss.clear();ss.str("");
		reverse(s.begin(),s.end());
		while (s.size() < 5)
		{
			s.push_back('0');
		}
		reverse(s.begin(),s.end());
		return s;
	}
}
int main()
{
#ifdef INPUT
	freopen("C:\\Users\\xuzhong\\Desktop\\pat\\input\\1052. Linked List Sorting (25).txt","r",stdin);
#endif
	while (cin >> N >> fs)
	{
		vec.clear();
		for(int i = 0;i != N;i++)
		{
			cin >> ad >> x >> nx;
			link_list[ad].data = x;
			link_list[ad].next = nx;
		}
		int x = fs;
		while (x != -1)
		{
			vec.push_back(pair<string,int>(valid(x),link_list[x].data));
			x = link_list[x].next;
		}


		sort(vec.begin(),vec.end(),cmp);
		vector< pair<string,int> >::iterator iter = vec.begin();
		if(vec.size() == 0){cout << "0 -1" << endl;continue;}
		cout << vec.size() << " " <<iter->first << endl;
		while((iter + 1) != vec.end())
		{
			cout << iter->first << " " << iter->second << " " << (iter + 1)->first << endl;
			iter++;
		}
		cout << iter->first << " " << iter->second << " -1" << endl;
	}
#ifdef INPUT
	while(1){}
	fclose(stdin);
#endif
}
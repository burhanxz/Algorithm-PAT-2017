#include <string>
#include <iostream>
#include <algorithm>
#include <vector>
//#define INPUT
using namespace std;
struct Person
{
	string name;
	string ID;
	int grade;
	Person(string _name,string _id,int _g):name(_name),ID(_id),grade(_g){}
};
int N;
int g1,g2;
string _n[10000],_i[10000];
int _g[10000];
vector<Person>vec;
bool cmp(const Person &lhs,const Person &rhs)
{
	return lhs.grade > rhs.grade;
}
int main()
{
#ifdef INPUT
	freopen("C:\\Users\\xuzhong\\Desktop\\pat\\input\\1083. List Grades (25).txt","r",stdin);
#endif
	while(cin >> N)
	{
		for(int i = 0;i != N;i++)
			cin >> _n[i] >> _i[i] >> _g[i];
		cin >> g1 >> g2;
		for(int i = 0;i != N;i++)
		{
			if(_g[i] >= g1 && _g[i] <= g2)
			{
				vec.push_back(Person(_n[i],_i[i],_g[i]));
			}
		}
		if(vec.empty())
		{
			cout << "NONE" << endl;
			continue;
		}
		sort(vec.begin(),vec.end(),cmp);
		for(auto iter = vec.begin();iter != vec.end();iter++)
		{
			cout << iter->name << " " << iter->ID << endl;
		}
	}
#ifdef INPUT
	while(1){}
	fclose(stdin);
#endif
}
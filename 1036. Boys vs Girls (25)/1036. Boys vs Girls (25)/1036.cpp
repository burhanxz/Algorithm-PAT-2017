#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
// #define INPUT
// #define DEBUG
using namespace std;
int N;
string s1,s2;
char ch;
int g;
struct Person
{
	string name;
	char gender;
	string ID;
	int grade;
	Person(string _name,char _gender,string _ID,int _grade):
	name(_name),gender(_gender),ID(_ID),grade(_grade){}
};
bool cmp(const Person &lhs,const Person &rhs)
{
	return lhs.grade < rhs.grade;
}
vector<Person>male;
vector<Person>female;
int main()
{
#ifdef INPUT
	freopen("C:\\Users\\xuzhong\\Desktop\\pat\\input\\1036. Boys vs Girls (25).txt","r",stdin);
#endif
	while (cin >> N)
	{
		for(int i = 0; i != N;i++)
		{
			cin >> s1 >> ch >> s2 >> g;
			if(ch == 'M') male.push_back(Person(s1,ch,s2,g));
			else if(ch = 'F') female.push_back(Person(s1,ch,s2,g));
		}
		sort(male.begin(),male.end(),cmp);
		sort(female.begin(),female.end(),cmp);
		int g1,g2;

		if(!female.size()) cout << "Absent" << endl;
		else 
		{
			vector<Person>::iterator iter = female.end() - 1;
			g2 = iter->grade;
			cout << iter->name << " " << iter->ID << endl;
		}

		if(!male.size()) cout << "Absent" << endl;
		else 
		{
			g1 = male[0].grade;
			cout << male[0].name << " " << male[0].ID << endl;
		}

		if(!male.size() || !female.size()) cout << "NA" << endl; 
		else cout << g2 - g1 << endl;
	}
#ifdef INPUT
	while(1){}
	fclose(stdin);
#endif
}
#include <iostream>
#include <algorithm>
#include <string>
#include <sstream>
#include <vector>
#include <stdio.h>
//#define INPUT
using namespace std;
int N,C;
string s;
stringstream ss;
struct Student
{
	string ID;
	string name;
	int grade;
	Student(string id,string _name,int _grade):ID(id),name(_name),grade(_grade){}
};
bool cmp1(const Student &lhs,const Student &rhs)
{
	return lhs.ID < rhs.ID;
}
bool cmp2(const Student &lhs,const Student &rhs)
{
	if(lhs.name != rhs.name) return lhs.name < rhs.name;
	else return lhs.ID < rhs.ID;
}
bool cmp3(const Student &lhs,const Student &rhs)
{
	if(lhs.grade != rhs.grade) return lhs.grade < rhs.grade;
	else return lhs.ID < rhs.ID;
}
vector<Student>student_list;
int main()
{
#ifdef INPUT
	freopen("C:\\Users\\xuzhong\\Desktop\\pat\\input\\1028. List Sorting (25).txt","r",stdin);
#endif
	while (getline(cin,s,' '))
	{
		student_list.clear();
		ss << s;ss >> N;ss.clear();ss.str("");
		getline(cin, s);
		ss << s;ss >> C;ss.clear();ss.str("");
		for(int i = 0;i != N;i++)
		{
			getline(cin,s);
			string::size_type pos = s.rfind(" ");
			int _grade;
			ss << string(s.begin()+pos+1,s.end());ss >> _grade;ss.clear();ss.str("");
			student_list.push_back(Student(string(s.begin(),s.begin()+6), string(s.begin()+7,s.begin()+pos), _grade));
		}
		switch(C)
		{
			case 1:
				{
					sort(student_list.begin(),student_list.end(),cmp1);
					for(int i = 0;i != N;i++)
						cout << student_list[i].ID << " " <<student_list[i].name << " " << student_list[i].grade << endl;
				}break;
			case 2:
				{
					sort(student_list.begin(),student_list.end(),cmp2);
					for(int i = 0;i != N;i++)
						cout << student_list[i].ID << " " <<student_list[i].name << " " << student_list[i].grade << endl;
				}break;
			case 3:
				{
					sort(student_list.begin(),student_list.end(),cmp3);
					for(int i = 0;i != N;i++)
						cout << student_list[i].ID << " " <<student_list[i].name << " " << student_list[i].grade << endl;
				}break;
		}
	}
#ifdef INPUT
	while (1){}
	fclose(stdin);
#endif
}
#include <iostream>
#include <sstream>
#include <cstring>
#include<vector>
#include <algorithm>
using namespace std;
struct Time
{
	int hh,mm,ss;
	Time(int HH, int MM,int SS):hh(HH),mm(MM),ss(SS){}
};
struct  Rec
{
	string id;
	Time in;
	Time out;
	Rec(string a,Time t1,Time t2):id(a),in(t1),out(t2){}
};
int _min(int lhs,int rhs){return lhs < rhs ? lhs : rhs;}
int _max(int lhs,int rhs){return lhs > rhs ? lhs : rhs;}
bool cmp1(const Rec &r1,const Rec &r2)
{
	if (_min(r1.in.hh,r1.out.hh) == _min(r2.in.hh,r2.out.hh))
	{
		if (_min(r1.in.mm,r1.out.mm) == _min(r2.in.mm,r2.out.mm))
		{
			return _min(r1.in.ss,r1.out.ss) < _min(r2.in.ss,r2.out.ss);
		}
		else
		{
			return _min(r1.in.mm,r1.out.mm) < _min(r2.in.mm,r2.out.mm);
		}
	} 
	else
	{
		return _min(r1.in.hh,r1.out.hh) < _min(r2.in.hh,r2.out.hh);
	}
}
bool cmp2(const Rec &r1,const Rec &r2)
{
	if (_max(r1.in.hh,r1.out.hh) == _max(r2.in.hh,r2.out.hh))
	{
		if (_max(r1.in.mm,r1.out.mm) == _max(r2.in.mm,r2.out.mm))
		{
			return _max(r1.in.ss,r1.out.ss) > _max(r2.in.ss,r2.out.ss);
		}
		else
		{
			return _max(r1.in.mm,r1.out.mm) > _max(r2.in.mm,r2.out.mm);
		}
	} 
	else
	{
		return _max(r1.in.hh,r1.out.hh) > _max(r2.in.hh,r2.out.hh);
	}
}
vector<Rec> recs;
int main()
{
	string s0,s1,s2;
	stringstream ss;
	int n;
	int HH,MM,SS;
	while (cin >> n)
	{
		s0.clear();s1.clear();s2.clear();recs.clear();
		for (int i = 0; i != n; i++)
		{
			getline(cin,s0,' ');                                              
			if(s0[0] == '\n') {string s(s0.begin() + 1,s0.end());s0 = s;}      //小心换行符会输入进字符串！大坑
			getline(cin,s1,' ');
			getline(cin,s2);
			ss << string(s1.begin(),s1.begin()+2);ss >> HH;ss.clear();ss.str("");
			ss << string(s1.begin()+3,s1.begin()+5);ss >> MM;ss.clear();ss.str("");
			ss << string(s1.begin()+6,s1.end());ss >> SS;ss.clear();ss.str("");
			Time t1(HH,MM,SS);
			ss << string(s2.begin(),s2.begin()+2);ss >> HH;ss.clear();ss.str("");
			ss << string(s2.begin()+3,s2.begin()+5);ss >> MM;ss.clear();ss.str("");
			ss << string(s2.begin()+6,s2.end());ss >> SS;ss.clear();ss.str("");
			Time t2(HH,MM,SS);
			recs.push_back(Rec(s0,t1,t2));
		}
	/*	if(n == 1) {string s = recs[0].id; cout << s << " "<< s0 << endl;}*/
			sort(recs.begin(),recs.end(),cmp1);
			cout << recs[0].id << " ";
			sort(recs.begin(),recs.end(),cmp2);
			cout << recs[0].id << endl;
	}
}
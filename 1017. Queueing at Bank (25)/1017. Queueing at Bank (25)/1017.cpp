#include <iostream>
#include<queue>
#include<cstring>
#include <sstream>
#include<string>
using namespace std;
int N,K;
int a,b,c,d;
string s;
stringstream ss;
struct Time
{
	int hh,mm,ss;
	Time(int HH,int MM,int SS):hh(HH),mm(MM),ss(SS){}
	Time& operator=(const Time &t)
	{
		hh = t.hh;
		mm = t.mm;
		ss = t.ss;
	}
	Time& operator++()
	{
		this->ss ++;
		if(this->ss >= 60) {this->mm++;this->ss -= 60;}
		if(this->mm >= 60) {this->hh++;this->mm -= 60;}
		return *this;
	}
};
bool operator<(const Time &lhs,const Time &rhs)
{
	if (lhs.hh == rhs.hh)
	{
		if(lhs.mm == rhs.mm) return lhs.ss < rhs.hh;
		else return lhs.mm < rhs.mm;
	}
	else return lhs.hh < rhs.hh;
}
Time& operator+(const Time &lhs,int minutes)
{
	int m = lhs.mm + minutes, h=lhs.hh;
	m = m % 60;
	h += m / 60;
	return Time(h,m,0);
}
Time& operator-(const Time &lhs,const Time &rhs)
{
	int h,m,s;
	int hh1 = lhs.hh, hh2 = rhs.hh, mm1 = lhs.mm, mm2 = rhs.mm, ss1 = lhs.ss, ss2 = rhs.ss;
	if(ss1 < ss2){s = ss1 + 60 - ss2;mm1--;}else s = ss1 - ss2;
	if(mm1 < mm2){m = mm1 + 60 - mm2;hh1--;}else m = mm1 - mm2;
	h = hh1 - hh2;
	return Time(h,m,s);
}
struct Person
{
	Time arriveTime;
	int spend;
	int used;
	float waitTime;
	Person(int HH,int MM,int SS,int sp):arriveTime(Time(HH,MM,SS)),spend(sp)
	{
		used = 0;
		waitTime = 0.0;
	}
// 	wait = hh * 60 + mm + ss / 60.0;
// 	wait = (int)(wait * 10 + 0.5)/10.0;
};

queue<Person> p;
vector<Person> w;
int main()
{
	while (cin >> N >> K)
	{
		for(int i = 0;i != N;i++)
		{
			getline(cin, s, ' ');
			ss << string(s.begin(), s.begin() + 2);ss >> a;ss.clear();ss.str("");
			ss << string(s.begin() + 3, s.begin() + 5);ss >> b;ss.clear();ss.str("");
			ss << string(s.begin() + 6, s.end());ss >> c;ss.clear();ss.str("");
			cin >> d;
			p.push(Person(a,b,c,d));
		}
		Time endTime(17,0,1);
		for(int i = 0; i != K; i++)
		{
			if (!p.empty())
			{
				Person _p = p.front();
				p.pop();
				w.push_back(_p);
			}
		}
		for (Time time(8,0,0);time < endTime; time++ )
		{
			for (int i = 0;i != K; i++)
			{

			}
		}
	}
}
#include<iostream>
#include<string>
#include <sstream>
#include <cstring>
#include<utility>
#include<map>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <stdio.h>
//#define DEBUG
//#define INPUT
using namespace std;
double cost[24];
int N;
struct Time 
{
	int mo,dd,hh,mm;
	int state;
	Time(int MO,int DD,int HH,int MM,string s):mo(MO),dd(DD),hh(HH),mm(MM)
	{
		if (s == "on-line")//开始为0状态
		{
			state = 0;
		}
		else if (s == "off-line")//挂断为1状态
		{
			state = 1;
		}
		else state = -1;
	}
	Time(string s)
	{
		stringstream ss;
		int _a;
		ss << string(s.begin(),s.begin() + 2); ss >> _a;ss.clear();ss.str("");mo = _a;//cout << "mo=" << mo << endl;
		ss << string(s.begin() + 3,s.begin() + 5);ss >> _a;ss.clear();ss.str("");dd = _a;//cout << "dd=" << dd << endl;
		ss << string(s.begin() + 6,s.begin() + 8);ss >> _a;ss.clear();ss.str("");hh = _a;//cout << "hh=" << hh << endl;
		ss << string(s.begin() + 9,s.begin() + 11);ss >> _a;ss.clear();ss.str("");mm = _a;//cout << "mm=" << mm << endl;
		string _s(s.begin() + 12, s.end()); //cout << _s << endl;
		if (_s == "on-line")//开始为0状态
		{
			state = 0;
		}
		else if (_s == "off-line")//挂断为1状态
		{
			state = 1;
		}
		else state = -1;
	}
	string timeString()//生成时间字符串
	{
		string _s;
		string _s1;
		stringstream ss;
		ss << dd;if(dd < 10) _s = _s + "0";ss >> _s1;_s = _s + _s1;_s1.clear();ss.clear();ss.str("");
		_s = _s + ":";
		ss << hh;if(hh < 10) _s = _s + "0";ss >> _s1;_s = _s + _s1;_s1.clear();ss.clear();ss.str("");
		_s = _s + ":";
		ss << mm;if(mm < 10) _s = _s + "0";ss >> _s1;_s = _s + _s1;_s1.clear();ss.clear();ss.str("");
		return _s;
	}
};

bool cmpTime(const Time &t1,const Time &t2)//时间升序排序
{
	if(t1.dd != t2.dd) return t1.dd < t2.dd; 
	else if (t1.hh != t2.hh )
	{
		return t1.hh < t2.hh;
	}
	else return t1.mm < t2.mm;
}//continue


double CountCost(pair<Time,Time>_p)//计算总费用
{
	double h1 = _p.first.dd * 24 + _p.first.hh + _p.first.mm / 60.0;
	double h2 = _p.second.dd * 24 + _p.second.hh + _p.second.mm / 60.0;
	int startT = (int)(h1 + 1);
	int endT = (int)h2;
	double sum = 0.0;
	sum += (startT - h1) * cost[(int)h1 % 24] * 0.6;
	sum += (h2 - endT) * cost[(int)h2 % 24] * 0.6;
	for(int i = startT;i != endT;i++)
	{
		sum += cost[i % 24] * 0.6;
	}
	return sum;
}
int CountMinute(pair<Time,Time>_p)//计算总分钟
{
	int dM = _p.second.mm - _p.first.mm;
	int dH = _p.second.hh - _p.first.hh;
	int dD = _p.second.dd - _p.first.dd;
	if(dM < 0){dM += 60;dH--;}
	if(dH < 0){dH += 24;dD--;}
	return dM + dH * 60 + dD * 1440;
}//continue
struct Person 
{
	string name;//唯一标识符：姓名
	vector<Time> T;//存储全部时间
	vector< pair<Time,Time> > P;//存储成对的开始-挂断时间 
	Person(string _s):name(_s)
	{
		P.clear();
		T.clear();
	}
	void AddTime(Time _t) //添加输入的时间到特定的人
	{
		T.push_back(_t);
	}
	void verifyTime()//把全部时间修正为成对的开始-挂断时间并存储
	{
		sort(T.begin(),T.end(),cmpTime);
		int maxI = T.size() - 1;
		for(int i = 0; i < maxI; i++)
		{
			if(T[i].state == 0 && T[i + 1].state == 1)
			{
				P.push_back( pair<Time,Time>(T[i],T[i + 1]) );
				i++;
			}
		}
	}
	void output()//对每个人，实现一次完整输出
	{
		cout << name << " " ;
		int _month = T[0].mo;
		if(_month >= 10) cout << _month << endl;
		else cout << "0" << _month << endl;
		if(P.size())
		{
			double sum = 0.0;
			for(int i = 0; i != P.size();i++)
			{
				cout << P[i].first.timeString() <<" "
					<< P[i].second.timeString() <<" "
					<< CountMinute(P[i]) << " ";
				double _cost = CountCost(P[i]);
				sum += _cost;
				_cost = (int)(_cost * 100 + 0.5) / 100.0;
				cout << "$" << setiosflags(ios::fixed) << setprecision(2) << _cost << endl;
			}
			sum = (int)(sum * 100 + 0.5) / 100.0;
			cout << "Total amount: $"<< setiosflags(ios::fixed) << setprecision(2) << sum << endl;
		}
		else cout << "Total amount: $00.00" << endl;
	}

};
bool operator==(const Person &lhs,const Person &rhs)
{
	return lhs.name == rhs.name;
}
bool cmpName(const Person &lhs,const Person &rhs)
{
	return lhs.name < rhs.name;
}

vector<Person> person;
string inputString;
string inputName;
int main()
{
#ifdef INPUT
	freopen("E:\\1016_Phone Bills (25).txt","r",stdin);
#endif
	while (cin >> cost[0] >> cost[1] >> cost[2] >> cost[3] >> cost[4] >> cost[5] >>
		 cost[6] >> cost[7] >> cost[8] >> cost[9] >> cost[10] >> cost[11] >> cost[12] >>
		  cost[13] >> cost[14] >> cost[15] >> cost[16] >> cost[17] >> cost[18] >> cost[19] >>
		   cost[20] >> cost[21] >> cost[22] >> cost[23])
	{
		person.clear();
		cin >> N;
		for(int i = 0;i != N;i++)
		{
			getline(cin,inputName,' ');
			if(inputName[0] == '\n') {string _inputName(inputName.begin() + 1,inputName.end());inputName = _inputName;}
			if( find(person.begin(),person.end(),Person(inputName)) == person.end()) person.push_back(Person(inputName));
			getline(cin,inputString);
			vector<Person>::iterator iter = find(person.begin(),person.end(),Person(inputName));
			if(iter == person.end())cout << "error" << endl;
			iter->AddTime(Time(inputString));
			inputString.clear();inputName.clear();
		}
		sort(person.begin(),person.end(),cmpName);
		for(int i = 0;i != person.size();i++)
		{
			person[i].verifyTime();
			person[i].output();
		}
	}
#ifdef INPUT
	while(1){}
	fclose(stdin);
#endif
}
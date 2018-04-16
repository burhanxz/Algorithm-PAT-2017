#include <map>
#include <vector>
#include <algorithm>
#include <string>
#include <iostream>
#include <utility>
#include <cstring>
#define INPUT
using namespace std;
int N,K;
char plate[20];
char state[5];
int H,M,S;
struct Car
{
	bool in;
	int t1,t2;
	vector<pair<int,int>>rec;
	int len;
	Car()
	{
		in = false;
		rec.clear();
		len = 0;
	}
	void AddTime(int _t,int _st)
	{
		if(_st == 0) 
		{
			in = true;
			t1 = _t;
		}
		else if(_st == 1)
		{
			if(in)
			{
				t2 = _t;
				rec.push_back(make_pair(t1,t2));
				in = false;
				len += t2 - t1;
			}
		}
	}
	void output()
	{
		for(auto iter = rec.begin();iter != rec.end();iter++)
			cout << iter->first << " " << iter->second << endl;
	}
	Car& operator=(const Car &rhs)
	{
		in = rhs.in;
		len = rhs.len;
		rec = rhs.rec;
		return *this;
	}
};
struct Record
{
	char p[20];
	int st;
	int t;
	Record(char *_p,int _t,char *_st)
	{
		strcpy(p,_p);
		if(_st[0] == 'i') st = 0;
		else if(_st[0] == 'o') st = 1;
		t = _t;
	}
};
vector<Record>vec;
vector<Car>ans;
map<string,Car>iMap;
int main()
{
#ifdef INPUT
	freopen("C:\\Users\\xuzhong\\Desktop\\pat\\input\\1095. Cars on Campus (30).txt","r",stdin);
#endif
	while (scanf("%d%d",&N,&K) != EOF)
	{
		for(int i = 0;i != N;i++)
		{
			scanf("%s %d:%d:%d %s",plate,&H,&M,&S,state);
			vec.push_back(Record(plate,H * 60 * 60 + M * 60 + S,state));
			if(!iMap.count(string(plate)) )
			{
				iMap.insert(make_pair(string(plate),Car()));
			}
		}
		sort(vec.begin(),vec.end(),
			[](const Record &lhs,const Record &rhs)->bool{return lhs.t < rhs.t;});
		for(auto iter = vec.begin();iter != vec.end();iter++)
		{
			string s(iter->p);
//			cout << "check: "<< s << " " << iter->t <<  " " << iter->st << endl;
			iMap[s].AddTime(iter->t,iter->st);
			//iMap[iter->p].output();
		}
		for(int i = 0;i != K;i++)
		{
			scanf("%d:%d:%d",&H,&M,&S);
			int time = H * 3600 + M * 60 + S;
			int n = 0;
			for(auto iter = iMap.begin();iter != iMap.end();iter++)
			{
				for(auto iter1 = (iter->second).rec.begin();iter1 != (iter->second).rec.end();iter1++)
				{
					if(iter1->first <= time && iter1->second > time)
					{
						n++;
						break;
					}
				}
			}
			printf("%d\n",n);
		}
		for(auto iter = iMap.begin();iter != iMap.end();iter++) 
		{
			ans.push_back(iter->second);
		}
		sort(ans.begin(),ans.end(),
			[](const Car &lhs,const Car &rhs)->bool{return lhs.len > rhs.len;});
		int maxL = ans.front().len;
		int n = 0;
		for(auto iter = iMap.begin();iter != iMap.end();iter++)
		{
			if(iter->second.len == maxL)
				printf("%s ",iter->first.c_str());
		}
		int x,y,z;
		x = maxL / 3600;
		maxL %= 3600;
		y = maxL / 60;
		z = maxL % 60;
		printf("%02d:%02d:%02d\n",x,y,z);
	}
#ifdef INPUT
	while(1){}
	fclose(stdin);
#endif
}
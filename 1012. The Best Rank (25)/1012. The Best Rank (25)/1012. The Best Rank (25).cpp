#include <iostream>
#include <vector>
#include <cstring>
#include <string>
#include <algorithm>
using namespace std;
struct Grade
{
	int c,m,e,a,id;
	Grade(int s,int C,int M,int E):id(s),c(C),m(M),e(E){ a = (c + m + e)/3; }
	Grade(int s):id(s){a=c=m=e=0;}
	bool operator==(const Grade &rhs)const
	{
		return id == rhs.id; 
	}
};
bool cmpa(const Grade &lhs,const Grade &rhs){ return lhs.a > rhs.a; }
bool cmpc(const Grade &lhs,const Grade &rhs){ return lhs.c > rhs.c; }
bool cmpm(const Grade &lhs,const Grade &rhs){ return lhs.m > rhs.m; }
bool cmpe(const Grade &lhs,const Grade &rhs){ return lhs.e > rhs.e; }
void print(int a,int b)
{
	switch(a)
	{
		case 0:cout << b << " " << "A" <<endl;break;
		case 1:cout << b << " " << "C" <<endl;break;
		case 2:cout << b << " " << "M" <<endl;break;
		case 3:cout << b << " " << "E" <<endl;break;

	}
}
vector<Grade>grades;
int _id[2001];
int r[4];
int main()
{
	int n,m;
	int _c,_m,_e;
	int _s;
	while (cin >> n >> m)
	{
		memset(_id, 0 ,sizeof(_id));
		memset(r,-1,sizeof(r));

		for (int i = 0; i != n; i++)
		{
			cin >> _s >> _c >> _m >> _e;
			grades.push_back(Grade(_s,_c,_m,_e));
		}
		for (int i = 0; i != m; i++)
		{
			cin >> _id[i];
		}
		// ‰»Î
		for (int i = 0; i != m;i++)
		{
			if(find(grades.begin(), grades.end(),Grade(_id[i])) == grades.end()) cout << "N/A" <<endl;
			else
			{
				sort(grades.begin(), grades.end(),cmpa);
				for(int j = 0; j != grades.size();j++) if( _id[i] == grades[j].id )r[0] = j+1;
				sort(grades.begin(), grades.end(),cmpc);
				for(int j = 0; j != grades.size();j++) if( _id[i] == grades[j].id )r[1] = j+1;
				sort(grades.begin(), grades.end(),cmpm);
				for(int j = 0; j != grades.size();j++) if( _id[i] == grades[j].id )r[2] = j+1;
				sort(grades.begin(), grades.end(),cmpe);
				for(int j = 0; j != grades.size();j++) if( _id[i] == grades[j].id )r[3] = j+1;
				int min_r = n,min_g;
				for(int j = 0; j != 4 ;j++)if(r[j] < min_r){min_r = r[j];min_g = j;}
				print(min_g,min_r);
			}
		}
	}

}
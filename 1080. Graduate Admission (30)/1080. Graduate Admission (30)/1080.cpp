#include <vector>
#include <algorithm>
#include <cstring>
#include <iostream>
//#define INPUT
using namespace std;
int quota[101];
int last_quota[101];//记录上一个录取的学生的排名
vector<int>Admit[40001];
int N,M,K;
int x,y;
struct Person
{
	int grad[5];
	int ID;
	int Ge,Gi;
	float Ga;
	int p;
	int ranks;
	Person(int _ID,int _Ge,int _Gi):ID(_ID),Ge(_Ge),Gi(_Gi)
	{
		Ga = (_Ge + _Gi) / 2.0;
		p = 0; 
	}
	void AddAppl(int x)
	{
		grad[p++] = x;
	}
};
vector<Person>vec;
bool cmp(const Person &lhs,const Person &rhs)
{
	if(lhs.Ga != rhs.Ga) return lhs.Ga > rhs.Ga;
	else return lhs.Ge > rhs.Ge;
}
int main()
{
#ifdef INPUT
	freopen("C:\\Users\\xuzhong\\Desktop\\pat\\input\\1080. Graduate Admission (30).txt","r",stdin);
#endif
	while(scanf("%d%d%d",&N,&M,&K) != EOF)
	{
		vec.clear();
		for(int i = 0;i != M;i++)Admit[i].clear();
		for(auto i = 0;i != M;i++)
		{
			scanf("%d",quota + i);
		}
		for(auto i = 0;i != N;i++)
		{
			scanf("%d%d",&x,&y);
			Person temp(i,x,y);
			for(auto j = 0;j != K;j++)
			{
				scanf("%d",&x);
				temp.AddAppl(x);
			}
			vec.push_back(temp);
		}
		sort(vec.begin(),vec.end(),cmp);
//		cout << "debug" << endl;
		//确定排名
		int _rank = 1;
		int _rrank = 1;
		int _ge = vec.back().Ge;
		int _ga = vec.back().Ga;
		for(auto iter = vec.begin();iter != vec.end();iter++)
		{
			if((iter->Ge < _ge) || (iter->Ge == _ge && iter->Ga < _ga)) 
				_rank = _rrank;
			_rrank++;
			iter->ranks = _rank;
			_ga = iter->Ga;
			_ge = iter->Ge;
		}

		

		for(auto iter = vec.begin();iter != vec.end();iter++)
		{
			for(auto i = 0;i != K;i++)
			{
				auto g = iter->grad[i];
				if(quota[g] > 0)
				{
					Admit[g].push_back(iter->ID);
					--quota[g];
					last_quota[g] = iter->ranks;
					break;
				}
				else if(quota[g] == 0 && iter->ranks == last_quota[g])
				{
					Admit[g].push_back(iter->ID);
					break;
				}
			}
		}
		for(auto i = 0;i != M;i++)
		{
			sort(Admit[i].begin(),Admit[i].end());
			for(auto j = 0;j != Admit[i].size();j++)
			{
				if(j == 0) printf("%d",Admit[i][j]);
				else 
					printf(" %d",Admit[i][j]);
			}
			printf("\n");
		}
	}
#ifdef INPUT
	while(1){}
	fclose(stdin);
#endif
}
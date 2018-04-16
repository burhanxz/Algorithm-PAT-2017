#include <iostream>
#include <algorithm>
#include <vector>
//#define INPUT
using namespace std;
int N;
double D;
double profit;
int x;
double y;
double STOR[1001];
struct Mon
{
	double stor;
	double cost;
	double price;
	Mon(double _stor,double _cost):stor(_stor),cost(_cost)
	{
		price = _cost / _stor;
	}
};
bool cmp(const Mon &lhs,const Mon &rhs)
{
	return lhs.price > rhs.price;
}
vector<Mon>vec;
int main()
{
#ifdef INPUT
	freopen("C:\\Users\\xuzhong\\Desktop\\pat\\input\\1070. Mooncake (25).txt","r",stdin);
#endif
	while (scanf("%d%lf",&N,&D) != EOF)
	{
		for(int i = 0;i != N;i++)
			scanf("%lf",STOR + i);
		
		for(int i = 0;i != N;i++)
		{
			scanf("%lf",&y);
			vec.push_back(Mon(STOR[i],y));
		}
		sort(vec.begin(),vec.end(),cmp);
		profit = 0.0;
// 		cout << "D=" << D << endl;
// 		for(vector<Mon>::iterator iter = vec.begin();iter != vec.end();iter++) cout << iter->stor << "," << iter->cost << "," << iter->price << endl;
		for(vector<Mon>::iterator iter = vec.begin();iter != vec.end();iter++)
		{
			if(iter->stor >= D)
			{
				profit += iter->price * D;
				break;
			}
			else
			{
				D -= iter->stor;
				profit += iter->cost;
			}
		}
		profit = ((int)(profit * 100 + 0.5)) / 100.0;
		printf("%.2f\n",profit);
	}
#ifdef INPUT
	while(1){}
	fclose(stdin);
#endif
}
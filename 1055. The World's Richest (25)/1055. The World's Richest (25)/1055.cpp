#include <vector>
#include <string.h>
#include <algorithm>
#include <iostream>
#include <cmath>
#define INPUT
using namespace std;
int N,K;
int _age,_nw;
char _ch[9];
int M,age1,age2;
struct Person
{
	char name[9];
	int age;
	int nw;
	Person(char *__ch,int __age,int __nw):age(__age),nw(__nw){strcpy(name,__ch);}
};
vector<Person>vec;
bool cmp(const Person &lhs,const Person &rhs)
{
	if(lhs.nw != rhs.nw) 
		return lhs.nw > rhs.nw;
	else if(rhs.age != lhs.age) return lhs.age < rhs.age;
	else return strcmp(lhs.name,rhs.name) < 0;
}
int main()
{
#ifdef INPUT
	freopen("C:\\Users\\xuzhong\\Desktop\\pat\\input\\1055. The World's Richest (25).txt","r",stdin);
#endif
	while (scanf("%d%d",&N,&K) != EOF)
	{				
		vec.clear();
		for(int i = 0;i != N;i++)
		{
			scanf("%s%d%d",_ch,&_age,&_nw);
			if(_age <= 100) vec.push_back(Person(_ch,_age,_nw));
		}
		sort(vec.begin(),vec.end(),cmp);
		for(int i = 0;i != K;i++)
		{
			scanf("%d%d%d",&M,&age1,&age2);
			printf("Case #%d:\n",i + 1);
			vector<Person>::iterator iter = vec.begin();
			int n = 0;
			for (;iter != vec.end() && n < M;iter++)
			{
				if(iter->age >= age1 && iter->age <=age2)
				{
					printf("%s %d %d\n",iter->name,iter->age,iter->nw);
					n++;
				}
			}
			if(n == 0)printf("None\n");
		}
	}
#ifdef INPUT
	while(1){}
	fclose(stdin);
#endif
}
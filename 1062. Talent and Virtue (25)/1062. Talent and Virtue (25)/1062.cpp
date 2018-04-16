#include <iostream>
#include <algorithm>
#include <vector>
#include <string.h>
#define INPUT
using namespace std;
struct Person
{
	char ch[20];
	int v;
	int t;
	Person(char *_ch,int _v,int _t):v(_v),t(_t)
	{
		strcpy(ch,_ch);
	}
};
vector<Person>vec1;
vector<Person>vec2;
vector<Person>vec3;
vector<Person>vec4;
int N,L,H,M;
char x[20];
int y,z;
bool cmp(const Person &lhs,const Person &rhs)
{
	if(lhs.v + lhs.t != rhs.v + rhs.t) return lhs.v + lhs.t > rhs.v + rhs.t;
	else if(lhs.v != rhs.v) return lhs.v > rhs.v;
	else return strcmp(lhs.ch,rhs.ch) < 0;
}
int main()
{
#ifdef INPUT
	freopen("C:\\Users\\xuzhong\\Desktop\\pat\\input\\1062. Talent and Virtue (25).txt","r",stdin);
#endif
	while(scanf("%d%d%d",&N,&L,&H) != EOF)
	{
		M = 0;
		vec1.clear();vec2.clear();vec3.clear();vec4.clear();
		for (int i = 0; i != N;i++)
		{
			scanf("%s %d %d",x,&y,&z);
			if(y >= L && z >= L)
			{
				M++;
				if(y >= H && z >= H) vec1.push_back(Person(x,y,z));
				else if(y >= H && z <= H ) vec2.push_back(Person(x,y,z));
				else if(y <= H && z <= H &&  y >= z) vec3.push_back(Person(x,y,z));
				else vec4.push_back(Person(x,y,z));
			}
		}
		sort(vec1.begin(),vec1.end(),cmp);
		sort(vec2.begin(),vec2.end(),cmp);
		sort(vec3.begin(),vec3.end(),cmp);
		sort(vec4.begin(),vec4.end(),cmp);
		printf("%d\n",M);
//		cout << "rank1:" << endl;
		for(int i = 0;i != vec1.size();i++)
			printf("%s %d %d\n",vec1[i].ch,vec1[i].v,vec1[i].t);
//		cout << "rank2:" << endl;
		for(int i = 0;i != vec2.size();i++)
			printf("%s %d %d\n",vec2[i].ch,vec2[i].v,vec2[i].t);
//		cout << "rank3:" << endl;
		for(int i = 0;i != vec3.size();i++)
			printf("%s %d %d\n",vec3[i].ch,vec3[i].v,vec3[i].t);
//		cout << "rank4:" << endl;
		for(int i = 0;i != vec4.size();i++)
			printf("%s %d %d\n",vec4[i].ch,vec4[i].v,vec4[i].t);
	}
#ifdef INPUT
	while(1){}
	fclose(stdin);
#endif
}
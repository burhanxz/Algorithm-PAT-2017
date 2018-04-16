#include <cstdio>
#include <string.h>
#include <algorithm>
#include <iostream>
#include <sstream>
#include <cstring>
#include <string>
#include <stack>
//#define INPUT
using namespace std;
int N;
int bigNum,smallNum;
stringstream ss;
bool cmp(const char &lhs,const char &rhs)
{
	return lhs > rhs;
}
int lower_n(int N)
{
	char ch[10];
	ss << N;ss >> ch;ss.clear();ss.str("");
	int x = strlen(ch);
	sort(ch,ch + x);
	return atoi(ch);
}
int higher_n(int N)
{
	char ch[10];
	int ans;
	N += 10000;
	for(int i = 0;i != 4;i++)
	{
		ch[i] = N % 10 + '0';
		N /= 10;
	}
	sort(ch,ch + 4,cmp);
	ss << ch;ss >> ans;ss.clear();ss.str("");
	return ans;
}
int main()
{
#ifdef INPUT
	freopen("C:\\Users\\xuzhong\\Desktop\\pat\\input\\1069. The Black Hole of Numbers (20).txt","r",stdin);
#endif
	while (scanf("%d",&N) != EOF)
	{
		for(;;)
		{
			smallNum = lower_n(N);
			bigNum = higher_n(N);
			N = bigNum - smallNum;
			printf("%04d - %04d = %04d\n",bigNum,smallNum,N);
			if(N == 0 || N == 6174) break;
		}
	}
#ifdef INPUT
	while(1){}
	fclose(stdin);
#endif
}
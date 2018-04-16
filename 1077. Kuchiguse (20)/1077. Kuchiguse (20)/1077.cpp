#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <stack>
#define INPUT
using namespace std;
char ch[101][300];
int N;
int min_length;
int _len;
string s;
int main()
{
#ifdef INPUT
	freopen("C:\\Users\\xuzhong\\Desktop\\pat\\input\\1077. Kuchiguse (20).txt","r",stdin);
#endif
	while(scanf("%d",&N) != EOF)
	{
		s.clear();
		min_length = 1000;
		for(auto i = 0;i != N;i++)
		{
			getchar();
			scanf("%[^\n]",ch[i]);
//			printf("%s\n",ch[i]);
			_len  = strlen(ch[i]);
			if(_len > min_length) min_length = _len;
			reverse(ch[i],ch[i] + _len);
		}
		for(auto i = 0;i < min_length;i++)
		{
			auto c = ch[0][i];
			bool ok = true;
			for(auto j = 1;j != N;j++)
			{
				if(ch[j][i] != c) 
				{
					ok = false;
					break;
				}
			}
			if(ok) s.push_back(c);
			else break;
		}
		if(s.empty()) 
		{
			printf("nai\n");
			continue;
		}
		else 
		{
//			while(S.top() == ' ')S.pop();
			reverse(s.begin(),s.end());
			printf("%s\n",s.c_str());
		}
	}
#ifdef INPUT
	while(1){}
	fclose(stdin);
#endif
}

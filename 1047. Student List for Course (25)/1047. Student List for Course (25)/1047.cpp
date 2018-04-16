#include <stdlib.h>
#include <string>
#include <vector>
#include <stdio.h>
#include <algorithm>
/*#define INPUT*/
using namespace std;
const int SIZE = 2500 + 5;
vector<int> vec[SIZE];
char ch[5];
int N,K,M,k;
int char_to_int(char *ch)
{
	return (ch[0] - 'A') * 26 * 26 * 10 + (ch[1] - 'A') * 26 * 10 + (ch[2] - 'A') * 10 + (ch[3] - '0');
}
void int_to_char(int hash)
{
	int x = hash / (26 * 26 * 10);
	ch[0] = x + 'A';
	hash %= (26 * 26 * 10);

	x = hash / (26 * 10);
	ch[1] = x + 'A';
	hash %= (26 * 10);

	x = hash / 10;
	ch[2] = x + 'A';
	hash %= 10;

	ch[3] = hash + '0';
}
int main()
{
#ifdef INPUT
	freopen("C:\\Users\\xuzhong\\Desktop\\pat\\input\\1047. Student List for Course (25).txt","r",stdin);
#endif
	while (scanf("%d %d",&N,&K) != EOF)
	{
 		for(int i = 0;i != SIZE;i++) vec[i].clear();
		for(int i = 0;i != N;i++)
		{
			scanf("%s %d",ch,&M);
			for(int j = 0;j != M;j++)
			{
				scanf("%d",&k);
				vec[k].push_back(char_to_int(ch));
			}
		}

		for(int i = 1;i <= K;i++)
		{
			int s = vec[i].size();
			printf("%d %d\n",i,s);
			sort(vec[i].begin(),vec[i].end());
			for(int j = 0;j != s;j++)
			{
				int_to_char(vec[i][j]);
				printf("%s\n",ch);
			}
		}
	}
#ifdef INPUT
	while(1){}
	fclose(stdin);
#endif
}
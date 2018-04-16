#include <iostream>
#include <algorithm>
#include <vector>
#include <stdio.h>
#include <stdlib.h>
/*#define DEBUG*/
#define INPUT
using namespace std;
const int SIZE = 2500 + 5;
vector<int>vec[SIZE];
vector<int>output;
char ch[4];
int N,K;
int a,b;
int hashName(char *ch)
{
	return (ch[0] - 'A') * 26 * 26 * 10 + (ch[1] - 'A') * 26 * 10 + (ch[2] - 'A') * 10 + ch[3] - '0';
}
int main()
{
#ifdef INPUT
	freopen("C:\\Users\\xuzhong\\Desktop\\pat\\input\\1039. Course List for Student (25).txt","r",stdin);
#endif
	while (scanf("%d%d",&N,&K) != EOF)
	{
		for (int i = 0;i != K;i++) vec[i].clear();
		for (int i = 0;i != K;i++)
		{
			scanf("%d%d",&a,&b);
			for(int j = 0;j != b;j++)
			{
				scanf("%s",ch);
				vec[a].push_back(hashName(ch));
			}
		}
#ifdef DEBUG
		for(int j = 1;j <= K;j++)
		{
			cout << j << ": " << endl;
			for(int i = 0; i != vec[j].size();i++)
				cout << vec[j][i] <<" ";
			cout <<endl;
		}
#endif
		for(int i = 0;i != N;i++)
		{
			scanf("%s",ch);
			printf("%s",ch);
			output.clear();
			for(int j = 1;j <= K;j++)
			{
				if(find(vec[j].begin(),vec[j].end(),hashName(ch)) != vec[j].end()) output.push_back(j);
			}
			cout << " " << output.size();
			for(int j = 0;j != output.size();j++) cout << " " << output[j];
			cout << endl;
		}
	}
#ifdef INPUT
	while (1){}
	fclose(stdin);
#endif
}
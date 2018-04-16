#include <string>
#include <iostream>
#include <stdio.h>
// #define INPUT
// #define DEBUG
using namespace std;
struct  Node
{
	char data;
	int next;
};
Node linkList[100000];
int link1[100000];
int link2[100000];
int max1,max2;
int start1,start2;
int ad1,ad2,N;
char ch;
int main()
{
#ifdef INPUT
	freopen("C:\\Users\\xuzhong\\Desktop\\pat\\input\\1032. Sharing (25).txt","r",stdin);
#endif
	while (scanf("%d %d %d",&start1,&start2,&N) != EOF)
	{
		for(int i = 0;i != N;i++)
		{
			scanf("%d %c %d",&ad1,&ch,&ad2);
			linkList[ad1].data = ch;
			linkList[ad1].next = ad2;
		}
		int _ad = start1;
		max1 = max2 = 0;
		while(_ad != -1)
		{
			link1[max1++] = _ad;
			_ad = linkList[_ad].next;
		}
#ifdef DEBUG
		for(int i = 0;i != max1;i++) cout << link1[i] << " ";
		cout << endl;
#endif
		_ad = start2;
		while (_ad != -1)
		{
			link2[max2++] = _ad;
			_ad = linkList[_ad].next;
		}
#ifdef DEBUG
		for(int i = 0;i != max2;i++) cout << link2[i] << " ";
		cout << endl;
#endif
		if(linkList[ link1[max1 - 1] ].data != linkList[ link2[max2 - 1] ].data) cout << -1 << endl;
		else if(max1 == 1 || max2 == 1) cout << link1[max1] << endl;
		else
		for (int i = max1 - 2,j = max2 - 2;i >= 0,j >= 0;i--,j--)
		{
			int u = link1[i],v = link2[j];
			if(linkList[u].data != linkList[v].data) 
			{
				cout << link1[i + 1] << endl;
				break;
			}
		}
	}
#ifdef INPUT
	while(1){}
	fclose(stdin);
#endif
}
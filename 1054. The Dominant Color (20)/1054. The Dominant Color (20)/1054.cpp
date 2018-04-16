#include <iostream>
#include <utility>
#include <map>
#include <vector>
#include <algorithm>
//#define INPUT
using namespace std;
int  M,N;
int x;

int main()
{
#ifdef INPUT
	freopen("C:\\Users\\xuzhong\\Desktop\\pat\\input\\1054. The Dominant Color (20).txt","r",stdin);
#endif
	while (cin >> M >> N)
	{
		int num = 1,dominant;
		for(int i = 0; i != N;i++)
			for(int j = 0;j != M;j++)
			{
				scanf("%d",&x);
				if(i == 0 && j == 0) dominant = x;
				else
				{
					x == dominant ? num++ : num--;
					if(!num) {dominant = x;num = 1;}
				}
			}
		printf("%d\n",dominant);
	}
#ifdef INPUT
	while(1){}
	fclose(stdin);
#endif
}
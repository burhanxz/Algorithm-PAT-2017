#include <iostream>
//#define INPUT
using namespace std;
long long x,y,z;
char ch[100005];
int main()
{
#ifdef INPUT
	freopen("C:\\Users\\xuzhong\\Desktop\\pat\\input\\1093. Count PAT's (25).txt","r",stdin);
#endif
	while (scanf("%s",ch) != EOF)
	{
		x= y = z = 0;
		for(int i = 0;ch[i] != '\0';i++)
		{
			if(ch[i] == 'P') x++;
			if(ch[i] == 'A') y = (y + x) % 1000000007;
			if(ch[i] == 'T') z = (z + y) % 1000000007;
		}
		printf("%ld\n",z);
	}
#ifdef INPUT
	while(1){}
	fclose(stdin);
#endif
}
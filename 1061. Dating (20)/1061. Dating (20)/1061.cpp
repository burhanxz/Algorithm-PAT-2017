#include <iostream>
#include <string>
#include <string.h>
using namespace std;
string week[7] = {"MON","TUE","WED","THU","FRI","SAT","SUN"};
char ch1[61],ch2[61],ch3[61],ch4[61];
char x,y;
int z;
int main()
{
	while (scanf("%s",ch1) != EOF)
	{
		scanf("%s",ch2);
		scanf("%s",ch3);
		scanf("%s",ch4);
		int length1 = min(strlen(ch1),strlen(ch2));
		int length2 = min(strlen(ch3),strlen(ch4));
		int n = 0;
		for(int i = 0; i != length1;i++)
		{
			if(ch1[i] == ch2[i] && ch1[i] >= 'A' && ch1[i] <= 'G')
			{
				n = i;
				x = ch1[i];
				break;
			}
		}
		for(int i = n + 1; i != length1;i++)
		{
			if(ch1[i] == ch2[i] && ((ch1[i] <= '9' && ch1[i] >= '0') || (ch1[i] <= 'N' && ch1[i] >= 'A')) )
			{
				y = ch1[i];
				break;
			}
		}
		for(int i = 0;i != length2;i++)
		{
			if(ch3[i] == ch4[i] && ((ch3[i] <= 'Z' && ch3[i] >= 'A') || (ch3[i] <= 'z' && ch3[i] >= 'a')))
			{
				z = i;
				break;
			}
		}
		printf("%s ",week[x - 'A'].c_str());
		if(y <= '9' && y >= '0') printf("0%c:",y);
		else 
		{
			printf("%d:",y - 'A' + 10);
		}
		if(z < 10) printf("0%d\n",z);
		else printf("%d\n",z);
	}
}
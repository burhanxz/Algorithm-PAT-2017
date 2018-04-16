#include <iostream>
//#define INPUT
using namespace std;
int a1,b1,c1,a2,b2,c2;
int a,b,c;
int main()
{
#ifdef INPUT
	freopen("C:\\Users\\xuzhong\\Desktop\\pat\\input\\1058. A+B in Hogwarts (20).txt","r",stdin);
#endif
	while (scanf("%d.%d.%d",&a1,&b1,&c1) != EOF)
	{
		scanf("%d.%d.%d",&a2,&b2,&c2);
		a = a1 + a2;
		b = b1 + b2;
		c = c1 + c2;
		if(c >= 29) {c -= 29;b++;}
		if(b >= 17) {b -= 17;a++;}
		printf("%d.%d.%d\n",a,b,c);
	}
#ifdef INPUT
	while(1){}
	fclose(stdin);
#endif
}
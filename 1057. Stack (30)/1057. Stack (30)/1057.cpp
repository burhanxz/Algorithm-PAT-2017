#include <string.h>
#include <string>
#include <memory.h>
#include <iostream>
#include <algorithm>
#define INPUT
using namespace std;
int arr[100000];
int arr1[100000];
int p;
int N;
typedef char ch[20];
ch s[100000];
int main()
{
#ifdef INPUT
	freopen("C:\\Users\\xuzhong\\Desktop\\pat\\input\\1057. Stack (30).txt","r",stdin);
#endif
	while(scanf("%d",&N) != EOF)
	{
		p = -1;
		for(int i = 0;i != N;i++)
		{
			getchar();
			scanf("%[^\n]",s[i]);
			char c = s[i][1];
			switch(c)
			{
			case 'o':if(p == -1) printf("Invalid\n");
					 else {printf("%d\n",arr[p]);--p;}
					 break;
			case 'e':if(p == -1) printf("Invalid\n");
					 else 
					 {
						 int x = p + 1;
						 memcpy(arr1,arr,x * sizeof(int));
						 sort(arr1,arr1 + x);
						 printf("%d\n",arr1[p / 2]);
					 }
					 break;
			case 'u':char ch1[20];
				strcpy(ch1,s[i] + 5);
				int x = atoi(ch1);
				p++;
				arr[p] = x;
				break;
			}
		}
	}
#ifdef INPUT
	while(1){}
	fclose(stdin);
#endif
}
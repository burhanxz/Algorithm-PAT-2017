#include <iostream>
#include <cmath>
#include <cstring>
//#define INPUT
using namespace std;
int hash_table[10005];
int M,T,N,x,key,H;
bool isPrime(int x)
{
	if(x == 2) return true;
	if(x == 1 || x == 0) return false;
	int y = (int)sqrt(x * 1.0);
	for(auto i = 2;i <= y;i++)
	{
		if(x % i == 0) return false;
	}
	return true;
}

int main()
{
#ifdef INPUT
	freopen("C:\\Users\\xuzhong\\Desktop\\pat\\input\\1078. Hashing (25).txt","r",stdin);
#endif
	while (scanf("%d%d",&M,&N) != EOF)
	{
		memset(hash_table,0,sizeof(hash_table));
		if(!isPrime(M))
		{
			for(auto i = M + 1;;i++)
			{
				if(isPrime(i))
				{
					T = i;
					break;
				}
			}
		}
		else T = M;
		for (auto i = 0;i != N;i++)
		{
			scanf("%d",&x);
			H = key = x % T;
//			cout << "key=" << key << ", T=" << T << ", x=" << x << endl;
			if(hash_table[key] == 0) 
			{
				hash_table[key] = x;
				printf("%d",key);
			}	
			else
			{
				bool ok = false;
				for(auto j = 0;j < T;j++)
				{
					key = (H + j * j) % T;
					if(hash_table[key] == 0) 
					{
						 hash_table[key] = x;
						 printf("%d",key);
						 ok = true;
						 break;
					}
				}
				if(!ok) printf("-");
			}
			if(i != N - 1) printf(" ");
		}
		printf("\n");
	}
#ifdef INPUT
	while(1){}
	fclose(stdin);
#endif
}
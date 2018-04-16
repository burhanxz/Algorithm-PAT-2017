#include <iostream>
#include <algorithm>
#include <vector>
//#define INPUT
using namespace std;
vector<int> vec;
int N,M;
int x;
int main()
{
#ifdef INPUT
	freopen("C:\\Users\\xuzhong\\Desktop\\pat\\input\\1048. Find Coins (25).txt","r",stdin);
#endif
	while (scanf("%d %d",&N,&M) != EOF)
	{
		vec.clear();
		for(int i = 0;i != N;i++)
		{
			scanf("%d",&x);
			if(x < M) vec.push_back(x);
		}
		if(vec.size() == 1 || vec.size() == 0) {printf("No Solution\n");continue;}
		sort(vec.begin(),vec.end());
		vector<int>::iterator left = vec.begin();
		vector<int>::iterator right = vec.end() - 1;

		for(;left != right;)
		{
			if(*left + *right == M){printf("%d %d\n",*left,*right);break;}
			else if(*left + *right > M) --right;
			else ++left;
		}
		if(left == right) printf("No Solution\n");
	}
#ifdef INPUT
	while(1){}
	fclose(stdin);
#endif
}
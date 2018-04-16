#include <map>
#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
/*#define INPUT*/
using namespace std;
const int SIZE = 100000 + 5;
int N,n;
int order[SIZE]; 
int num;
map<int, int>m;

int main()
{
#ifdef INPUT
	freopen("C:\\Users\\xuzhong\\Desktop\\pat\\input\\1041. Be Unique (20).txt","r",stdin);
#endif
	while (cin >>N)
	{
		m.clear();
		memset(order,0,sizeof(order));
		num = 0;
		for(int i = 0;i != N;i++)
		{
			cin >> n;
			if(!m.count(n)){m[n] = 1;order[num++] = n;}
			else m[n]++;
		}
#ifdef DEBUG
		for(int i = 0;i != num;i++) cout << order[i] << endl;
#endif
		int _i;
		for(_i = 0;_i != num;_i++)
		{
			if(m[ order[_i] ] == 1) {cout << order[_i] << endl;break;}
		}
		if(_i == num) cout << "None" << endl;
	}
#ifdef INPUT
	while(1){}
	fclose(stdin);
#endif
}
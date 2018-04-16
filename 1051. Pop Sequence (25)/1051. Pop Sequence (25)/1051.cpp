#include <stack>
#include <iostream>
/*#define INPUT*/
using namespace std;
const int SIZE = 1000 + 3;
int N,M,K;
int arr[SIZE];
bool isStack()
{
	stack<int>s;
	int x = 1;
	s.push(x);
	int i = 0;
	while (s.size() <= M && x <= N)
	{
		while(!s.empty() && s.top() == arr[i]) 
		{
			s.pop();
			i++;
			if(i == N) return true;
		}
		s.push(++x);
	}
	return false;
}
int main()
{
#ifdef INPUT
	freopen("C:\\Users\\xuzhong\\Desktop\\pat\\input\\1051. Pop Sequence (25).txt","r",stdin);
#endif
	while (cin >> M >> N >> K)
	{
		while (K--)
		{
			for(int i = 0;i != N;i++)cin >> arr[i];
			if(isStack())cout << "YES" << endl;
			else cout << "NO" << endl;
		}
	}
#ifdef INPUT
	while(1){}
	fclose(stdin);
#endif
}
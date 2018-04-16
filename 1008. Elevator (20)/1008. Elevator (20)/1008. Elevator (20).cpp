#include <iostream>
using namespace std;
int arr[102];
int main()
{
	int n,t;
	while (cin >> n)
	{
		t= 0;
		for (int i = 0; i != n; i++)
		{
			cin >> arr[i];
		}
		t += arr[0]*6;
		for (int i = 0; i != n - 1;i++)
		{
			if(arr[i] < arr[i + 1])t += (arr[i + 1] - arr[i])*6;
			else t += (arr[i] - arr[i + 1])*4;
		}
		t += n * 5;
		cout << t << endl;
	}
}
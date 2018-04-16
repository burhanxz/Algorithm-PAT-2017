#include <iostream>
#include <vector>
#include<algorithm>
using namespace std;
vector<int>vec;
bool isPali(int _N,int _b)
{
	vec.clear();
	int n = _N;
	int x;
	while (n)
	{
		x = n % _b;
		n = n / _b;
		vec.push_back(x);
	}
	reverse(vec.begin(),vec.end());
	int mid = (vec.size() - 1) / 2;
	int right = vec.size() - 1;
	for(int i = 0; i <= mid;i++)
	{
		if(vec[i] != vec[right - i]) return false;
	}
	return true;
}
int N,b;
int main()
{
	while (cin >> N >> b)
	{
		if(N == 0) {cout << "Yes" << endl;cout<< "0" <<endl;}
		else
		{
			if(isPali(N,b)) cout << "Yes" << endl;
			else cout << "No" <<endl;
			if(vec.size())
			{
				cout<<vec[0];
				for (int i = 1; i != vec.size(); i++)
				{
					cout<<" " << vec[i];
				}
			}
			cout << endl;
		}
		
	}
}
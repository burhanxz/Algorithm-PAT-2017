#include <iostream>
#include <iomanip>
using namespace std;
float a[3],b[3],c[3];
void print_o(int i)
{
	switch(i)
	{
		case 0:cout << "W ";break;
		case 1:cout << "T ";break;
		case 2:cout << "L ";break;
	}
}
int main()
{
	while (cin >> a[0])
	{
		for (int i = 1; i !=3; i++)cin >> a[i];
		for (int i = 0; i !=3; i++)cin >> b[i];
		for (int i = 0; i !=3; i++)cin >> c[i];
		int o1,o2,o3;float m1=0.0,m2 = 0.0,m3 = 0.0;
		for (int i = 0; i !=3; i++)
		{
			if(a[i] > m1) {m1 = a[i]; o1 = i;}
			if(b[i] > m2) {m2 = b[i]; o2 = i;}
			if(c[i] > m3) {m3 = c[i]; o3 = i;}
		}
		print_o(o1);print_o(o2);print_o(o3);
		float x = (m1 * m2 * m3 * 0.65 - 1) * 2;
//		cout << x << endl;
		float y = ((int)(x*100+0.5))/100.0;
		cout <<setprecision(2) <<std::fixed <<y <<endl;
	}
	
}
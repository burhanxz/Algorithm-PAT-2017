#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
// #define DEBUG
// #define INPUT
using namespace std;
string poker[54] = {"S1", "S2","S3","S4","S5","S6","S7","S8","S9","S10","S11","S12","S13",
					"H1", "H2","H3","H4","H5","H6","H7","H8","H9","H10","H11","H12","H13",
					"C1", "C2","C3","C4","C5","C6","C7","C8","C9","C10","C11","C12","C13",
					"D1", "D2","D3","D4","D5","D6","D7","D8","D9","D10","D11","D12","D13",
					"J1","J2"};
int hashNum[54] = {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40,41,
					42,43,44,45,46,47,48,49,50,51,52,53};
int position[54];
int order[54];
int N;
bool cmp(const int &lhs,const int &rhs)
{
	int u = position[lhs],v = position[rhs];
	return order[u] < order[v];
}
int main()
{
#ifdef INPUT
	freopen("C:\\Users\\xuzhong\\Desktop\\pat\\input\\1042. Shuffling Machine (20).txt","r",stdin);
#endif
	while (cin >> N)
	{
		sort(hashNum,hashNum + 54);
		for (int i = 0;i != 54;i++)
			cin >> order[i];
		for (int i = 0;i != N;i++)
		{
			for(int j = 0;j != 54;j++)
				position[hashNum[j]] = j;
			sort(hashNum,hashNum + 54,cmp);
		}
		cout << poker[hashNum[0]];
		for (int i = 1;i != 54;i++)
		{
			cout<< " " << poker[hashNum[i]];
		}
		cout << endl;
	}
#ifdef INPUT
	while(1){}
	fclose(stdin);
#endif
}
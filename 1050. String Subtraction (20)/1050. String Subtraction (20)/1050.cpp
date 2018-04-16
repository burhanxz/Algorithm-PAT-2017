#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string>
#include <iostream>
#include <set>
#include <algorithm>
//#define INPUT
using namespace std;
const int SIZE = 10000;
string s1;
string s2;
int main()
{
#ifdef INPUT
	freopen("C:\\Users\\xuzhong\\Desktop\\pat\\input\\1050. String Subtraction (20).txt","r",stdin);
#endif
	while (getline(cin,s1))
	{
//		cout << "s1= " <<s1 << endl;
		getline(cin,s2);
//		cout << "s2= " <<s2 << endl;
		for(int i = 0;i != s1.size();i++)
			if(s2.find(s1[i]) == s2.npos) cout << s1[i];
		cout << endl;
	}
#ifdef INPUT
	while(1){}
	fclose(stdin);
#endif
}
#include <stack>
#include <iostream>
#include <string>
#include <sstream>
#define INPUT
using namespace std;
int N;
string str;
stringstream ss;
stack<int>S;
int pre_order[31];
int in_order[31];
int rch[31],lch[31];
int build_tree(int L1,int R1,int L2,int R2)
{
	if(L1 > R1) return 0; //叶节点
	int root = pre_order[L2];
	int mid;
	for(int i = L1;i <= R1;i++)
	{
		if(in_order[i] == root) 
		{
			mid = i;
			break;
		}
	}
	int x = mid - L1;
	lch[root] = build_tree(L1,mid - 1,L2 + 1,L2 + x);
	rch[root] = build_tree(mid + 1,R1,L2 + x + 1,R2);
	return root;
}
void post_order(int s)
{
	static int t = 0;
	if(s == 0) return;
	else
	{
		post_order(lch[s]);
		post_order(rch[s]);
		if(t == 0)
		{
			t++;
			printf("%d",s);
		}
		else printf(" %d",s);
	}
}
int main()
{
#ifdef INPUT
	freopen("C:\\Users\\xuzhong\\Desktop\\pat\\input\\1086. Tree Traversals Again (25).txt","r",stdin);
#endif
	while (cin >> N)
	{
		getchar();
		while(!S.empty()) S.pop();
		size_t index1 = 0,index2 = 0;
		for(int i = 0;i != 2 * N;i++)
		{
			getline(cin,str);
			if(str[1] == 'u')
			{
				int x;
				ss << string(str.begin() + 5,str.end());ss >> x;ss.clear();ss.str("");
				S.push(x);
				pre_order[index1++] = x;
			}
			else if(str[1] == 'o')
			{
				in_order[index2++] = S.top();
				S.pop();
			}
		}
// 		cout << "先序：" << endl;
// 		for(int i = 0;i != N;i++) cout << pre_order[i] << " ";
// 		cout << endl;
// 		cout << "中序：" << endl;
// 		for(int i = 0;i != N;i++) cout << in_order[i] << " ";
// 		cout << endl;
		int r = build_tree(0, N - 1, 0, N - 1);
		post_order(r);
		printf("\n");
	}
#ifdef INPUT
	while(1){}
	fclose(stdin);
#endif
}
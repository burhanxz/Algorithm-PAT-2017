#include <iostream>
#include <set>
#include <cstring>
#define INPUT
using namespace std;
const int maxn = 35;
int rch[maxn];
int lch[maxn];
int post[maxn],pre[maxn];
bool isUnique;
bool isOk;
int N;
int root;
set<int>s1,s2;
bool isEqual(set<int> &lhs,set<int> &rhs)
{
	
// 	cout << lhs.size() << " " << rhs.size() << endl; 
// // 	for(auto iter1 = lhs.begin(),iter2 = rhs.begin();iter1 != lhs.end(),iter2 != rhs.end();iter1++,iter2++)
// // 		cout << *iter1 << " " << *iter2 << endl; 
	for(auto iter1 = lhs.begin(),iter2 = rhs.begin();iter1 != lhs.end(),iter2 != rhs.end();iter1++,iter2++)
	{
		if(*iter1 != *iter2) return false;
	}
	return true;
}
int build_tree(int L1,int R1,int L2,int R2)
{
	if(R1 < L1 || R2 < L2) return 0;
	isUnique = true;
	int root = pre[L1];
	int i = 0;
	s1.clear();s2.clear();
	
	for(;;)
	{
		if(L1 + 1 + i > R1 || L2 + i > R2 - 1) break; 
		s1.insert(pre[L1 + 1 + i]);
		s2.insert(post[L2 + i]);
		if(isEqual(s1,s2))
		{
			if(L1 + 1 + i == R1 || L2 + i == R2 - 1)
			{
				
				isUnique = false;
				isOk = false;
			}
			break;
		}
		i++;
		
	}
	if(isUnique)
	{
		lch[root] = L1 == R1 ? 0 : build_tree(L1 + 1, L1 + 1 + i, L2, L2 + i);
		rch[root] = L1 == R1 ? 0 : build_tree(L1 + 1 + i + 1, R1, L2 + i + 1, R2 - 1);
	}
	else 
	{
		lch[root] = 0;
		rch[root] = build_tree(L1 + 1, L1 + 1 + i, L2, L2 + i);
	}
	return root;
}
void in_order(int s)
{
	static int x = 0;
	if(s == 0) return;
	else 
	{
		in_order(lch[s]);
		if(x == 0)
		{
			cout << s;
			x++;
		}
		else cout << " " << s;
		in_order(rch[s]);
	}
}
int main()
{
#ifdef INPUT
	freopen("C:\\Users\\xuzhong\\Desktop\\pat\\input\\1119. Pre- and Post-order Traversals (30).txt","r",stdin);
#endif
	while(scanf("%d",&N) != EOF)
	{
		for(int i = 0;i != N;i++)
		{
			scanf("%d",pre + i);
		}
		for(int i = 0;i != N; i++)
		{
			scanf("%d",post + i);
		}
		memset(rch,0,sizeof(rch));
		memset(lch,0,sizeof(lch));
		isOk = true;
		int root = build_tree(0, N - 1, 0, N - 1);
		if(isOk)
			printf("Yes\n");
		else printf("No\n");
		in_order(root);
		cout << endl;
	}
#ifdef INPUT
	while(1){}
	fclose(stdin);
#endif
}
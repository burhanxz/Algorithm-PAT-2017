#include <iostream>
#include <queue>
#include <stdio.h>
#include <string>
#include <cstring>
//#define INPUT
//#define DEBUG
using namespace std;
int lch[31];
int rch[31];
int post_order[31];
int in_order[31];
int level_order[31];
int N;
int build_tree(int L1,int R1,int L2,int R2)
{
//	cout << "done" << endl;
	if(L1 > R1) return 0;
	int root = post_order[R2];
	int p = L1;//������λ��
	while(in_order[p] != root) p++;
	int leftNodeNum = p - L1;//�������ڵ�ĸ���
	lch[root] = build_tree(L1, p - 1, L2, L2 + leftNodeNum - 1);
	rch[root] = build_tree(p + 1, R1, L2 + leftNodeNum, R2 - 1);
	return root;
}
void BFS(int u)
{
	queue<int>Q;
	Q.push(u);
	int i = 0;
	while (!Q.empty())
	{
		u = Q.front();Q.pop();
		level_order[i++] = u;
		if(lch[u])Q.push(lch[u]);
		if(rch[u])Q.push(rch[u]);
	}
}
void pre_order(int u)
{
	if(u)
	{
		cout << u << " ";
		pre_order(lch[u]);
		pre_order(rch[u]);
	}
}
int main()
{
#ifdef INPUT
	freopen("C:\\Users\\xuzhong\\Desktop\\pat\\input\\1020. Tree Traversals (25).txt","r",stdin);
#endif	
	while (cin >> N)
	{
		memset(lch,0,sizeof(lch));
		memset(rch,0,sizeof(rch));
		memset(level_order,0,sizeof(level_order));
		for(int i = 0;i != N;i++) cin >> post_order[i];
		for(int i = 0;i != N;i++) cin >> in_order[i];
		//�������
		int root = build_tree(0,N - 1,0,N - 1);
		BFS(root);
		//����������
#ifdef DEBUG
		pre_order(root);
		cout << endl;
#endif
		cout << level_order[0];
		for(int i = 1;i != N;i++) cout << " " << level_order[i];
		cout << endl;
		//������
	}
#ifdef INPUT
	while(1){}
	fclose(stdin);
#endif
}
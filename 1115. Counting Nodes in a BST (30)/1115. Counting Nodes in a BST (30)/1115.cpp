#include <cstdio>
#include <iostream>
#define INPUT
using namespace std;
const int maxn = 1000 + 1;
struct Node
{
	int data;
	Node *left,*right;
	Node(int _data):data(_data),left(NULL),right(NULL){}
};
Node *newnode(int _data){ return new Node(_data); }
void delnode(Node *s)
{
	if(s != NULL)
	{
		if(s->left != NULL) delnode(s->left);
		if(s->right != NULL) delnode(s->right);
		delete s;
	}
}
int arr[maxn];
int maxLevel;
int n1,n2;
void build_tree(int x,Node *T)
{
	if(T == NULL) return;
	if(x <= T->data) 
	{
		if(T->left == NULL)
			T->left = newnode(x);
		else
			build_tree(x,T->left);
	}
	if(x > T->data) 
	{
		if(T->right == NULL)
			T->right = newnode(x);
		else 
			build_tree(x,T->right);
	}
}
void findHeight(Node *T,int level)
{
	if(T != NULL)
	{
		maxLevel = max(maxLevel,level);
		findHeight(T->left,level + 1);
		findHeight(T->right,level + 1);
	}
}
void pre_order(Node *T,int level)
{
	if(T != NULL)
	{
		if(level == maxLevel) n1++;
		if(level == maxLevel - 1) n2++;
		pre_order(T->left,level + 1);
		pre_order(T->right,level + 1);
	}
}
int N;
int main()
{
#ifdef INPUT
	freopen("C:\\Users\\xuzhong\\Desktop\\pat\\input\\1115. Counting Nodes in a BST (30).txt","r",stdin);
#endif
	while (scanf("%d",&N) != EOF)
	{
		scanf("%d",arr + 0);
		Node *root = newnode(arr[0]);
		for(int i = 1;i != N;i++)
		{
			scanf("%d",arr + i);
			build_tree(arr[i],root);
		}
		maxLevel = 0;
		findHeight(root,1);
		n1 = n2 = 0;
		pre_order(root,1);
		printf("%d + %d = %d\n",n1,n2,n1 + n2);
		delnode(root);
	}
#ifdef INPUT
	while(1){}
	fclose(stdin);
#endif
}
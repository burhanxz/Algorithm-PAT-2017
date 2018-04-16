#include <iostream>
#include <queue>
#include <cstdio>
#include <algorithm>
#define INPUT
using namespace std;
const int maxn = 10000;
int N,arr[maxn];
struct Node 
{
	int data;
	Node *left,*right;
	int height;
};
Node *newnode(int data)
{
	Node *node = new Node;
	node->data = data;
	node->height = 1;
	node->left = node->right = NULL;
	return node;
}
int getHeight(Node *node)
{
	if(node == NULL) return 0;
	return node->height;
}
void updateHeight(Node *node)
{
	node->height = max(getHeight(node->left), getHeight(node->right)) + 1;
}
int getBalanceFactor(Node *node)
{
	return getHeight(node->left) - getHeight(node->right);
}

struct AVL
{
	void L(Node *&root)
	{
		Node *temp = root->right;
		root->right = temp->left;
		temp->left = root;
		updateHeight(root);
		updateHeight(temp);
		root = temp;
	}

	void R(Node *&root)
	{
		Node *temp = root->left;
		root->left = temp->right;
		temp->right = root;
		updateHeight(root);
		updateHeight(temp);
		root = temp;
	}

	void insert(Node *&root, int v)
	{
		if(root == NULL)
		{
			root = newnode(v);
			return;
		}
		if(v < root->data)
		{
			insert(root->left,v);
			updateHeight(root);
			if(getBalanceFactor(root) == 2)
			{
				if(getBalanceFactor(root->left) == 1)
				{
					R(root);
				}
				else if(getBalanceFactor(root->left) == -1)
				{
					L(root->left);
					R(root);
				}
			}
		}
		else 
		{
			insert(root->right,v);
			updateHeight(root);
			if(getBalanceFactor(root) == -2)
			{
				if(getBalanceFactor(root->right) == -1)
				{
					L(root);
				}
				else if(getBalanceFactor(root->right) == 1)
				{
					R(root->right);
					L(root);
				}
			}
		}
	}

	Node *Create(int data[],int n)
	{
		Node *root = NULL;
		for(int i = 0;i != n;i++)
		{
			insert(root,data[i]);
		}
		return root;
	}
};
int level[maxn];
int rch[maxn];
int lch[maxn];
void pre_order(Node *root)
{
	if(root != NULL)
	{
		cout << root->data << endl;
		pre_order(root->left);
		pre_order(root->right);
	}
}
void level_order(Node *root)
{
	int x = 1;
	queue<Node *>Q;
	Q.push(root);
	while(!Q.empty())
	{
		Node *node = Q.front();
		Q.pop();
		if(x == 1)
			printf("%d",node->data);
		else printf(" %d",node->data);
		level[x++] = node->data;
		if(node->left != NULL) 
		{
			Q.push(node->left);
			lch[node->data] = node->left->data;
		}
		if(node->right != NULL) 
		{
			Q.push(node->right);
			rch[node->data] = node->right->data;
		}
	}
}
int main()
{
#ifdef INPUT
	freopen("C:\\Users\\xuzhong\\Desktop\\pat\\input\\1123. Is It a Complete AVL Tree (30).txt","r",stdin);
#endif
	scanf("%d",&N);
	for(int i = 0;i != N;i++)
	{
		scanf("%d",arr + i);
	}
	AVL avl;
	Node *root = avl.Create(arr,N);
	/*	pre_order(root);*/
	fill(level,level + maxn, -1);
	fill(rch,rch + maxn, -1);
	fill(lch,lch + maxn, -1);
	level_order(root);
	printf("\n");
	bool ok = true;
	// 	for(int i = 1;i <= N;i++)
	// 		cout << level[i] << endl;
	for(int i = 1;i <= N; i++)
	{
		// 		cout << "level[" << i << "]=" << level[i] << ", level[" << 2 * i << "]=" << level[i*2] <<endl;
		// 		cout << "level[" << i << "]=" << level[i] << ", level[" << 2 * i + 1<< "]=" << level[i*2+1] <<endl;
		// 		cout << "lch[" << level[i] <<"]=" << lch[level[i]] << endl;
		// 		cout << "rch[" << level[i] <<"]=" << rch[level[i]] << endl;
		if(level[i * 2] != -1)
		{

			if(lch[level[i]] != level[i * 2]) 
			{
				ok = false;
				break;
			}
		}
		if(level[i * 2 + 1] != -1)
		{
			if(rch[level[i]] != level[i * 2 + 1])
			{				
				ok = false;
				break;
			}
		}
	}
	if(ok) printf("YES\n");
	else printf("NO\n");
#ifdef INPUT
	while(1){}
	fclose(stdin);
#endif
}
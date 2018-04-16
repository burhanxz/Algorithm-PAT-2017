#include <cstdio>
#include <iostream>
#define INPUT
using namespace std;
const int maxn = 20 + 2;
int N;
int arr[maxn];
struct Node
{
	int data,height;
	Node *left,*right;
	Node():data(0),left(NULL),right(NULL){}
};
Node *newnode(int v)
{
	Node *node = new Node();
	node->data = v;
	node->height = 1;
	node->left = node->right = NULL;
	return node;
}

int getHeight(Node *node)
{
	if(node == NULL) return 0;
	return node->height;
}

int getBalanceFactor(Node *node)
{
	return getHeight(node->left) - getHeight(node->right);
}

void updateHeight(Node *node)
{
	node->height = max(getHeight(node->left), getHeight(node->right)) + 1;
}

void search(Node *node,int x)
{
	if(node == NULL) return;
	if(node->data == x)
	{
		printf("found\n");
	}
	else if(x < node->data)
		search(node->left,x);
	else if(x > node->data)
		search(node->right,x);
}
struct AVL
{
	void L(Node *&node)
	{
		Node *temp = node->right;
		node->right = temp->left;
		temp->left = node;
		updateHeight(node);
		updateHeight(temp);
		node = temp;
	}

	void R(Node *&node)
	{
		Node *temp = node->left;
		node->left = temp->right;
		temp->right = node;
		updateHeight(node);
		updateHeight(temp);
		node = temp;
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

	Node* Create(int data[],int n)
	{
		Node *root = NULL;
		for(int i = 0;i < n;i++)
		{
			insert(root,data[i]);
		}
		return root;
	}
};
int main()
{
#ifdef INPUT
	freopen("C:\\Users\\xuzhong\\Desktop\\pat\\input\\1066. Root of AVL Tree (25).txt","r",stdin);
#endif
	scanf("%d",&N);
	for(int i = 0;i != N;i++)
	{
		scanf("%d",arr + i);
	}
	AVL avl;
	Node *root = avl.Create(arr,N);
	printf("%d\n",root->data);
#ifdef INPUT
	while(1){}
	fclose(stdin);
#endif
}
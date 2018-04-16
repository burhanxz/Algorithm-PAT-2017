#include <iostream>
#include <memory.h>
/*#define DEBUG*/
#define INPUT
using namespace std;
const int SIZE = 1000 + 5;
int order[SIZE];
int N;
int preorder[SIZE];
int postorder[SIZE];
struct node
{
	int data;
	node *left;
	node *right;
	node(int _data):data(_data),left(NULL),right(NULL){}
};
node* newNode(int _data)
{
	return new node(_data);
}
void deleteNode(node *T)
{
	if(T->left != NULL) deleteNode(T->left);
	if(T->right != NULL) deleteNode(T->right);
	delete T;
}
void build_tree(node *u,int x)
{
	if(x < u->data)
	{
		if(u->left == NULL) {u->left = newNode(x);return;}
		else build_tree(u->left,x);
	}
	else
	{
		if(u->right == NULL) {u->right = newNode(x);return;}
		else build_tree(u->right,x);
	}
}
void preorder_traversal(node *u)
{
	static int n = 0;
	if(u != NULL)
	{
		preorder[n++] = u->data;
		if(u->left != NULL) preorder_traversal(u->left);
		if(u->right != NULL) preorder_traversal(u->right);
	}
}
void postorder_traversal(node *u)
{
	static int n = 0;
	if(u != NULL)
	{
		if(u->left != NULL) postorder_traversal(u->left);
		if(u->right != NULL) postorder_traversal(u->right);
		postorder[n++] = u->data;
	}
}
void preorder_traversal_mirror(node *u)
{
	static int n = 0;
	if(u != NULL)
	{
		preorder[n++] = u->data;
		if(u->right != NULL) preorder_traversal_mirror(u->right);
		if(u->left != NULL) preorder_traversal_mirror(u->left);
	}
}
void postorder_traversal_mirror(node *u)
{
	static int n = 0;
	if(u != NULL)
	{
		if(u->left != NULL) postorder_traversal_mirror(u->left);
		if(u->right != NULL) postorder_traversal_mirror(u->right);
		postorder[n++] = u->data;
	}
}
int main()
{
#ifdef INPUT
	freopen("C:\\Users\\xuzhong\\Desktop\\pat\\input\\1043. Is It a Binary Search Tree (25).txt","r",stdin);
#endif
	while (cin >> N)
	{
		for(int i = 0;i != N;i++)
			cin >> order[i];
		node* root = newNode(order[0]);
		for(int i = 1;i != N;i++)
			build_tree(root,order[i]);

		preorder_traversal(root);
#ifdef DEBUG
		cout << "preorder:" << endl;
		for(int i = 0;i != N;i++)
		{
			cout << preorder[i] << " ";
		}
		cout << endl;
#endif
		if(memcmp(preorder,order,sizeof(int)*N))
		{
			cout << "Yes" << endl;
			postorder_traversal(root);
			for(int i = 0;i != N;i++)
			{
				if(i == 0) cout << postorder[i];
				else cout << " " <<postorder[i];
			}
			cout << endl;
			continue;
		}

		preorder_traversal_mirror(root);
#ifdef DEBUG
		cout << "preorder:" << endl;
		for(int i = 0;i != N;i++)
		{
			cout << preorder[i] << " ";
		}
		cout << endl;
#endif
		if(memcmp(preorder,order,sizeof(int)*N))
		{
			cout << "Yes" << endl;
			postorder_traversal_mirror(root);
			for(int i = 0;i != N;i++)
			{
				if(i == 0) cout << postorder[i];
				else cout << " " <<postorder[i];
			}
			cout << endl;
			continue;
		}
		cout << "No" << endl;

		deleteNode(root);
	}
#ifdef INPUT
	while(1){}
	fclose(stdin);
#endif
}
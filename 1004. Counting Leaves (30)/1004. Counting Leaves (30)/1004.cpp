#include <iostream>
#include <queue>
#include <stdio.h>
#include <string>
#include <cstring>
#define INPUT
/*#define DEBUG*/
using namespace std;
int N,M;
int noChild[105];
bool vis[105];
int maxLevel;
struct Node
{
	int level;
	int id;
	Node *firstChild;
	Node *nextSibling;
	Node():firstChild(NULL),nextSibling(NULL){}
};
Node* newnode()
{
	return new Node();
}
void remove_tree(Node *_u)
{
	if(_u == NULL) return;
	remove_tree(_u->firstChild);
	remove_tree(_u->nextSibling);
	delete _u;
}
typedef Node* nodePointer;
nodePointer nodeArr[105];
void BFS(Node *u)
{
	memset(noChild,0,sizeof(noChild));
	for(int i = 0;i != 105;i++)vis[i] = false;
	maxLevel = 0;
	queue<nodePointer>Q;
	Q.push(u);
	while (!Q.empty())
	{
		u = Q.front();Q.pop();
#ifdef DEBUG
		cout << "No."<< u->id << endl;
#endif
		if(u->firstChild != NULL)
		{
			Q.push(u->firstChild);
			vis[u->firstChild->id] = true;
			u->firstChild->level = u->level + 1;
			maxLevel = max(u->firstChild->level,maxLevel);
		}
		else noChild[u->level]++;
		while (u->nextSibling != NULL && !vis[u->nextSibling->id])
		{
			Q.push(u->nextSibling);
			vis[u->nextSibling->id] = true;
			u->nextSibling->level = u->level;
			u = u->nextSibling;
		}
	}
}
int main()
{
#ifdef INPUT
	freopen("C:\\Users\\xuzhong\\Desktop\\pat\\input\\1004. Counting Leaves (30).txt","r",stdin);
#endif
	while (cin >> N >> M)
	{
		int _root,_id,_brother,K;
		for(int i = 0; i != 105;i++) nodeArr[i] = NULL;
		nodeArr[1] = newnode();nodeArr[1]->level = 1;
		for(int i = 0; i != M;i++)
		{
			cin >> _root >> K;
			if(nodeArr[_root] == NULL) nodeArr[_root] = newnode();
			for(int i = 0;i != K;i++)
			{
				cin >> _id;
				if(i == 0) 
				{
					if(nodeArr[_id] == NULL) nodeArr[_id] = newnode();
					nodeArr[_root]->firstChild = nodeArr[_id];
					_brother = _id;
				}
				else 
				{
					if(nodeArr[_id] == NULL) nodeArr[_id] = newnode();
					nodeArr[_brother]->nextSibling = nodeArr[_id];
					_brother = _id;
				}
			}
		}
		for(int i = 0;i != 105;i++) if(nodeArr[i] != NULL) nodeArr[i]->id = i;
		//ÕÍ≥… ‰»Î
		BFS(nodeArr[1]);
		cout << noChild[1];
		for(int i = 2; i <= maxLevel;i++)
		{
			cout << " " << noChild[i];
		}
		cout << endl;
		remove_tree(nodeArr[1]);
#ifdef INPUT
		while (1){}
		fclose(stdin);
#endif
	}
}
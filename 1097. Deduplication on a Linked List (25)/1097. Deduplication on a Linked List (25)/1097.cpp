#include <iostream>
#include <cstdio>
#include <map>
#include <utility>
#include <cmath>
//#define INPUT
using namespace std;
const int maxn = 100000 + 2;
struct Node
{
	int data;
	int next;
};
Node link_list[maxn];
Node rev[maxn];
int start;
int N;
int x,y,z;
map<int,int>iMap;
int main()
{
#ifdef INPUT
	freopen("C:\\Users\\xuzhong\\Desktop\\pat\\input\\1097. Deduplication on a Linked List (25).txt","r",stdin);
#endif
	while (scanf("%d%d",&start,&N) != EOF)
	{
		iMap.clear();
		for(int i = 0;i != maxn;i++)
		{
			link_list[i].next = -1;
			rev[i].next = -1;
		}
		for(int i = 0;i != N;i++)
		{
			scanf("%d%d%d",&x,&y,&z);
			link_list[x].data = y;
			link_list[x].next = z;

		}
		int p = start;
		int last = -2;
		int start1;
		iMap.insert(make_pair(abs(link_list[p].data),1));
		while (1)
		{
			int q = link_list[p].next;
			if(q == -1) break;
			if(!iMap.count(abs(link_list[q].data)))
			{
				p = q;
				iMap.insert(make_pair(abs(link_list[q].data),1));
			}
			else
			{
				link_list[p].next = link_list[q].next;
				if(last < 0)
				{
					rev[q].data = link_list[q].data;
					rev[q].next = -1;
					start1 = last = q;
				}
				else 
				{
					rev[last].next = q;
					rev[q].data = link_list[q].data;
					rev[q].next = -1;
					last = q;
				}
			}
		}
		while(start != -1)
		{
			if(link_list[start].next != -1)
				printf("%05d %d %05d\n",start,link_list[start].data,link_list[start].next);
			else 
				printf("%05d %d %d\n",start,link_list[start].data,link_list[start].next);
			start = link_list[start].next;
		}
		while(start1 != -1)
		{
			if(rev[start1].next != -1)
				printf("%05d %d %05d\n",start1,rev[start1].data,rev[start1].next);
			else
				printf("%05d %d %d\n",start1,rev[start1].data,rev[start1].next);
			start1 = rev[start1].next;
		}
	}
#ifdef INPUT
	while(1){}
	fclose(stdin);
#endif
}
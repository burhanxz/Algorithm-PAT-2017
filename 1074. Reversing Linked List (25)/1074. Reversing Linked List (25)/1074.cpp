#include <iostream>
//#define INPUT
using namespace std;
struct node
{
	int prev,next;
	int data;
};
node link_list[100001];
int start,End,N,K,start_adderss;
int x,y,z;
int main()
{
#ifdef INPUT
	freopen("C:\\Users\\xuzhong\\Desktop\\pat\\input\\1074. Reversing Linked List (25).txt","r",stdin);
#endif	
	while (scanf("%d%d%d",&start_adderss,&N,&K) != EOF)
	{
		
		for(auto i = 0;i != N;i++)
		{
			scanf("%d%d%d",&x,&y,&z);
			link_list[x].data = y;
			link_list[x].next = z;
			link_list[z].prev = x;
		}
		link_list[100000].next = start_adderss;
		start = 100000;
		int new_start = start_adderss;
		int new_start_x = 0;
		while (1)
		{
			
			if(start == -1)break;
			bool is_end = false;
			int r = start;
			for(auto i = 0;i != K;i++)
			{
				if(link_list[r].next == -1)
				{
					is_end = true;
					break;
				}
				r = link_list[r].next;
			}
			if(is_end) break;
			if(new_start_x == 0)
			{
				new_start = r;
				new_start_x++;
			}
			End = link_list[r].next;
			for(auto i = 0;i != K;i++)
			{
				link_list[r].next = link_list[r].prev;				
				if(i != K -1)r = link_list[r].prev;
			}
			link_list[r].next = End;
			start = End;
			
		}
		while (new_start != -1)
		{
			int temp = link_list[new_start].next;
			if(temp == -1) printf("%05d %d %d\n",new_start,link_list[new_start].data,temp);
			else
				printf("%05d %d %05d\n",new_start,link_list[new_start].data,temp);
			new_start = temp;
		}
	}
#ifdef INPUT
	while(1){}
	fclose(stdin);
#endif
}
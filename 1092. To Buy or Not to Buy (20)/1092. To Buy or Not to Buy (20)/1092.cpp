#include <vector>
#include <map>
#include <utility>
#include <iostream>
//#define INPUT
using namespace std;
char ch1[1001];
char ch2[1001];
map<char,int>map1;
map<char,int>map2;
int main()
{
#ifdef INPUT
	freopen("C:\\Users\\xuzhong\\Desktop\\pat\\input\\1092. To Buy or Not to Buy (20).txt","r",stdin);
#endif
	while (scanf("%s",ch1) != EOF)
	{
		getchar();
		for(int i = 0;ch1[i] != '\0';i++)
		{
			char c = ch1[i];
			auto ret = map1.insert(make_pair(c,1));
			if(!ret.second)
				++ret.first->second;
		}
		scanf("%s",ch2);
		for(int i = 0;ch2[i] != '\0';i++)
		{
			auto ret = map2.insert(make_pair(ch2[i],1));
			if(!ret.second)
				++ret.first->second;
		}

		bool ok = true;
		int ans1 = 0;
		int ans2 = 0;

		for(auto iter = map2.begin();iter != map2.end();iter++)
		{
			if(map1[iter->first] < iter->second) 
			{
				ok = false;
				break;
			}
		}
		if(ok)
			for(auto iter = map1.begin();iter != map1.end();iter++)
			{
				ans1 += iter->second - map2[iter->first];
			}
		else 
			for(auto iter = map2.begin();iter != map2.end();iter++)
			{
				if(iter->second >= map1[iter->first])
					ans2 += iter->second - map1[iter->first];
			}
		if(ok) 
			printf("Yes %d\n",ans1);
		else printf("No %d\n",ans2);
	}
#ifdef INPUT
	while(1){}
	fclose(stdin);
#endif
}
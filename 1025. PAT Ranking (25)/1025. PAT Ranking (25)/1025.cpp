#include <iostream>
#include <cstring>
#include<string>
#include <sstream>
#include <algorithm>
#include <vector>
#include <stdio.h>
// #define INPUT
// #define DEBUG
using namespace std;
string s;
stringstream ss;
int N,K,totalK;
struct Item
{
	string registration_number;
	int final_rank;
	int location_number;
	int local_rank;
	int score;
	Item(string _s,string _score,int _n):registration_number(_s),location_number(_n)
	{
		ss << _score;ss >> score;ss.clear();ss.str("");
	}
};
vector<Item>rankLists[101];
vector<Item>grossList;
bool cmp(const Item &lhs,const Item &rhs)
{
	if(lhs.score == rhs.score) return lhs.registration_number < rhs.registration_number;
	else return lhs.score > rhs.score;
}
void setRankList(int n)
{
	if(!rankLists[n].size()) return;
	sort(rankLists[n].begin(),rankLists[n].end(),cmp);
	int rank = 1;
	rankLists[n][0].local_rank = 1;
	for(int i = 1; i != rankLists[n].size();i++)
	{
		rank++;
		if(rankLists[n][i].score == rankLists[n][i - 1].score) rankLists[n][i].local_rank = rankLists[n][i - 1].local_rank;
		else rankLists[n][i].local_rank = rank;
	}
}
void setGrossList()
{
	grossList.clear();
	for(int i = 1; i != totalK ;i++)
	{
		for(int j = 0;j != rankLists[i].size();j++)
			grossList.push_back(rankLists[i][j]);
	}
	sort(grossList.begin(),grossList.end(),cmp);
	int rank = 1;
	if(!grossList.size()) return;
	grossList[0].final_rank = 1;
	for(int i = 1; i != totalK;i++)
	{
		rank++;
		if(grossList[i].score == grossList[i - 1].score) grossList[i].final_rank = grossList[i - 1].final_rank;
		else grossList[i].final_rank = rank;
	}
}
int main()
{
#ifdef INPUT
	freopen("C:\\Users\\xuzhong\\Desktop\\pat\\input\\1025. PAT Ranking (25).txt","r",stdin);
#endif
	while (getline(cin,s))
	{
		for(int i = 0;i != 101;i++)rankLists[i].clear();
		totalK = 0;
		ss << s;ss >> N;ss.clear();ss.str("");
		for(int i = 1;i <= N;i++)
		{
			getline(cin,s);
			ss << s; ss>> K;ss.clear();ss.str("");
			totalK += K;
			for(int j = 0;j != K;j++)
			{
				getline(cin,s);
				rankLists[i].push_back( Item(string(s.begin(),s.begin() + 13), string(s.begin() + 14,s.end()),i) );
			}
		}
		for(int i = 1; i <= N; i++) setRankList(i);
		setGrossList();
		cout << totalK << endl;
		for(int i = 0;i != totalK;i++)
		{
			cout << grossList[i].registration_number << " " 
				<< grossList[i].final_rank <<" " 
				<<grossList[i].location_number<<" "
				<< grossList[i].local_rank << endl;
		}
	}
#ifdef INPUT
	while (1){}
	fclose(stdin);
#endif
}
#include <iostream>
#include<queue>
#include <cstring>
#include <string>
using namespace std;
int M,N;
int K,Q;
int T[1001];
int query[1001];
int spend[1001];
struct Rec
{
	int hh,mm;
	int t;
	bool use;
	Rec(int _t):t(_t)
	{
		use = true;
		mm = t % 60;
		hh = t / 60;
		hh += 8;
	}
	Rec()
	{
		use = false;
	}
};
Rec r[1001];
bool ok[1001];
queue<int>w[21];
int main()
{
	while (cin >> N >> M >> K >> Q)
	{
		memset(spend,0,sizeof(spend));
		memset(query,0,sizeof(query));
		for(int i = 0; i != 1001;i++){r[i].use = false;ok[i] = true;}
		for (int i = 1; i <= K; i++)cin >> T[i];
		for (int i = 1; i <= Q; i++)cin >> query[i];

		int x = 1;//给顾客编号
		for(int i = 0; i != M; i++)
			for(int j = 0; j != N; j++)
				if(w[j].size() <= M) {w[j].push(x++);}
	    //再考虑一下人比窗口少的情况
		for (int time = 0;time < 9 * 60;time++)
		{
			for(int i = 0;i != N;i++)
			{
				if (w[i].size())
				{
					int frontNum = w[i].front();
					if(spend[frontNum] >= T[frontNum]) 
					{
						w[i].pop();
/*						cout << "time=" << time << "," << frontNum << "号出队, " ;*/
						Rec _r(time);
						r[frontNum] =  _r;
/*						cout <<"出队时间"<<r[frontNum].hh<<":"<<r[frontNum].mm <<endl;*/
					}
				}
			}
			//检查每个正接受服务的人他们所费时间是否超过或等于所需业务时间，是，则出队
			for(int i = x;i <= K ;i++)
				for(int j = 0;j != N;j++)
					if( w[j].size() < M )
					{
						w[j].push(i);
	/*					cout << "time=" << time << "," << i << "号入队" <<endl;*/
						x++;
					}
			//对每一个人，检查每一个窗口，如果队伍有空，就插进来，更新最新需接受服务的人x
			for(int i = 0; i != N;i++)
				if (w[i].size()) 
				{
					int frontNum = w[i].front();
					bool isTrue = false;
					if(ok[frontNum]) {isTrue = (T[frontNum] + time >= 9 * 60);ok[frontNum] = false;}
					if(isTrue && !r[frontNum].use) 
					{
						Rec _r(T[frontNum] + time);
						r[frontNum] = _r;
					}
					else spend[frontNum]++;

				}
			//对每个正在前台接受服务的人，花费时间+1
		}
		for (int i = 0;i != 1001;i++)
		{
			int queryNum = query[i];
			if(queryNum != 0) 
				if(r[queryNum].use)
				{
					r[queryNum].hh < 10 ? (cout << "0" << r[queryNum].hh << ":")
						:(cout << r[queryNum].hh << ":");
					r[queryNum].mm < 10 ? (cout << "0" << r[queryNum].mm << endl)
						:(cout << r[queryNum].mm << endl);
				}	
				else cout << "Sorry" <<endl;
		}
		//输出
	}

}
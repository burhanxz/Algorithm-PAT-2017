#include <iostream>
#include<string>
#include <cstring>
#include <sstream>
#include <vector>
#include <algorithm>
#include <stdio.h>
#define INPUT
#define DEBUG
using namespace std;
int N,M;
string ns,ms;
struct Book
{
	string id;
	string title;
	string author;
	string keywords;
	string publisher;
	string published_year;
	Book(string _id,string _title,string _author,string _keywords,string _publisher,string _published_year):
	id(_id),title(_title),author(_author),keywords(_keywords),publisher(_publisher),published_year(_published_year){}
};
bool find_1(const Book& b,string s)//title
{
	return b.title == s;
}
bool find_2(const Book& b,string s)
{
	return b.author == s;
}
bool find_3(const Book& b,string s)//keywords
{
	string k(b.keywords);
	k.append(" ");
	s.append(" ");
	string::size_type pos = k.find(s);
	if(pos == k.npos) return false;
	return true;
}
bool find_4(const Book& b,string s)
{
	string k(b.publisher);
	k.append(" ");
	s.append(" ");
	string::size_type pos = k.find(s);
	if(pos == k.npos) return false;
	return true;
}
bool find_5(const Book& b,string s)
{
	return b.published_year == s;
}
vector<Book> books;
vector<int>outputNum;
int main()
{
#ifdef INPUT
	freopen("C:\\Users\\xuzhong\\Desktop\\pat\\input\\1022. Digital Library (30).txt","r",stdin);
#endif
	while (getline(cin,ns))
	{
		stringstream ss;ss << ns;ss >> N;ss.clear();ss.str("");ns.clear();
		string _id,_title, _author, _keywords, _publisher, _published_year;
		for(int i = 0;i != N;i++)
		{
			getline(cin,_id); 
			getline(cin,_title);
			getline(cin,_author);
			getline(cin,_keywords);
			getline(cin,_publisher);
			getline(cin,_published_year);
			books.push_back(Book(_id,_title, _author, _keywords, _publisher, _published_year));
			_id.clear();_title.clear();_author.clear();_keywords.clear();_publisher.clear();_published_year.clear();
		}
		getline(cin,ms);
		ss << ms;ss >> M;ss.clear();ss.str("");ms.clear();
		string s;
		for(int i = 0;i < M;i++)
		{
			getline(cin,s);
			cout << s << endl;
			char ch = s[0];
			string _s(s.begin() + 3,s.end());
			int SIZE = books.size();
			int n;
			outputNum.clear();
			switch(ch)
			{
				case '1': {
							for(int j = 0;j != SIZE;j++) 
							  if(find_1(books[j],_s)){ss << books[j].id;ss >> n;ss.clear();ss.str("");outputNum.push_back(n);}
							if(!outputNum.size()) cout << "Not Found" << endl;
							else 
							{
								sort(outputNum.begin(),outputNum.end());
								for(int j = 0;j != outputNum.size();j++) cout << outputNum[j] << endl;
							}
						  }
					break;
				case '2': {
							for(int j = 0;j != SIZE;j++) 
								if(find_2(books[j],_s)){ss << books[j].id;ss >> n;ss.clear();ss.str("");outputNum.push_back(n);}
							if(!outputNum.size()) cout << "Not Found" << endl;
							else 
							{
								sort(outputNum.begin(),outputNum.end());
								for(int j = 0;j != outputNum.size();j++) cout << outputNum[j] << endl;
							}
						  }
						  break;
				case '3': {
							for(int j = 0;j != SIZE;j++) 
								if(find_3(books[j],_s)){ss << books[j].id;ss >> n;ss.clear();ss.str("");outputNum.push_back(n);}
							if(!outputNum.size()) cout << "Not Found" << endl;
							else 
							{
								sort(outputNum.begin(),outputNum.end());
								for(int j = 0;j != outputNum.size();j++) cout << outputNum[j] << endl;
							}
						  }
						  break;
				case '4': {
							for(int j = 0;j != SIZE;j++) 
								if(find_4(books[j],_s)){ss << books[j].id;ss >> n;ss.clear();ss.str("");outputNum.push_back(n);}
							if(!outputNum.size()) cout << "Not Found" << endl;
							else 
							{
								sort(outputNum.begin(),outputNum.end());
								for(int j = 0;j != outputNum.size();j++) cout << outputNum[j] << endl;
							}
						  }
							break;
				case '5': {
							for(int j = 0;j != SIZE;j++) 
								if(find_5(books[j],_s)){ss << books[j].id;ss >> n;ss.clear();ss.str("");outputNum.push_back(n);}
							if(!outputNum.size()) cout << "Not Found" << endl;
							else 
							{
								sort(outputNum.begin(),outputNum.end());
								for(int j = 0;j != outputNum.size();j++) cout << outputNum[j] << endl;
							}
						  }
						  break;
			}
		}
		books.clear();
	}
#ifdef INPUT
	while (1){}
	fclose(stdin);
#endif
}
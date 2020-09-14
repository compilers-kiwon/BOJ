#include <iostream>
#include <string>
#include <map>
#include <set>

using namespace std;

typedef set<string> Member;

int N,M;
map<string,string> my_group;
map<string,Member> group_members;

void init(void)
{
	cin>>N>>M;
	
	for(int i=1;i<=N;i++)
	{
		string g;
		int num_of_members;
		
		cin>>g>>num_of_members;
		
		for(int j=1;j<=num_of_members;j++)
		{
			string name;
			
			cin>>name;
			
			my_group[name] = g;
			group_members[g].insert(name);
		}
	}
}

void print_members(string& name)
{
	set<string>::iterator it;
	
	for(it=group_members[name].begin();it!=group_members[name].end();it++)
	{
		cout<<*it<<'\n';
	}
}

int main(void)
{
	cin.sync_with_stdio(false);
	
	init();
	
	for(int i=1;i<=M;i++)
	{
		int p;
		string n;
		
		cin>>n>>p;
		
		if( p == 0 )
		{
			print_members(n);
		}
		else
		{
			cout<<my_group[n]<<'\n';
		}
	}
	
	return 0;
}

#include	<iostream>
#include	<queue>
#include	<stack>
#include	<map>
#include	<set>
#include	<string>

using namespace	std;

map< char,set<string> > never_heard_people;
priority_queue<string>	never_heard_seen_people;
stack<string>			answer;

int	main(void)
{
	int	N,M;
	
	cin>>N>>M;
	
	for(int i=1;i<=N;i++)
	{
		string	name;
		
		cin>>name;
		never_heard_people[name[0]].insert(name);
	}
	
	for(int i=1;i<=M;i++)
	{
		string	name;
		
		cin>>name;
		if( never_heard_people[name[0]].find(name) != never_heard_people[name[0]].end() )
		{
			never_heard_seen_people.push(name);
		}
	}
	
	while( never_heard_seen_people.size() != 0 )
	{
		answer.push(never_heard_seen_people.top());
		never_heard_seen_people.pop();
	}
	
	cout<<answer.size()<<'\n';
	
	while( answer.size() != 0 )
	{
		cout<<answer.top()<<'\n';
		answer.pop();
	}
	
	return	0;
}

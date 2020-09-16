#include	<iostream>
#include	<string>
#include	<queue>

using namespace	std;

#define	MAX_NUM_OF_WORKER	(1000000+1)

priority_queue<string>	enter[256];
priority_queue<string>	leave[256];

int	main(void)
{
	int	n;
	
	scanf("%d",&n);
	
	for(int i=1;i<=n;i++)
	{
		string	name,event;
		
		cin>>name>>event;
		
		if( event[0] == 'e' )
		{
			enter[name[0]].push(name);
		}
		else
		{
			leave[name[0]].push(name);
		}
	}
	
	for(char c='z';c>='a';c--)
	{
		while( !leave[c].empty() )
		{
			string e = enter[c].top();
			string l = leave[c].top();
			
			if( e == l )
			{
				leave[c].pop();
			}
			else
			{
				cout<<e<<'\n';
			}
			enter[c].pop();
		}
		
		while( !enter[c].empty() )
		{
			cout<<enter[c].top()<<'\n';
			enter[c].pop();
		}
	}
	
	for(char c='Z';c>='A';c--)
	{
		while( !leave[c].empty() )
		{
			string e = enter[c].top();
			string l = leave[c].top();
			
			if( e == l )
			{
				leave[c].pop();
			}
			else
			{
				cout<<e<<'\n';
			}
			enter[c].pop();
		}
		
		while( !enter[c].empty() )
		{
			cout<<enter[c].top()<<'\n';
			enter[c].pop();
		}
	}
	
	return	0;
}

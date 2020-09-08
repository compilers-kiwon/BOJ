#include	<iostream>
#include	<string>
#include	<queue>

using namespace std;

queue<int>	q;

int	main(void)
{
	int	T;
	
	cin>>T;
	
	while(T-->0)
	{
		string	instruction;
		int		n;
		
		cin>>instruction;
		
		if( instruction == "push")
		{
			cin>>n;
			q.push(n);
		}
		else if( instruction == "pop")
		{
			if( q.size() == 0 )
			{
				cout<<"-1\n";
			}
			else
			{
				cout<<q.front()<<endl;
				q.pop();
			}
		}
		else if( instruction == "size")
		{
			cout<<q.size()<<endl;
		}
		else if( instruction == "empty")
		{
			cout<<(q.size()?0:1)<<endl;
		}
		else if( instruction == "front")
		{
			cout<<(q.size()?q.front():-1)<<endl;
		}
		else if( instruction == "back" )
		{
			cout<<(q.size()?q.back():-1)<<endl;
		}
		else
		{
			*((int*)0x0) = 0xFFFFFFFF;
		}
	}
	return	0;
}

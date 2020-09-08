#include	<iostream>
#include	<deque>

using namespace	std;

deque<int>	dq;

int	main(void)
{
	int	N;
	
	cin>>N;
	
	for(int i=1;i<=N;i++)
	{
		string	instruction;
		int		X;
		
		cin>>instruction;
		
		if( instruction	== "push_front" )
		{
			cin>>X;
			dq.push_front(X);
		}
		else if( instruction == "push_back" )
		{
			cin>>X;
			dq.push_back(X);
		}
		else if( instruction == "pop_front" )
		{
			if( dq.size() == 0 )
			{
				X = -1;
			}
			else
			{
				X = dq.front();
				dq.pop_front();
			}
			cout<<X<<endl;
		}
		else if( instruction == "pop_back" )
		{
			if( dq.size() == 0 )
			{
				X = -1;
			}
			else
			{
				X = dq.back();
				dq.pop_back();
			}
			cout<<X<<endl;
		}
		else if( instruction == "size" )
		{
			cout<<dq.size()<<endl;
		}
		else if( instruction == "empty" )
		{
			cout<<dq.empty()<<endl;
		}
		else if( instruction == "front" )
		{
			if( dq.size() == 0 )
			{
				X = -1;
			}
			else
			{
				X = dq.front();
			}
			cout<<X<<endl;
		}
		else if( instruction == "back" )
		{
			if( dq.size() == 0 )
			{
				X = -1;
			}
			else
			{
				X = dq.back();
			}
			cout<<X<<endl;
		}
		
	}
	return	0;
}

#include	<iostream>
#include	<queue>

using namespace	std;

int	main(void)
{
	int			N;
	queue<int>	buffer;
	
	cin>>N;
	
	for(;;)
	{
		int	d;
		
		cin>>d;
		
		if( d == -1 )
		{
			break;
		}
		
		if( d == 0 )
		{
			buffer.pop();
		}
		else
		{
			if( buffer.size() < N )
			{
				buffer.push(d);
			}
		}
	}
	
	if( buffer.empty() )
	{
		cout<<"empty\n";
	}
	else
	{
		while( !buffer.empty() )
		{
			cout<<buffer.front()<<' ';
			buffer.pop();
		}
		cout<<"\n";
	}
	
	return	0;
}

#include	<iostream>

using namespace	std;

void	solve(int total)
{
	bool	found;
	
	found = false;
	
	for(int four=1;four*400<total;four++)
	{
		int	remain = total-400*four;
		
		for(int half=1;half*50<remain;half++)
		{
			if( (remain-half*50)%25 == 0 )
			{
				int quarter;
				
				quarter = (remain-half*50)/25;
				
				if( four+half+quarter == total/100 )
				{
					found = true;
					cout<<four<<" at four cents each\n";
					cout<<half<<" at two for a penny\n";
					cout<<quarter<<" at four for a penny\n\n";
				}
			}
		}
	}
	
	if( found == false )
	{
		cout<<"No solution found.\n\n";
	}
}

int		main(void)
{
	for(int i=1;;i++)
	{
		int	N;
		
		cin>>N;
		
		if( N == 0 )
		{
			break;
		}
		
		cout<<"Case "<<i<<":\n";
		cout<<N<<" pencils for "<<N<<" cents\n";
		
		solve(N*100);
	}
	
	return	0;
}

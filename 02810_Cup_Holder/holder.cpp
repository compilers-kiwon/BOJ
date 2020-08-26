#include	<iostream>
#include	<string>

using namespace	std;

int	main(void)
{
	int		N,cnt,i;
	string	seat;
	
	cin>>N>>seat;
	
	for(i=cnt=0;i<N;cnt++)
	{
		if( seat[i] == 'L' )
		{
			i += 2;
		}
		else
		{
			++i;
		}
	}
	
	cout<<min(N,cnt+1)<<endl;
	
	return	0;
}

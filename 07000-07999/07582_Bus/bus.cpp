#include	<iostream>
#include	<string>

using namespace	std;

void	simulate(const int& size,const int& num_of_stops,int& p)
{
	for(int i=1;i<=num_of_stops;i++)
	{
		int	off,on;
		
		cin>>off>>on;
		
		p = max(p-off,0);
		p = min(size,p+on);
	}
}

int		main(void)
{
	for(;;)
	{
		string	bus;
		int		Z,P,S;
		
		cin>>bus>>Z;
		
		if( bus=="#" && Z==0 )
		{
			break;
		}
		
		cin>>P>>S;
		simulate(Z,S,P);
		
		cout<<bus<<' '<<P<<'\n';
	}
	
	return	0;
}

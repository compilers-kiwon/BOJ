#include	<iostream>

using namespace	std;

#define	NUM_OF_MONTHS	12

const string	month[NUM_OF_MONTHS+1]
	= {"","Jan","Feb","Mar","Apr","May","Jun","Jul","Aug","Sep","Oct","Nov","Dec"};
	
int	main(void)
{
	for(int c=1;;c++)
	{
		int	N;
		
		cin>>N;
		
		if( N == 0 )
		{
			break;
		}
		
		string	graph[NUM_OF_MONTHS+1];
		
		for(int i=1;i<=N;i++)
		{
			int	d,m,y;
			
			cin>>d>>m>>y;
			graph[m].push_back('*');
		}
		
		cout<<"Case #"<<c<<":\n";
		
		for(int m=1;m<=NUM_OF_MONTHS;m++)
		{
			cout<<month[m]<<":"<<graph[m]<<'\n';
		}
	}
	
	return	0;
}

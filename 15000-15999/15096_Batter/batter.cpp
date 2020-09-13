#include	<iostream>

using namespace	std;

#define	WALK	-1

int	main(void)
{
	int	n,deno,total_number_of_bases;
	
	cin>>n;
	deno = total_number_of_bases = 0;
	
	for(int i=1;i<=n;i++)
	{
		int	b;
		
		cin>>b;
		
		if( b != WALK )
		{
			total_number_of_bases += b;
			deno++;
		}
	}
	
	cout<<(double)total_number_of_bases/(double)deno<<'\n';
	
	return	0;
}

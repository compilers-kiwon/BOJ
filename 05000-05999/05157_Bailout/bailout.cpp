#include	<iostream>

using namespace	std;

#define	MAX_NUM_OF_COMPANIES	(500+1)

int	main(void)
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	
	int	K;
	
	cin>>K;
	
	for(int k=1;k<=K;k++)
	{
		int		C,B,n,r,tax;
		bool	bailout[MAX_NUM_OF_COMPANIES];
		
		tax = 0;
		cin>>C>>B>>n>>r;
		
		fill(&bailout[1],&bailout[C+1],false);
		
		for(int i=1;i<=B;i++)
		{
			int	c;
			
			cin>>c;
			bailout[c] = true;
		}
		
		for(int i=1;i<=n;i++)
		{
			int	c,p;
			
			cin>>c>>p;
			
			if( bailout[c] == true )
			{
				tax += p*r/100;
			}
		}
		
		cout<<"Data Set "<<k<<":\n"<<tax<<"\n\n";
	}
	
	return	0;
}

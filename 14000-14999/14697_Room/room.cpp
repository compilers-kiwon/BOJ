#include	<iostream>

using namespace	std;

int	main(void)
{
	int		A,B,C,N;
	bool	found;
	
	cin>>A>>B>>C>>N;
	found = false;
	
	for(int i=0;i<=N/A;i++)
	{
		for(int j=0;j<=(N-A*i)/B;j++)
		{
			for(int k=0;k<=(N-A*i-B*j)/C;k++)
			{
				if( A*i+B*j+C*k == N )
				{
					found = true;
					break;
				}
			}
			
			if( found == true )
			{
				break;
			}
		}
		
		if( found == true )
		{
			break;
		}
	}
	
	cout<<found<<endl;
	
	return	0;
}

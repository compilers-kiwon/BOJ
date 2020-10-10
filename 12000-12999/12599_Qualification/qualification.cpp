#include	<iostream>

using namespace	std;

#define	MAX_SIZE	(60+1)

typedef	long long int	int64;

int64	P,C,S[MAX_SIZE];

int64	get_sum(void)
{
	int64	ret;
	
	ret = 0;
	
	for(int i=1;i<=P;i++)
	{
		ret += S[i];
	}
	
	return	ret;
}

void	input(void)
{
	cin>>P>>C;
	
	for(int i=1;i<=P;i++)
	{
		cin>>S[i];
	}
}

int		main(void)
{
	int	T;
	
	cin>>T;
	
	for(int t=1;t<=T;t++)
	{
		int64	advanced,sum;
		
		input();
		
		sum = get_sum();
		advanced = sum/C;
		
		for(;;)
		{
			bool	updated;
			int64	delta;
			
			updated = false;
			delta = 0;
			
			for(int i=1;i<=P;i++)
			{
				if( S[i] > advanced )
				{
					updated = true;
					delta += S[i]-advanced;
					S[i] = advanced;
					
				}
			}
			
			if( updated == false )
			{
				break;
			}
			
			sum -= delta;
			advanced = sum/C;
		}
		
		cout<<"Case #"<<t<<": "<<advanced<<'\n';
	}
	
	return	0;
}

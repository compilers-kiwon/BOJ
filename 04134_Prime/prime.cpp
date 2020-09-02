#include	<iostream>
#include	<map>
#include	<cmath>

using namespace	std;

typedef	unsigned int	uint32;

bool	is_prime(uint32 n,map<uint32,uint32>& sqrt_table)
{
	uint32	sqr,i;
	bool	flag;
	
	if( sqrt_table[n] != 0 )
	{
		sqr = sqrt_table[n];
	}
	else
	{
		sqr = sqrt(n);
		sqrt_table[n] = sqr;
	}
	
	for(i=2,flag=true;i<=sqr;i++)
	{
		if( n%i == 0 )
		{
			flag = false;
			break;
		}
	}
	
	return	flag;
}

int		main(void)
{
	int					t;
	map<uint32,uint32>	sqrt_table;
	
	cin>>t;
	
	while(t>0)
	{
		uint32	n,i;
		
		cin>>n;
		
		if( n < 2 )
		{
			cout<<"2\n";
		}
		else
		{
			for(i=n;;i++)
			{
				if( is_prime(i,sqrt_table) == true )
				{
					cout<<i<<endl;
					break;
				}
			}
		}
		
		t--;
	}
	return	0;
}

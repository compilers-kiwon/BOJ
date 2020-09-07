#include	<iostream>
#include	<vector>
#include	<algorithm>

using namespace	std;

bool	check_sum_of_divisors(int n,vector<int>& d)
{
	int	sum,to,i;
	
	sum = 1;
	d.push_back(1);
	
	for(i=2,to=n/i;i<to;i++,to=n/i)
	{
		if( n%i == 0 )
		{
			sum += i+to;
			d.push_back(i);
			d.push_back(to);
		}
	}
	
	if( i == to && n%i == 0 )
	{
		sum += i;
		d.push_back(i);
	}
	
	if( sum == n )
	{
		return	true;
	}
	return	false;
}

int		main(void)
{
	while(1)
	{
		vector<int>	divisor;
		int			n;
		
		cin>>n;
		
		if( n == -1 )
		{
			break;
		}
		
		if( check_sum_of_divisors(n,divisor) == true )
		{
			sort(divisor.begin(),divisor.end());
			
			cout<<n<<" = ";
			
			for(int i=0;i<divisor.size()-1;i++)
			{
				cout<<divisor[i]<<" + ";
			}
			cout<<divisor[divisor.size()-1]<<'\n';
		}
		else
		{
			cout<<n<<" is NOT perfect.\n";
		}
	}
	return	0;
}

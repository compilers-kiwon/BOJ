#include	<iostream>
#include	<queue>
#include	<cmath>

using namespace	std;

bool	get_divisor(int n,priority_queue<int>& d)
{
	int	sum;
	
	sum = 1;
	d.push(-1);
	
	for(int i=2;i<sqrt(n);i++)
	{
		if( n%i == 0 )
		{
			d.push(-i);
			d.push(-(n/i));
			sum += i+n/i;
		}
	}
	
	if( sqrt(n)*sqrt(n) == n )
	{
		d.push(-sqrt(n));
		sum += sqrt(n);
	}

	return	(sum==n);	
}

int		main(void)
{
	for(;;)
	{
		int	n;
		
		cin>>n;
		
		if( n == -1 )
		{
			break;
		}
		
		priority_queue<int>	divisors;
		
		if( get_divisor(n,divisors) == true )
		{
			cout<<n<<" = ";
			
			while( divisors.size() != 1 )
			{
				cout<<-divisors.top()<<" + ";
				divisors.pop();
			}
			cout<<-divisors.top()<<'\n';
		}
		else
		{
			cout<<n<<" is NOT perfect.\n";
		}
	}
	
	return	0;
}

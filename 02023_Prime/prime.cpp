#include	<iostream>
#include	<queue>
#include	<cmath>

using namespace	std;

#define	value		first
#define	digit_len	second

typedef	pair<int,int>	Number;

bool	is_prime(int n)
{
	bool	result;
	int		i,to;
	
	for(result=true,i=2,to=sqrt(n);i<=to;i++)
	{
		if( n%i == 0 )
		{
			result = false;
			break;
		}
	}
	
	return	result;
}

int		main(void)
{
	int				N;
	queue<Number>	prime_queue;
	
	cin>>N;
	
	for(int i=2;i<=9;i++)
	{
		if( is_prime(i) == true )
		{
			prime_queue.push(make_pair(i,1));
		}
	}
	
	while( prime_queue.size() != 0 )
	{
		Number	current_number;
		
		current_number = prime_queue.front();
		prime_queue.pop();
		
		if( current_number.digit_len == N )
		{
			cout<<current_number.value<<endl;
			continue;
		}
		
		for(int i=0;i<=9;i++)
		{
			Number	next_number;
			
			next_number.value = current_number.value*10+i;
			
			if( is_prime(next_number.value) == true )
			{
				next_number.digit_len = current_number.digit_len+1;
				prime_queue.push(next_number);
			}
		}
	}
	
	return	0;
}

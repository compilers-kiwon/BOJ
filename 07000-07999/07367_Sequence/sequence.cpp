#include	<iostream>
#include	<vector>

using namespace	std;

int	get_max_digit(int n)
{
	int	ret;
	
	for(ret=0;n>0;n/=10)
	{
		ret = max(ret,n%10);
	}
	
	return	ret;
}

int	convert(int n,int base)
{
	int	ret;
	
	ret = 0;
	
	for(int b=1;n>0;n/=10,b*=base)
	{
		ret += (n%10)*b;
	}
	
	return	ret;
}

int	main(void)
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	
	for(;;)
	{
		int	n;
		
		cin>>n;
		
		if( n == 0 )
		{
			break;
		}
		
		vector<int>	numbers;
		
		for(int i=1;i<=n;i++)
		{
			int	num;
			
			cin>>num;
			numbers.push_back(num);
		}
		
		int		max_digit_num,diff,base;
		bool	result;
		
		max_digit_num = 0;
		
		for(int i=0;i<n;i++)
		{
			max_digit_num = max(max_digit_num,get_max_digit(numbers[i]));
		}
		
		for(base=max_digit_num+1;base<=10;base++)
		{
			diff = convert(numbers[1],base)-convert(numbers[0],base);
			result = true;
			
			for(int i=2;i<n;i++)
			{
				if( diff != convert(numbers[i],base)-convert(numbers[i-1],base) )
				{
					result = false;
					break;
				}
			}
			
			if( result == true )
			{
				break;
			}
		}
		
		if( result == true )
		{
			cout<<"Minimum base = "<<base<<".\n";
		}
		else
		{
			cout<<"No base <= 10 can be found.\n";
		}
	}
	
	return	0;
}

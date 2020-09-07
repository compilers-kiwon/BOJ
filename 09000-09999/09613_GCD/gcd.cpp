#include	<iostream>
#include	<vector>

using namespace	std;

typedef	unsigned long long uint64;

uint64	get_gcd(uint64 a,uint64 b)
{
	uint64	big,small,mod;
	
	big = max(a,b);
	small = min(a,b);
	mod = big%small;
	
	while( mod != 0 )
	{
		big = small;
		small = mod;
		mod = big%small;
	}
	
	return	small;
}

uint64	get_sum_of_gcd(vector<uint64>& n,int size)
{
	uint64	gcd_sum;
	int		i,j;
	
	for(gcd_sum=0,i=0;i<size-1;i++)
	{
		for(j=i+1;j<size;j++)
		{
			gcd_sum += get_gcd(n[i],n[j]);
		}
	}
	
	return	gcd_sum;
}

int	main(void)
{
	int	t;
	
	cin>>t;
	
	while(t>0)
	{
		int			n;
				
		cin>>n;
		
		vector<uint64>	numbers(n);
		
		for(int i=0;i<n;i++)
		{
			cin>>numbers[i];
		}
		
		cout<<get_sum_of_gcd(numbers,n)<<endl;
		
		t--;
	}
	
	return	0;
}

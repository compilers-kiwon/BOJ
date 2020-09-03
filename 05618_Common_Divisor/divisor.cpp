#include	<iostream>
#include	<vector>

using namespace	std;

vector<int>	common_divisor;

void	get_common_divisor(int a,int b)
{
	int	small,big,to;
	
	small = min(a,b);
	big = max(a,b);
	to = small/2;
	
	common_divisor.push_back(1);
	
	for(int i=2;i<=to;i++)
	{
		if( a%i == 0 && b%i == 0 )
		{
			common_divisor.push_back(i);
		}
	}
	
	if( big%small == 0 )
	{
		common_divisor.push_back(small);
	}
}

int		main(void)
{
	int	n,n1,n2,n3;
	
	cin>>n>>n1>>n2;

	get_common_divisor(n1,n2);
	
	if( n == 2 )
	{
		for(int i=0,size=common_divisor.size();i<size;i++)
		{
			cout<<common_divisor[i]<<"\n";
		}
	}
	else
	{
		cin>>n3;
		
		for(int i=0,size=common_divisor.size();i<size;i++)
		{
			if( n3%common_divisor[i] == 0 )
			{
				cout<<common_divisor[i]<<"\n";
			}
		}
	}
	return	0;
}

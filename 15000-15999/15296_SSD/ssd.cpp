#include	<iostream>
#include	<vector>

using namespace	std;

typedef	unsigned int	uint32;

void	get_representation(uint32 n,uint32 b,vector<uint32>& digits)
{
	for(;n>0;n/=b)
	{
		digits.push_back(n%b);
	}
}

uint32	get_sum_of_squares(vector<uint32>& digits)
{
	uint32	ret;
	
	ret = 0;
	
	for(int i=0;i<digits.size();i++)
	{
		ret += digits[i]*digits[i];
	}
	
	return	ret;
}

uint32	SSD(uint32 b,uint32 n)
{
	vector<uint32>	d;
	
	get_representation(n,b,d);
	
	return	get_sum_of_squares(d);
}

int		main(void)
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	
	int	P;
	
	cin>>P;
	
	for(int i=1;i<=P;i++)
	{
		uint32	K,b,n;
		
		cin>>K>>b>>n;
		cout<<K<<' '<<SSD(b,n)<<'\n';
	}
	
	return	0;
}

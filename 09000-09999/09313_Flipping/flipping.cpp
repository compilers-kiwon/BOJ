#include	<iostream>
#include	<vector>

using namespace	std;

typedef	unsigned int	uint32;

void	convert_uint32_to_reverse_bin(uint32 n,vector<uint32>& bin)
{
	for(int i=0;i<32;i++)
	{
		bin.push_back((n>>i)&0x1);
	}
}

uint32		convert_bin_to_uint32(vector<uint32>& bin)
{
	uint32	n,ret;
	
	n = 1;
	ret = 0;
	
	for(int i=31;i>=0;i--)
	{
		ret += n*bin[i];
		n *= 2;
	}
	
	return	ret;
}

int		main(void)
{
	for(;;)
	{
		int				n;
		vector<uint32>	b;
		
		cin>>n;
		
		if( n == -1 )
		{
			break;
		}
		
		convert_uint32_to_reverse_bin((uint32)n,b);
		cout<<convert_bin_to_uint32(b)<<'\n';
	}
	
	return	0;
}

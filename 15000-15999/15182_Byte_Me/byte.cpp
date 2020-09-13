#include	<iostream>
#include	<string>

using namespace	std;

#define	MAX_BYTES			(10+1)
#define	BIT_LEN_FOR_BYTE	8

int	num_of_1_bits(char* s)
{
	int	ret;
	
	ret = 0;
	
	for(int i=1;i<=BIT_LEN_FOR_BYTE;i++,s++)
	{
		if( *s == '1' )
		{
			ret++;
		}
	}
	
	return	ret;
}

int	main(void)
{
	int		N,corrupted_byte,corrupted_bit;
	char	data[MAX_BYTES][BIT_LEN_FOR_BYTE+1];
	char	parity_byte[BIT_LEN_FOR_BYTE+1];
	string	p;
	
	cin>>N;
	
	for(int byte=1;byte<=N;byte++)
	{
		for(int bit=1;bit<=BIT_LEN_FOR_BYTE;bit++)
		{
			cin>>data[byte][bit];
		}
	}
	
	for(int bit=1;bit<=BIT_LEN_FOR_BYTE;bit++)
	{
		cin>>parity_byte[bit];
	}
	
	int	num_of_even_bytes,num_of_odd_bytes,even_byte,odd_byte;
	
	num_of_even_bytes = num_of_odd_bytes = 0;
	
	for(int b=1;b<=N;b++)
	{
		if( num_of_1_bits(&data[b][1])%2 == 0 )
		{
			num_of_even_bytes++;
			even_byte = b;
		}
		else
		{
			num_of_odd_bytes++;
			odd_byte = b;
		}
	}
	
	if( num_of_even_bytes == 1 )
	{
		p = "Odd";
		corrupted_byte = even_byte;
	}
	else
	{
		p = "Even";
		corrupted_byte = odd_byte;
	}
	
	for(int bit=1;bit<=BIT_LEN_FOR_BYTE;bit++)
	{
		int	cnt;
		
		cnt = (parity_byte[bit]=='1'?1:0);
		
		for(int byte=1;byte<=N;byte++)
		{
			if( data[byte][bit] == '1' )
			{
				cnt++;
			}
		}
		
		if( (p=="Odd"&&cnt%2==0) || (p=="Even"&&cnt%2==1) )
		{
			corrupted_bit = bit;
			break;
		}
	}
	
	cout<<p<<"\nByte "<<corrupted_byte<<" is broken\nBit "<<corrupted_bit<<" is broken\n";
	
	return	0;
}

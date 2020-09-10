#include	<iostream>
#include	<string>

using namespace	std;

int	hex2dec(string hex)
{
	int	value,i;
	
	for(i=2,value=0;i<hex.length();i++)
	{
		char	c;
		
		c = hex[i];
		
		if( c>='0' && c<='9' )
		{
			value = value*16+(int)(c-'0');
		}
		else
		{
			value = value*16+10+(int)(c-'a');
		}
		
	}
	return	value;
}

int	oct2dec(string oct)
{
	int	value,i;
	
	for(i=1,value=0;i<oct.length();i++)
	{
		value = value*8+(int)(oct[i]-'0');
	}
	return	value;
}

int	dec2dec(string dec)
{
	int	value,i;
	
	for(i=0,value=0;i<dec.length();i++)
	{
		value = value*10+(int)(dec[i]-'0');
	}
	return	value;
}

int	main(void)
{
	string	num;
	int		dec;
	
	cin>>num;
	
	if( num[0] == '0' )
	{
		if( num[1] == 'x' )
		{
			dec = hex2dec(num);
		}
		else
		{
			dec = oct2dec(num);
		}
	}
	else
	{
		dec = dec2dec(num);
	}
	
	cout<<dec<<endl;
	
	return	0;
}

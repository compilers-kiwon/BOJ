#include	<iostream>
#include	<string>

using namespace	std;

int	main(void)
{
	while(1)
	{
		string	bit;
		int		num_of_ones,i;
		
		cin>>bit;
		
		if( bit == "#" )
		{
			break;
		}
		
		for(i=num_of_ones=0;i<bit.length()-1;i++)
		{
			if( bit[i] == '1' )
			{
				++num_of_ones;
			}
		}
		
		if( (bit[bit.length()-1] == 'e' && num_of_ones%2 == 0) || (bit[bit.length()-1] == 'o' && num_of_ones%2 == 1) )
		{
			bit[bit.length()-1] = '0';
		}
		else
		{
			bit[bit.length()-1] = '1';
		}
		cout<<bit<<endl;
	}
	
	return	0;
}

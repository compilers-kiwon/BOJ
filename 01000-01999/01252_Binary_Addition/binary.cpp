#include	<iostream>
#include	<string>

using namespace	std;

int		main(void)
{
	string	bin1,bin2,bin3;
	int		bin1_len,bin2_len;
	
	cin>>bin1>>bin2;
	
	bin1_len = bin1.length();
	bin2_len = bin2.length();
	
	if( bin1_len < bin2_len )
	{
		for(int i=0;i<bin2_len-bin1_len;i++)
		{
			bin1.insert(bin1.begin(),'0');
		}
	}
	else
	{
		for(int i=0;i<bin1_len-bin2_len;i++)
		{
			bin2.insert(bin2.begin(),'0');
		}
	}
	
	int	c,i;
	
	for(i=bin1.length()-1,c=0;i>=0;i--)
	{
		int 	b1,b2,sum;
		char	n;
		
		b1 = (int)(bin1[i]-'0');
		b2 = (int)(bin2[i]-'0');
		
		sum = b1+b2+c;
		
		c = sum/2;
		n = (char)((int)'0'+sum%2);
		
		bin3.insert(bin3.begin(),n);
	}
	
	if( c == 1 )
	{
		bin3.insert(bin3.begin(),'1');	
	}
	
	int pos;
	
	for(pos=0;pos<bin3.length();pos++)
	{
		if( bin3[pos] == '1' )
		{
			break;
		}
	}
	
	if( pos == bin3.length() )
	{
		cout<<"0\n";
	}
	else
	{
		for(;pos<bin3.length();pos++)
		{
			cout<<bin3[pos];
		}
		cout<<endl;
	}
	return	0;
}

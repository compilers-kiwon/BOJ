#include	<iostream>
#include	<string>

using namespace std;

int		digit_count[10];
string	N;

int		main(void)
{
	cin>>N;
	
	for(int i=0;i<N.length();i++)
	{
		int	digit;
		
		digit = (int)N[i]-(int)'0';
		
		if( digit == 9 )
		{
			digit = 6;
		}
		++digit_count[digit];
	}
	
	int	max_digit = 0;
	
	digit_count[6] = (digit_count[6]+1)/2;
	
	for(int i=0;i<=8;i++)
	{
		max_digit = max(max_digit,digit_count[i]);
	}
	cout<<max_digit<<endl;
	
	return	0;
}

#include	<iostream>
#include	<string>

using namespace	std;

#define	CARD_NUMBER_LEN	16
#define	char2int(c)		((int)((c)-'0'))
#define	int2char(i)		((char)((i)+(int)'0'))

const string	answer[2] = {"Yes","No"};

#define	VALID	0
#define	INVALID	1

#define	is_valid(n)	(((n)%10==0)?VALID:INVALID)

int	multiply_odd_labeled_digit_by_2(string& number)
{
	int	sum;
	
	sum = 0;
	
	for(int i=1;i<CARD_NUMBER_LEN;i+=2)
	{
		int	n;
		
		n = char2int(number[i])*2;
		
		if( n > 9 )
		{
			n -= 9;
		}
		
		sum += n;
	}
	
	return	sum;
}

int	get_sum_of_all_even_labeled_digits(string& number)
{
	int	sum;
	
	sum = 0;
	
	for(int i=0;i<CARD_NUMBER_LEN;i+=2)
	{
		sum += char2int(number[i]);
	}
	
	return	sum;
}

int	main(void)
{
	for(;;)
	{
		string	number;
		
		for(int i=1;i<=4;i++)
		{
			string	n;
			
			cin>>n;
			number += n;	
		}
		
		if( number == "0000000000000000" )
		{
			break;
		}
		
		for(int h=0,t=CARD_NUMBER_LEN-1;h<t;h++,t--)
		{
			swap(number[h],number[t]);
		}
		
		int	s1,s2;
		
		s1 = multiply_odd_labeled_digit_by_2(number);
		s2 = get_sum_of_all_even_labeled_digits(number);
		
		cout<<answer[is_valid(s1+s2)]<<'\n';
	}
	
	return	0;
}

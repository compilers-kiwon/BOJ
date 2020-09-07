#include	<iostream>
#include	<string>

using namespace	std;

#define	char2int(c)	((int)((c)-'0'))

bool	check_num(int head,int tail,string& number,int tail_first_index)
{
	if( head == tail )
	{
		return	true;
	}
	
	if( tail_first_index == number.length()-1 )
	{
		return	false;
	}
	
	int	n;
	
	n = char2int(number[tail_first_index]);
	
	return	check_num(head*n,tail/n,number,tail_first_index+1);
}

int		main(void)
{
	string	number;
	int		head,tail,i,num_of_zero;
	
	cin>>number;
	
	if( number.length() == 1 )
	{
		cout<<"NO\n";
		return	0;
	}
	
	for(i=num_of_zero=0;i<number.length();i++)
	{
		if( number[i] == '0' )
		{
			num_of_zero++;
		}
	}
	
	if( num_of_zero != 0 )
	{
		if( num_of_zero != 1 )
		{
			cout<<"YES\n";
		}
		else
		{
			cout<<"NO\n";
		}
		
		return	0;
	}
	
	head = char2int(number[0]);
	
	for(tail=1,i=1;i<number.length();i++)
	{
		tail *= char2int(number[i]);
	}
	
	if( check_num(head,tail,number,1) == true )
	{
		cout<<"YES\n";
	}
	else
	{
		cout<<"NO\n";
	}
	
	return	0;
}

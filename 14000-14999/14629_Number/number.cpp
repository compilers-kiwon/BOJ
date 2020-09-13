#include	<iostream>
#include	<cmath>
#include	<string>

using namespace	std;

typedef	long long int	int64;

int64	in_number;
int		number_len;
bool	used[10];

void	find_number(int64 out_number,int current_digit,int64& min_diff_num,int64& min_diff)
{
	if( current_digit > number_len )
	{
		int64	tmp_diff;
		
		tmp_diff = abs(in_number-out_number);
		
		if( (tmp_diff<min_diff) || (tmp_diff==min_diff&&out_number<min_diff_num) )
		{
			min_diff_num = out_number;
			min_diff = tmp_diff;
		}
		
		return;
	}
	
	for(int64 i=0;i<10;i++)
	{
		if( used[i] == false )
		{
			used[i] = true;
			find_number(out_number*10+i,current_digit+1,min_diff_num,min_diff);
			used[i] = false;
		}
	}
}

int		main(void)
{
	string	N;
	
	cin>>N;
	
	number_len = min(10,(int)(N.length()));
	
	for(int i=0;i<N.length();i++)
	{
		in_number = in_number*10+(int64)(N[i]-'0');
	}
	
	int64	min_diff_num,min_diff;
	
	min_diff_num = min_diff = 2000000000000;
	
	find_number(0,1,min_diff_num,min_diff);
	
	cout<<min_diff_num<<'\n';
	
	return	0;
}

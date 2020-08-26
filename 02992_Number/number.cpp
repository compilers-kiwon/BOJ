#include	<iostream>

using namespace	std;

#define	MAX_DIGIT	(6+1)

void	find_min_num(int origin_num,int current_value,int current_digit,
					 int& min_num,int digit_len,int* each_num,bool* used)
{
	if( current_digit > digit_len )
	{
		if( current_value > origin_num )
		{
			min_num = min(min_num,current_value);
		}
		return;
	}
	
	for(int i=1;i<=digit_len;i++)
	{
		if( used[i] == false )
		{
			used[i] = true;
			find_min_num(origin_num,current_value*10+each_num[i],
						 current_digit+1,min_num,digit_len,each_num,used);
			used[i] = false;
		}
	}
}

int		main(void)
{
	int		X,each_num[MAX_DIGIT];
	int		digit_len,min_num;
	bool	used[MAX_DIGIT];
	
	cin>>X;
	
	digit_len = 0;
	
	for(int n=X;n>0;n/=10)
	{
		each_num[++digit_len] = n%10;
		used[digit_len] = false;
	}
	
	min_num = 0x7FFFFFFF;
	
	find_min_num(X,0,1,min_num,digit_len,each_num,used);
	
	if( min_num == 0x7FFFFFFF )
	{
		min_num = 0;
	}
	
	cout<<min_num<<endl;
	
	return	0;
}

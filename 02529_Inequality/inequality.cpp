#include	<iostream>
#include	<vector>

using namespace	std;

#define	MAX_DIGIT	10

typedef	unsigned long long	uint64;

vector<bool>	used(MAX_DIGIT,false);
vector<char>	inequality;
int				k;

void	find_number(int current_inequality_index,uint64 current_value,uint64& min_num,uint64& max_num)
{
	if( current_inequality_index == k )
	{
		min_num = min(min_num,current_value);
		max_num = max(max_num,current_value);
		
		return;
	}
	
	int	last_number;
	
	last_number = (int)(current_value%10);
	
	if( inequality[current_inequality_index] == '>' )
	{
		for(int i=last_number-1;i>=0;i--)
		{
			if( used[i] == false )
			{
				used[i] = true;
				find_number(current_inequality_index+1,current_value*10+(uint64)i,min_num,max_num);
				used[i] = false;
			}
		}
	}	
	else
	{
		for(int i=last_number+1;i<=9;i++)
		{
			if( used[i] == false )
			{
				used[i] = true;
				find_number(current_inequality_index+1,current_value*10+(uint64)i,min_num,max_num);
				used[i] = false;
			}
		}
	}
}

int		main(void)
{
	cin>>k;
	
	for(int i=1;i<=k;i++)
	{
		char	c;
		
		cin>>c;
		inequality.push_back(c);
	}
	
	uint64	min_num,max_num;
	
	min_num = 9999999999;
	max_num = 0;
	
	if( inequality[0] == '>' )
	{
		for(int i=9;i>=1;i--)
		{
			used[i] = true;
			find_number(0,i,min_num,max_num);
			used[i] = false;	
		}	
	}
	else
	{
		for(int i=0;i<=8;i++)
		{
			used[i] = true;
			find_number(0,i,min_num,max_num);
			used[i] = false;
		}
	}
	
	uint64	d,t;
	
	d = 1;
	
	for(int i=1;i<=k;i++)
	{
		d = d*10;
	}
	
	t =d;
	
	for(int i=1;i<=k+1;i++)
	{
		cout<<max_num/t;
		max_num %= t;
		t /= 10;
	}
	cout<<endl;
	
	t = d;
	
	for(int i=1;i<=k+1;i++)
	{
		cout<<min_num/t;
		min_num %= t;
		t /= 10;
	}
	cout<<endl;
	
	return	0;	
}

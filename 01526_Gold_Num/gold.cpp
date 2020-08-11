#include	<iostream>

using namespace	std;

#define	MAX_NUM	(1000000+1)

bool	gold_num[MAX_NUM];

void	check_gold_num(int digit,int index)
{
	if( digit == 6 )
	{
		return;
	}
	
	int	shift_index = index*10;
	
	gold_num[shift_index+4] = true;
	check_gold_num(digit+1,shift_index+4);
	
	gold_num[shift_index+7] = true;
	check_gold_num(digit+1,shift_index+7);
}

int		main(void)
{
	gold_num[4] = true;
	check_gold_num(1,4);
	
	gold_num[7] = true;
	check_gold_num(1,7);
	
	int	N;
	
	cin>>N;
	
	for(int i=N;i>=4;i--)
	{
		if( gold_num[i] == true )
		{
			cout<<i<<endl;
			break;
		}
	}
	return	0;
}

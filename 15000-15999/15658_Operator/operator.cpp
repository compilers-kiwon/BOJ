#include	<iostream>

using namespace	std;

#define	MAX_NUM_OF_NUMS	(11+1)

#define	ADD		0
#define	SUB		1
#define	MUL		2
#define	DIV		3
#define	MAX_OP	4

int	N,numbers[MAX_NUM_OF_NUMS],op_cnt[MAX_OP];

void	do_operation(int num_index,int current_value,int& max_value,int& min_value)
{
	if( num_index > N )
	{
		max_value = max(max_value,current_value);
		min_value = min(min_value,current_value);
		
		return;
	}
	
	for(int i=ADD;i<=DIV;i++)
	{
		if( op_cnt[i] > 0 )
		{
			int	tmp;
			
			switch(i)
			{
				case	ADD:
					tmp = current_value+numbers[num_index];
					break;
				case	SUB:
					tmp = current_value-numbers[num_index];
					break;
				case	MUL:
					tmp = current_value*numbers[num_index];
					break;
				case	DIV:
					tmp = current_value/numbers[num_index];
					break;
			}
			
			op_cnt[i]--;
			do_operation(num_index+1,tmp,max_value,min_value);
			op_cnt[i]++;
		}
		
	}
}

int		main(void)
{
	cin>>N;
	
	for(int i=1;i<=N;i++)
	{
		cin>>numbers[i];
	}
	
	for(int i=ADD;i<=DIV;i++)
	{
		cin>>op_cnt[i];
	}
	
	int	min_value,max_value;
	
	min_value = 1000000001;
	max_value = -1000000001;
	
	do_operation(2,numbers[1],max_value,min_value);
	
	cout<<max_value<<'\n'<<min_value<<'\n';
	
	return	0;
}

#include	<iostream>

using namespace	std;

#define	MAX_NUM_OF_NUMBERS	11

#define	ADD		0
#define	SUB		1
#define	MUL		2
#define	DIV		3
#define	MAX_OP	4

void	do_operation(int index,int num_of_numbers,int* op_list,int* numbers,
					 int result,int& max_result,int& min_result)
{
	if( index == num_of_numbers )
	{
		max_result = max(max_result,result);
		min_result = min(min_result,result);
		
		return;
	}
	
	int&	current_num = numbers[index];
	int		tmp;
	
	if( op_list[ADD] != 0 )
	{
		op_list[ADD]--;
		do_operation(index+1,num_of_numbers,op_list,numbers,result+current_num,max_result,min_result);
		op_list[ADD]++;
	}
	
	if( op_list[SUB] != 0 )
	{
		op_list[SUB]--;
		do_operation(index+1,num_of_numbers,op_list,numbers,result-current_num,max_result,min_result);
		op_list[SUB]++;
	}
	
	if( op_list[MUL] != 0 )
	{
		op_list[MUL]--;
		do_operation(index+1,num_of_numbers,op_list,numbers,result*current_num,max_result,min_result);
		op_list[MUL]++;
	}
	
	if( op_list[DIV] != 0 )
	{
		op_list[DIV]--;
		
		if( result < 0 )
		{
			tmp = (-result)/current_num;
			tmp = -tmp;
		}
		else
		{
			tmp = result/current_num;
		}
		do_operation(index+1,num_of_numbers,op_list,numbers,tmp,max_result,min_result);
		
		op_list[DIV]++;
	}
}

int		main(void)
{
	int	N,numbers[MAX_NUM_OF_NUMBERS],op_num[MAX_OP];
	int	max_result,min_result;
	
	cin>>N;
	
	for(int i=0;i<N;i++)
	{
		cin>>numbers[i];
	}
	
	for(int op=ADD;op<=DIV;op++)
	{
		cin>>op_num[op];
	}
	
	max_result = -1000000000;
	min_result = 1000000000;
	
	do_operation(1,N,op_num,numbers,numbers[0],max_result,min_result);
	
	cout<<max_result<<endl<<min_result<<endl;
	
	return	0;
}

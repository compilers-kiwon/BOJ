#include	<iostream>
#include	<string>

using namespace	std;

#define	get_operand(o)	(((o)=="true")?true:false)

const string	result[2] = {"false","true"};

int	main(void)
{
	string	left,right,op;
	bool	operand_1,operand_2,ret;
	
	cin>>left>>op>>right;
	operand_1 = get_operand(left);
	operand_2 = get_operand(right);
	
	if( op == "AND" )
	{
		ret = operand_1 & operand_2;
	}
	else
	{
		ret = operand_1 | operand_2;
	}
	cout<<result[ret]<<'\n';
	
	return	0;
}

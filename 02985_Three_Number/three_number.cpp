#include	<iostream>

using namespace	std;

#define	EQU		0
#define	ADD		1
#define	SUB		2
#define	MUL		3
#define	DIV		4
#define	MAX_OP	5

int	do_operation(int n1,int n2,int op)
{
	int	result;
	
	switch(op)
	{
		case	ADD:
			result = n1+n2;
			break;
		case	SUB:
			result = n1-n2;
			break;
		case	MUL:
			result = n1*n2;
			break;
		case	DIV:
			result = n1/n2;
			break;
		default:
			break;
	}
	
	return	result;
}

int	main(void)
{
	char	operator_char[MAX_OP] = {'=','+','-','*','/'};
	int		a,b,c,op1,op2;
	bool	result;
	
	cin>>a>>b>>c;
	
	for(op1=EQU,op2=ADD;op2<=DIV;op2++)
	{
		result = (a==do_operation(b,c,op2))?true:false;
		
		if( result == true )
		{
			break;
		}
	}
	
	if( result != true )
	{
		for(op2=EQU,op1=ADD;op1<=DIV;op1++)
		{
			result = (c==do_operation(a,b,op1))?true:false;
			
			if( result == true )
			{
				break;
			}
		}
	}
	
	cout<<a<<operator_char[op1]<<b<<operator_char[op2]<<c<<endl;
	
	return	0;
}

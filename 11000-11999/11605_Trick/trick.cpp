#include	<iostream>
#include	<vector>

using namespace	std;

typedef	pair<int,int>	Operation;

#define	operator	first
#define	operand		second

#define	ADD			0
#define	SUBTRACT	1
#define	MULTIPLY	2
#define	DIVIDE		3

#define	MAX_NUM		100

void	input(int& num_of_operations,vector<Operation>& v)
{
	cin>>num_of_operations;
	
	for(int i=1;i<=num_of_operations;i++)
	{
		string		a;
		Operation	o;
		
		cin>>a>>o.operand;
		
		if( a == "SUBTRACT" )
		{
			o.operator = SUBTRACT; 
		}
		else if( a == "ADD" )
		{
			o.operator = ADD; 
		}
		else if( a == "MULTIPLY" )
		{
			o.operator = MULTIPLY; 
		}
		else
		{
			o.operator = DIVIDE; 
		}
		
		v.push_back(o);
	}
}

bool	is_messed_up(vector<Operation>& op,int n)
{
	bool	ret;
	
	ret = false;
	
	for(int i=0;i<op.size()&&ret!=true;i++)
	{
		int	result;
		
		switch(op[i].operator)
		{
			case	ADD:
				result = n+op[i].operand;
				break;
			case	SUBTRACT:
				result = n-op[i].operand;
				if( result < 0 ) ret = true;
				break;
			case	MULTIPLY:
				result = n*op[i].operand;
				break;
			case	DIVIDE:
				result = n/op[i].operand;
				if( result*op[i].operand != n ) ret = true;
				break;
			default:
				// do nothing
				break;
		}
		
		n = result;
	}
	
	return	ret;
}

int		main(void)
{
	int					n,cnt;
	vector<Operation>	op;
	
	cnt = 0;
	input(n,op);
	
	for(int i=1;i<=MAX_NUM;i++)
	{
		if( is_messed_up(op,i) == true )
		{
			cnt++;
		}
	}
	
	cout<<cnt<<'\n';
	
	return	0;
}

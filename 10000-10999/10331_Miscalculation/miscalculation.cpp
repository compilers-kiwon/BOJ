#include	<iostream>
#include	<string>
#include	<vector>

using namespace	std;

#define	MUL	-1
#define	ADD	-2

#define	char2int(c)			((int)((c)-'0'))
#define	IN_RANGE(MIN,n,MAX)	((MIN)<=(n)&&(n)<=(MAX))
	
void	parse_expression(string& str,vector<int>& st)
{
	int	i;
	
	for(i=0;i<str.length();i++)
	{
		int	value;
		
		if( IN_RANGE('0',str[i],'9') == true )
		{
			value = char2int(str[i]);
		}
		else
		{
			if( str[i] == '+' )
			{
				value = ADD;
			}
			else
			{
				value = MUL;
			}
		}
		
		st.push_back(value);
	}
}

void	calculate(vector<int>& expression,int& left_to_right_result,int& mul_first_result)
{
	int	op;
	
	// 1. do left->right
	left_to_right_result = 0;
	op = ADD;
	
	for(int i=0;i<expression.size();i++)
	{
		if( IN_RANGE(0,expression[i],9) == true )
		{
			if( op == ADD )
			{
				left_to_right_result += expression[i];
			}
			else
			{
				left_to_right_result *= expression[i];
			}
		}
		else
		{
			op = expression[i];
		}
	}
	
	// 2. do mul-first
	vector<int>	tmp;
	
	op = ADD;
	
	for(int i=0;i<expression.size();i++)
	{
		if( IN_RANGE(0,expression[i],9) == true )
		{
			if( op == ADD )
			{
				tmp.push_back(expression[i]);
			}
			else
			{
				int	n;
				
				n = tmp.back();
				tmp.pop_back();
				tmp.push_back(n*expression[i]);
			}
		}
		else
		{
			op = expression[i];
		}
	}
	
	mul_first_result = 0;
	
	for(int i=0;i<tmp.size();i++)
	{
		mul_first_result += tmp[i];
	}
}

int		main(void)
{
	vector<int>	exp;
	string		str;
	int			input_result,left_to_right,mul_first;
	char		result;
	
	cin>>str>>input_result;
	parse_expression(str,exp);
	calculate(exp,left_to_right,mul_first);
	
	if( input_result == mul_first && input_result != left_to_right )
	{
		result = 'M';
	}
	else if( input_result != mul_first && input_result == left_to_right )
	{
		result = 'L';
	}
	else if( input_result == mul_first && input_result == left_to_right )
	{
		result = 'U';
	}
	else
	{
		result = 'I';
	}
	
	cout<<result<<'\n';
	
	return	0;
}

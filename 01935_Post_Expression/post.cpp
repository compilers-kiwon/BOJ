#include	<iostream>
#include	<stack>
#include	<string>
#include	<map>

using namespace	std;

int	main(void)
{
	map<char,double>	variable;
	string				expression;
	stack<double>		value;
	int					N,i;
	char				c;
	
	cin>>N>>expression;
	
	for(i=1,c='A';i<=N;i++,c++)
	{
		cin>>variable[c];
	}
	
	for(i=0;i<expression.length();i++)
	{
		double	first,second,result;
		
		switch(expression[i])
		{
			case	'+':
				second = value.top();value.pop();
				first = value.top();value.pop();
				result = first+second;
				break;
			case	'-':
				second = value.top();value.pop();
				first = value.top();value.pop();
				result = first-second;
				break;
			case	'/':
				second = value.top();value.pop();
				first = value.top();value.pop();
				result = first/second;
				break;
			case	'*':
				second = value.top();value.pop();
				first = value.top();value.pop();
				result = first*second;
				break;
			default:
				result = variable[expression[i]];
				break;
		}
		
		value.push(result);
	}
	
	printf("%.2f\n",value.top());
	
	return	0;
}

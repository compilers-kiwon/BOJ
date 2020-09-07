#include	<iostream>
#include	<string>
#include	<stack>

using namespace	std;

#define	PAREN				-1
#define	char2int(c)			((int)((c)-'0'))
#define	IN_RANGE(MIN,n,MAX)	((MIN)<=(n) && (n)<=(MAX))

void	solve_exp(string& exp,stack<int>& st)
{
	for(int i=0;i<exp.length();i++)
	{
		char&	c = exp[i];
		int		value;
		
		switch(c)
		{
			case	'H':
				value = 1;
				break;
			case	'C':
				value = 12;
				break;
			case	'O':
				value = 16;
				break;
			case	'(':
				value = PAREN;
				break;
			case	')':
				for(value=0;st.top()!=PAREN;st.pop())
				{
					value += st.top();
				}
				st.pop();
				break;
			default:
				if( IN_RANGE('2',c,'9') )
				{
					value = st.top();
					st.pop();
					value *= char2int(c);
				}
				else
				{
					*((int*)0x0) = 1;
				}
				break;
		}
		st.push(value);
	}
}

int		main(void)
{
	string		exp;
	stack<int>	st;
	int			sum;
	
	cin>>exp;
	solve_exp(exp,st);
	sum = 0;
	
	while( !st.empty() )
	{
		sum += st.top();
		st.pop();
	}
	
	cout<<sum<<endl;
	
	return	0;
}

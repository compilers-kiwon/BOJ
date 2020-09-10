#include	<iostream>
#include	<string>
#include	<vector>

using namespace	std;

#define	char2int(c)			((int)((c)-'0'))
#define	IN_RANGE(MIN,n,MAX)	((MIN)<=(n)&&(n)<=(MAX))

int		add(vector<int>& v)
{
	int	ret;
	
	ret = 0;

	for(int i=0;i<v.size();i++)
	{
		ret += v[i];	
	}
	
	return	ret;	
}

int		mul(vector<int>& v)
{
	int	ret;
	
	ret = 1;
	
	for(int i=0;i<v.size();i++)
	{
		ret *= v[i];	
	}
	
	return	ret;	
}

int		calulate(vector<string>& exp,int& ptr)
{
	string&	current = exp[ptr];
	char	token;
	int		depth;
	
	depth = current.length();
	token = current[depth-1];
	ptr++;
	
	if( IN_RANGE('0',token,'9') == true )
	{
		return	char2int(token);
	}
	
	vector<int>	operand;
	
	for(;ptr<exp.size()&&exp[ptr].length()>depth;)
	{
		operand.push_back(calulate(exp,ptr));
	}
	
	int	ret;
	
	if( token == '+' )
	{
		ret = add(operand);
	}
	else
	{
		ret = mul(operand);
	}
	
	return	ret;
}

bool	input(int& exp_size,vector<string>& exp)
{
	cin>>exp_size;
	
	if( exp_size == 0 )
	{
		return	false;
	}
	
	for(int i=1;i<=exp_size;i++)
	{
		string	s;
		
		cin>>s;
		exp.push_back(s);
	}
	
	return	true;
}

int		main(void)
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	
	for(;;)
	{
		int				n,result,ptr;
		vector<string>	exp;
		
		if( input(n,exp) == false )
		{
			break;
		}
		
		ptr = 0;
		cout<<calulate(exp,ptr)<<'\n';
	}
	
	return	0;
}

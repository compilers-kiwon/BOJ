#include	<iostream>
#include	<string>

using namespace	std;

#define	MIN_LEN				6
#define	NONE				0
#define	IN_RANGE(MIN,n,MAX)	((MIN)<=(n)&&(n)<=(MAX))

bool	check_password(const string& str,int from,int to)
{
	bool	upper,lower,digit;
	
	upper = lower = digit = false;
	
	for(int i=from;i<=to;i++)
	{		
		if( IN_RANGE('A',str[i],'Z') )
		{
			upper = true;
		}
		
		if( IN_RANGE('a',str[i],'z') )
		{
			lower = true;
		}
		
		if( IN_RANGE('0',str[i],'9') )
		{
			digit = true;
		}
	}
	
	return	(upper&&lower&&digit);
}

int		find_sub_str(const string& str)
{
	int	ret;
	
	ret = NONE;
	
	for(int l=MIN_LEN;l<=str.length()&&ret==NONE;l++)
	{
		for(int i=0;i<=str.length()-l;i++)
		{
			if( check_password(str,i,i+l-1) == true )
			{
				ret = l;
				break;
			}
		}
	}
	
	return	ret;
}

int		main(void)
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	
	int	N;
	
	cin>>N;
	
	for(int i=1;i<=N;i++)
	{
		string	str;
		
		cin>>str;
		cout<<find_sub_str(str)<<'\n';
	}
	
	return	0;
}

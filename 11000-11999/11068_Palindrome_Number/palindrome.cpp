#include	<iostream>
#include	<vector>

using namespace	std;

#define	TRUE	1
#define	FALSE	0

int		check_cycle(vector<int>& c)
{
	int	result,h,t;
	
	for(result=TRUE,h=0,t=c.size()-1;h<t;h++,t--)
	{
		if( c[h] != c[t] )
		{
			result = FALSE;
			break;
		}
	}
	
	return	result;
}

void	convert(int n,int B,vector<int>& c)
{
	while(n>0)
	{
		c.push_back(n%B);
		n /= B;
	}
}

int		is_cycle(int n)
{
	for(int i=2;i<=64;i++)
	{
		vector<int>	converted;
		
		convert(n,i,converted);
		
		if( check_cycle(converted) == TRUE )
		{
			return	TRUE;
		}
	}
	return	FALSE;
}

int		main(void)
{
	int	T;
	
	cin>>T;
	
	while(T>0)
	{
		int	n;
		
		cin>>n;
		cout<<is_cycle(n)<<'\n';
		
		T--;
	}
	return	0;
}

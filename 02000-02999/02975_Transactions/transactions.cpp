#include	<iostream>

using namespace	std;

#define BALANCE_LIMIT		-200
#define	GET_BALANCE(s,l,a)	((s)+((l)=='D'?(a):-(a)))

int	main(void)
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	
	for(;;)
	{
		int		s_balance,amount,result;
		char	c;
		
		cin>>s_balance>>c>>amount;
		
		if( s_balance==0 && c=='W' && amount==0 )
		{
			break;
		}
		
		result = GET_BALANCE(s_balance,c,amount);
		
		if( result >= BALANCE_LIMIT )
		{
			cout<<result<<'\n';
		}
		else
		{
			cout<<"Not allowed\n";
		}
	}
	
	return	0;
}

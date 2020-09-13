#include	<iostream>
#include	<string>

using namespace	std;

int	flip(string& cake)
{
	int		cnt,i;

	for(cnt=0,i=cake.length()-1;i>=0;)
	{
		if( cake[i] == '-' )
		{
			for(;i>=0&&cake[i]=='-';i--);
			cnt++;
			
			for(int j=0;j<=i;j++)
			{
				if( cake[j] == '+' )
				{
					cake[j] = '-';
				}
				else
				{
					cake[j] = '+';
				}
			}
		}
		else
		{
			i--;
		}
	}
	
	return	cnt;
}

int	main(void)
{
	int	T;
	
	cin.sync_with_stdio(false);
	
	cin>>T;
	
	for(int i=1;i<=T;i++)
	{
		string	S;
		
		cin>>S;
		cout<<"Case #"<<i<<": "<<flip(S)<<'\n';
	}
	
	return	0;
}

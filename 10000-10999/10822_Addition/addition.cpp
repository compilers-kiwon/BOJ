#include	<iostream>
#include	<string>

using namespace	std;

int	main(void)
{
	string	S;
	int		i,sum;
	
	cin>>S;
	
	for(i=0,sum=0;i<S.length();)
	{
		int	value;
		
		for(value=0;S[i]>='0' && S[i]<='9';i++)
		{
			value = value*10+(int)(S[i]-'0');
		}
		i++;
		sum += value;
	}
	cout<<sum<<endl;
	
	return	0;
}

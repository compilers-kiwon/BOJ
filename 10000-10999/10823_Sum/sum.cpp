#include	<iostream>
#include	<string>

using namespace	std;

int	main(void)
{
	string	S,line;
	
	while( getline(cin,line) )
	{
		S += line;
	}
	
	int	sum,value,i;
	
	for(sum=value=i=0;i<S.length();i++)
	{
		if( S[i] == ',' )
		{
			sum += value;
			value = 0;
		}
		else
		{
			value = value*10+(int)(S[i]-'0');
		}
	}
	sum += value;
	
	cout<<sum<<endl;
	
	return	0;
}

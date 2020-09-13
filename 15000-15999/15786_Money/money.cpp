#include	<iostream>
#include	<string>

using namespace	std;

bool	is_included(string& pw,string& candidate)
{
	bool	result;
	int		i,j;
	
	for(i=j=0;i<pw.length()&&j<candidate.length();j++)
	{
		if( pw[i] == candidate[j] )
		{
			i++;
		}
	}
	
	if( i == pw.length() )
	{
		result = true;
	}
	else
	{
		result = false;
	}
	
	return	result;
}

int		main(void)
{
	int		N,M;
	string	p;
	
	cin>>N>>M>>p;
	
	for(int i=1;i<=M;i++)
	{
		string c;
		
		cin>>c;
		
		if( is_included(p,c) == true )
		{
			cout<<"true\n";
		}
		else
		{
			cout<<"false\n";
		}
	}
	
	return	0;
}

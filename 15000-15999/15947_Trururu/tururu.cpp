#include	<iostream>
#include	<string>

using namespace	std;

const string	words[14] = {"baby","sukhwan","tururu","turu","very","cute","tururu","turu",
							 "in","bed","tururu","turu","baby","sukhwan"};
							 
int	main(void)
{
	int		N,p,w;
	
	cin>>N;
	N--;
	
	p = N/14;
	w = N%14;
	
	if( words[w] == "tururu" )
	{
		if( p >= 3 )
		{
			cout<<"tu+ru*"<<p+2<<'\n';
		}
		else
		{
			cout<<"tururu";
			
			for(int i=1;i<=p;i++)
			{
				cout<<"ru";
			}
			cout<<'\n';
		}
	}
	else if( words[w] == "turu" )
	{
		if( p >= 4 )
		{
			cout<<"tu+ru*"<<p+1<<'\n';
		}
		else
		{
			cout<<"turu";
			
			for(int i=1;i<=p;i++)
			{
				cout<<"ru";
			}
			cout<<'\n';
		}
	}
	else
	{
		cout<<words[w]<<'\n';
	}
	
	return	0;
}

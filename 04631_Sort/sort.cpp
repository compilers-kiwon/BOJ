#include	<iostream>
#include	<string>

using namespace	std;

#define	MAX_NUM_OF_WORDS	(15+1)

int	main(void)
{
	for(int set=1;;set++)
	{
		int	n,i;
		
		cin>>n;
		
		if( n == 0 )
		{
			break;
		}
		
		string	words[MAX_NUM_OF_WORDS];
		
		for(i=1;i<=n;i++)
		{
			cin>>words[i];
		}
		
		cout<<"SET "<<set<<'\n';
		
		for(i=1;i<=n;i+=2)
		{
			cout<<words[i]<<'\n';
		}
		
		for(i=(n%2)?n-1:n;i>=1;i-=2)
		{
			cout<<words[i]<<'\n';
		}
	}
	
	return	0;
}

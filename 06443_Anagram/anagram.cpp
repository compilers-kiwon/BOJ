#include	<iostream>
#include	<string>
#include	<algorithm>

using namespace	std;

int		main(void)
{
	int	N;
	
	cin>>N;
	
	while(N>0)
	{
		string		word;
		
		cin>>word;
		sort(word.begin(),word.end());		
		
		do{
			cout<<word<<'\n';
		}while( next_permutation(word.begin(),word.end()) );
		
		N--;
	}
	
	return	0;
}

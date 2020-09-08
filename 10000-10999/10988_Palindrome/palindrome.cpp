#include	<iostream>
#include	<string>

using namespace	std;

int	main(void)
{
	string	word;
	bool	result;
	
	cin>>word;
	
	int	i,j;
	
	for(i=0,j=word.length()-1,result=true;i<j;i++,j--)
	{
		if( word[i] != word[j] )
		{
			result = false;
			break;
		}
	}
	cout<<result<<endl;
	
	return	0;
}

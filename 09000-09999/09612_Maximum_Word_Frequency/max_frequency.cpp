#include	<iostream>
#include	<string>
#include	<map>

using namespace	std;

map<string,int>	dic;

int	main(void)
{
	int		n,max_frequency;
	string	max_frequency_word;
	
	cin>>n;
	
	for(int i=1;i<=n;i++)
	{
		string	str;
		
		cin>>str;
		dic[str]++;
	}
	
	max_frequency = 0;
	
	map<string,int>::iterator	iter;
	
	for(iter=dic.begin();iter!=dic.end();iter++)
	{
		if( iter->second >= max_frequency )
		{
			max_frequency_word = iter->first;
			max_frequency = iter->second;
		}
	}
	
	cout<<max_frequency_word<<' '<<max_frequency<<endl;
	
	return	0;
}	

#include	<iostream>
#include	<string>
#include	<map>

using namespace	std;

int	main(void)
{
	int	T;
	
	cin>>T;
	
	while(T>0)
	{
		map<char,int>	count;
	
		for(char c='A';c<='Z';c++)
		{
			count[c] = 0;
		}
	
		string	s;
		
		cin>>s;
		
		for(int i=0;i<s.length();i++)
		{
			count[s[i]]++;
		}
		
		int	sum = 0;
		
		for(char c='A';c<='Z';c++)
		{
			if( count[c] == 0 )
			{
				sum += (int)c;
			}
		}
		cout<<sum<<endl;
		
		T--;
	}
	return	0;
}

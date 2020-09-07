#include	<iostream>
#include	<string>
#include	<vector>

using namespace	std;

int	main(void)
{
	int	T;
	
	cin.sync_with_stdio(false);
	
	cin>>T;
	
	while(T>0)
	{
		int				N,english_index;
		vector<string>	str;
		
		cin>>N;
		english_index = -1;
		
		for(int i=0;i<N;i++)
		{
			string	w;
			
			cin>>w;
			str.push_back(w);
			
			if( w[0] != '#' )
			{
				english_index = i;
			}
		}
		
		for(int i=english_index+1;i<N;i++)
		{
			cout<<str[i]<<' ';
		}
		
		if( english_index != -1 )
		{
			cout<<str[english_index]<<' ';
		}
		
		for(int i=0;i<english_index;i++)
		{
			cout<<str[i]<<' ';
		}
		
		cout<<'\n';
		
		T--;
	}
	
	return	0;
}

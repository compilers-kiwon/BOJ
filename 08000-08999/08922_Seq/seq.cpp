#include	<iostream>
#include	<vector>
#include	<cmath>

using namespace	std;

typedef	vector<int>	Sequence;

int	main(void)
{
	int	T;
	
	cin>>T;
	
	while(T>0)
	{
		int	n;
		
		cin>>n;
		
		Sequence			s(n);
		vector<Sequence>	table;
		
		for(int i=0;i<n;i++)
		{
			cin>>s[i];
		}
		table.push_back(s);
		
		while(1)
		{
			int		tmp;
			bool	found,is_zero;
			
			tmp = s[0];
			
			for(int i=0;i<n-1;i++)
			{
				s[i] = abs(s[i]-s[i+1]);
			}
			s[n-1] = abs(s[n-1]-tmp);
			
			is_zero = true;
			
			for(int i=0;i<n;i++)
			{
				if( s[i] != 0 )
				{
					is_zero = false;
					break;
				}
			}
			
			if( is_zero == true )
			{
				cout<<"ZERO\n";
				break;
			}
			
			found = false;
			
			for(int i=0;i<table.size();i++)
			{
				if( table[i] == s )
				{
					found = true;
					break;
				}
			}
			
			if( found == true )
			{
				cout<<"LOOP\n";
				break;
			}
			table.push_back(s);
		}
		T--;
	}
	
	return	0;
}

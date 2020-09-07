#include	<iostream>
#include	<map>
#include	<string>

using namespace	std;

int	main(void)
{
	int		T;
	
	cin.sync_with_stdio(false);
	
	cin>>T;
	
	while(T>0)
	{
		map<string,int>	table;
		int				n,cnt;
		
		cin>>n;
		
		for(int i=1;i<=n;i++)
		{
			string	a,b;
			
			cin>>a>>b;
			table[b]++;
		}
		
		if( n == 0 )
		{
			cnt = 0;
		}
		else
		{
			cnt = 1;
			
			map<string,int>::iterator	it;
			
			for(it=table.begin();it!=table.end();it++)
			{
				cnt *= it->second+1;
			}
			
			cnt--;
		}
		
		cout<<cnt<<'\n';
		
		T--;
	}
	
	return	0;
}

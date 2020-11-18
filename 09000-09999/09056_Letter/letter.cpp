#include	<iostream>
#include	<string>

using namespace	std;

#define	MAX_SIZE	0x100

int	main(void)
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	
	int	T;
	
	cin>>T;
	
	for(int t=1;t<=T;t++)
	{
		string	a,b;
		bool	available[MAX_SIZE],used[MAX_SIZE],found;
		
		cin>>a>>b;
		
		fill(&available['A'],&available['Z'+1],false);
		fill(&used['A'],&used['Z'+1],false);
		
		for(int i=0;i<a.length();i++)
		{
			available[a[i]] = true;
		}
		
		found = true;
		
		for(int i=0;i<b.length()&&found!=false;i++)
		{
			found = available[b[i]];
			used[b[i]] = true;
		}
		
		if( found == false )
		{
			cout<<"NO\n";
		}
		else
		{
			bool	flag;
			
			flag = true;
			
			for(int i=0;i<a.length()&&flag!=false;i++)
			{
				flag = used[a[i]];
			}
			
			if( flag == false )
			{
				cout<<"NO\n";
			}
			else
			{
				cout<<"YES\n";
			}
		}
	}
	
	return	0;
}

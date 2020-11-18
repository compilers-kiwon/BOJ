#include	<iostream>
#include	<string>
#include	<algorithm>

using namespace	std;

#define	MAX_SIZE	0x100

int	main(void)
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	
	for(;;)
	{
		string	s,sorted;
		
		cin>>s;
		
		if( s.empty() )
		{
			break;
		}
		
		sorted = s;
		sort(sorted.begin(),sorted.end());
		
		int	pos[MAX_SIZE],cnt;
		
		for(int i=0;i<s.length();i++)
		{
			pos[s[i]] = i;
		}
		
		cnt = 0;
		
		for(int i=0;i<s.length();i++)
		{
			if( s[i] == sorted[i] )
			{
				continue;
			}
			
			int	p;
			
			p = pos[sorted[i]];
			
			pos[s[i]] = p;
			pos[s[p]] = i;
			
			swap(s[i],s[p]);
			
			
			cnt++;
		}
		
		cout<<cnt<<'\n';
	}
	
	return	0;
}

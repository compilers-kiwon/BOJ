#include	<iostream>
#include	<vector>
#include	<algorithm>

using namespace	std;

#define	MAX_SIZE	20

int	main(void)
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	
	int	P;
	
	cin>>P;
	
	for(int p=1;p<=P;p++)
	{
		int			T,d;
		vector<int>	s;
		
		cin>>T;
		d = 0;
		
		for(int i=1;i<=MAX_SIZE;i++)
		{
			int	h;
			
			cin>>h;
			
			if( s.empty() || h>s.back() )
			{
				s.push_back(h);
			}
			else
			{
				vector<int>::iterator	pos;
				
				pos = lower_bound(s.begin(),s.end(),h);
				d += s.end()-pos;
				s.insert(pos,h);
			}
		}
		
		cout<<T<<' '<<d<<'\n';
	}
	
	return	0;
}

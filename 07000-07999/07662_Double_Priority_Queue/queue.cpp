#include	<iostream>
#include	<map>

using namespace	std;

typedef	long long int	int64;

int	main(void)
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	
	int	T;
	
	cin>>T;
	
	for(int t=1;t<=T;t++)
	{
		map<int64,int>			counter;
		int						cnt,k;
		
		cin>>k;
		cnt = 0;
		
		for(int i=1;i<=k;i++)
		{
			char	c;
			int64	n;
			
			cin>>c>>n;
			
			if( c == 'I' )
			{
				cnt++;
				counter[n]++;
			}
			else
			{
				if( cnt == 0 )
				{
					continue;
				}
				
				if( n == 1 )
				{
					map<int64,int>::reverse_iterator	it;
					
					it = counter.rbegin();
					it->second -= 1;
					
					if( it->second == 0 )
					{
						counter.erase(it->first);
					}
				}
				else
				{
					map<int64,int>::iterator	it;
					
					it = counter.begin();
					it->second -= 1;
					
					if( it->second == 0 )
					{
						counter.erase(it->first);
					}
				}

				cnt--;
			}
		}
		
		if( cnt == 0 )
		{
			cout<<"EMPTY\n";
		}
		else
		{
			cout<<counter.rbegin()->first<<' '<<counter.begin()->first<<'\n';
		}
	}
	
	return	0;
}

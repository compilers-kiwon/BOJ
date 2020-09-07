#include	<iostream>
#include	<set>

using namespace	std;

#define	MAX_SIZE	(100+1)

int	main(void)
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	
	int	K;
	
	cin>>K;
	
	for(int k=1;k<=K;k++)
	{
		int			n,m,s;
		bool		head;		
		set<int>	connected[MAX_SIZE];
		
		cin>>n>>m;
		
		for(int i=1;i<=m;i++)
		{
			int	p1,p2;
			
			cin>>p1>>p2;
			
			connected[p1].insert(p2);
			connected[p2].insert(p1);
		}
		
		cin>>s;
		head = true;
		
		cout<<"Data Set "<<k<<":\n";
		
		for(set<int>::iterator it=connected[s].begin();it!=connected[s].end();it++)
		{
			if( head == true )
			{
				cout<<*it;
				head = false;
			}
			else
			{
				cout<<' '<<*it;
			}
		}
		cout<<"\n\n";
	}
	
	return	0;
}

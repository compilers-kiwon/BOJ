#include	<iostream>
#include	<queue>

using namespace	std;

#define	MAX_SIZE	(100+1)
#define	MAX_TIME	24

#define	start_time	first
#define	end_time	second

typedef	pair<int,pair<int,int> >	Party;	// first:-total_time,second:<start_time,end_time>
typedef	pair<bool,bool>				Time;	// first:first_half,second:second_half

Time	time_table[MAX_TIME];

bool	input(priority_queue<Party>& pq)
{
	int	p;
	
	cin>>p;
	
	if( p == 0 )
	{
		return	false;
	}
	
	for(int i=1;i<=p;i++)
	{
		int	s,e;
		
		cin>>s>>e;
		pq.push(make_pair(-(e-s),make_pair(s,e)));
	}
	
	return	true;
}

// attend a party which is shorter and earlier
int		attend_party(priority_queue<Party>& pq)
{
	int		cnt;
	
	cnt = 0;
	
	for(;!pq.empty();)
	{
		int	s,e;
		
		s = pq.top().second.start_time;
		e = pq.top().second.end_time;
		
		pq.pop();
		
		for(int t=s;t<e;t++)
		{
			if( time_table[t].first == false )
			{
				cnt++;
				time_table[t].first = true;
				
				break;
			}
			
			if( time_table[t].second == false )
			{
				cnt++;
				time_table[t].second = true;
				
				break;
			}
		}
	}
	
	return	cnt;
}

int		main(void)
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	
	for(int d=1;;d++)
	{
		priority_queue<Party>	pq;
		
		if( input(pq) == false )
		{
			break;
		}
		
		fill(&time_table[0],&time_table[MAX_TIME],make_pair(false,false));
		cout<<"On day "<<d<<" Emma can attend as many as "<<attend_party(pq)<<" parties.\n";
	}
	
	return	0;
}

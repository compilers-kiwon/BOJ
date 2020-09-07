#include	<iostream>
#include	<map>

using namespace	std;

int	main(void)
{
	int	T;
	
	cin>>T;
	
	while(T>0)
	{
		int				K,N;
		map<int,bool>	attendee;
		
		cin>>K;
		
		for(int i=1;i<=K;i++)
		{
			int	runner;
			
			cin>>runner;
			attendee[runner] = true;
		}
		
		cin>>N;
		
		int	best_attendee,best_record,cnt;
		
		best_record = 0x7FFFFFFF;
		cnt = 0;
		
		for(int i=1;i<=N;i++)
		{
			int	r,h,m;
			
			cin>>r>>h>>m;
			
			if( attendee[r] == true && h != -1 && m != -1 )
			{
				int	record;
				
				record = h*60+m;
				
				if( record <= 60*6 )
				{
					cnt++;
				}
				
				if( record < best_record )
				{
					best_record = record;
					best_attendee = r;
				}
			}
			
		}
		cout<<best_attendee<<' '<<cnt<<endl;
		
		T--;
	}
	
	return	0;
}

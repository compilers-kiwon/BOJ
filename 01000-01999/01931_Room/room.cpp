#include	<cstdio>
#include	<vector>
#include	<algorithm>

using namespace std;

#define	MAX_NUM_OF_MEETINGS	(100000+1)

vector< pair<int,int> > meeting_time(MAX_NUM_OF_MEETINGS);	// first:end time, second:start time
vector<int>	max_num_of_arranged_meetings(MAX_NUM_OF_MEETINGS,0);

int	main(void)
{
	int	n;
	
	scanf("%d",&n);
	
	for(int i=1;i<=n;i++)
	{
		scanf("%d %d",&meeting_time[i].second,&meeting_time[i].first);
	}
	
	sort(&meeting_time[1],&meeting_time[n+1]);
	
	int	prev,num_of_allocated_meetings;
	
	prev = 1;
	num_of_allocated_meetings = 1;
	
	for(int i=2;i<=n;i++)
	{
		if( meeting_time[prev].first <= meeting_time[i].second )
		{
			prev = i;
			++num_of_allocated_meetings;
		}
	}
	
	printf("%d\n",num_of_allocated_meetings);
	
	return	0;
}

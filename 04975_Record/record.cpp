#include	<iostream>
#include	<vector>

using namespace	std;

#define	MAX_SIZE	(10000+1)

#define	START_TIME	first
#define	END_TIME	second

#define	LOGGED_IN	1
#define	LOGGED_OUT	0

#define	IN_RANGE(MIN,n,MAX)	((MIN)<=(n)&&(n)<=(MAX))

typedef	pair<int,int>	Time;	// first:START_TIME, second:END_TIME

bool	input(vector<Time>* student_record)
{
	int	N,M;
	
	cin>>N>>M;
	
	if( N==0 && M==0 )
	{
		return	false;
	}
	
	int	r;
	
	cin>>r;
	
	for(int i=1;i<=r;i++)
	{
		int	t,n,m,s;
		
		cin>>t>>n>>m>>s;
		
		vector<Time>&	record = student_record[m];

		if( s == LOGGED_IN )
		{			
			if( record.size() == 0 )
			{
				record.push_back(make_pair(t,-1));
			}
			else
			{
				if( record.back().END_TIME < 0 )
				{
					record.back().END_TIME--;
				}
				else
				{
					if( record.back().END_TIME == t )
					{
						record.back().END_TIME = -1;
					}
					else
					{
						record.push_back(make_pair(t,-1));
					}
				}
			}
		}
		else
		{
			record.back().END_TIME++;
			
			if( record.back().END_TIME == 0 )
			{
				record.back().END_TIME = t;
			}
		}
	}

	return	true;
}

void	do_query(vector<Time>* student_record)
{
	int	q;
	
	cin>>q;
	
	for(int i=1;i<=q;i++)
	{
		int		t_s,t_e,m,usage;
		bool	end_time;
		
		cin>>t_s>>t_e>>m;
		end_time = false;
		usage = 0;
		
		vector<Time>&	record = student_record[m];
		
		for(int j=0;j<record.size()&&end_time!=true;j++)
		{
			Time&	t = record[j];
			
			if( IN_RANGE(t_s,t.START_TIME,t_e) 
				&& IN_RANGE(t_s,t.END_TIME,t_e) )
			{
				usage += t.END_TIME-t.START_TIME;
				continue;
			}
			
			if( IN_RANGE(t.START_TIME,t_s,t.END_TIME) 
				&& IN_RANGE(t.START_TIME,t_e,t.END_TIME) )
			{
				end_time = true;
				usage = t_e-t_s;
				continue;
			}
			
			if( IN_RANGE(t.START_TIME,t_s,t.END_TIME) )
			{
				usage = t.END_TIME-t_s;
				continue;
			}
			
			if( IN_RANGE(t.START_TIME,t_s,t.END_TIME) )
			{
				usage = t.END_TIME-t_s;
				continue;
			}
			
			if( IN_RANGE(t.START_TIME,t_e,t.END_TIME) )
			{
				usage += t_e-t.START_TIME;
				end_time = true;
				continue;
			}
		}
		
		cout<<usage<<'\n';
	}
}

int		main(void)
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	
	for(;;)
	{
		vector<Time>	student_record[MAX_SIZE];
		
		if( input(student_record) == false )
		{
			break;
		}
		
		do_query(student_record);
	}
	
	return	0;
}

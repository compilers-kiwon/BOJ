#include	<iostream>
#include	<queue>

using namespace	std;

typedef	pair<int,int>	Event;	// first:-mm, second:train_event

#define	START_FROM_A	1
#define	ARRIVE_AT_A		2
#define	START_FROM_B	3
#define	ARRIVE_AT_B		4

void	init(int& return_time,int& num_of_train_A,
			 int& num_of_train_B,priority_queue<Event>& pq)
{
	cin>>return_time>>num_of_train_A>>num_of_train_B;
	
	for(int i=1;i<=num_of_train_A;i++)
	{
		string	start,arrive;
		int		start_time_hh,start_time_mm,arrive_time_hh,arrive_time_mm;
		
		cin>>start>>arrive;
		start[2] = arrive[2] = ' ';
		
		sscanf(start.c_str(),"%d %d",&start_time_hh,&start_time_mm);
		sscanf(arrive.c_str(),"%d %d",&arrive_time_hh,&arrive_time_mm);
		
		pq.push(make_pair(-(start_time_hh*60+start_time_mm),START_FROM_A));
		pq.push(make_pair(-(arrive_time_hh*60+arrive_time_mm),ARRIVE_AT_B));
	}
	
	for(int i=1;i<=num_of_train_B;i++)
	{
		string	start,arrive;
		int		start_time_hh,start_time_mm,arrive_time_hh,arrive_time_mm;
		
		cin>>start>>arrive;
		start[2] = arrive[2] = ' ';
		
		sscanf(start.c_str(),"%d %d",&start_time_hh,&start_time_mm);
		sscanf(arrive.c_str(),"%d %d",&arrive_time_hh,&arrive_time_mm);
		
		pq.push(make_pair(-(start_time_hh*60+start_time_mm),START_FROM_B));
		pq.push(make_pair(-(arrive_time_hh*60+arrive_time_mm),ARRIVE_AT_A));
	}
}

void	simulate(priority_queue<Event>& event_q,int return_time,
				 int& num_of_new_train_A,int& num_of_new_train_B)
{
	priority_queue<int>	A_station,B_station;
	
	for(num_of_new_train_A = num_of_new_train_B = 0;!event_q.empty();event_q.pop())
	{
		int	current_time,current_event;
		
		current_time = -event_q.top().first;
		current_event = event_q.top().second;
		
		switch(current_event)
		{
			case	START_FROM_A:
				if( !A_station.empty() && (-A_station.top())<=current_time )
				{
					A_station.pop();
				}
				else
				{
					num_of_new_train_A++;
				}
				break;
			case	START_FROM_B:
				if( !B_station.empty() && (-B_station.top())<=current_time )
				{
					B_station.pop();
				}
				else
				{
					num_of_new_train_B++;
				}
				break;
			case	ARRIVE_AT_A:
				A_station.push(-(current_time+return_time));
				break;
			case	ARRIVE_AT_B:
				B_station.push(-(current_time+return_time));
				break;
			default:
				// do nothing
				break;
		}
	}
}

int		main(void)
{
	int	N;
	
	cin>>N;
	
	for(int i=1;i<=N;i++)
	{
		int						T,NA,NB,A,B;
		priority_queue<Event>	eq;
		
		init(T,NA,NB,eq);
		simulate(eq,T,A,B);
		
		cout<<"Case #"<<i<<": "<<A<<' '<<B<<'\n';
	}
	
	return	0;
}

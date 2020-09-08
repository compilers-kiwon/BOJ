#include	<iostream>
#include	<vector>
#include	<set>

using namespace	std;

#define	MAX_NUM_OF_FIELD	(100+1)
#define	MAX_TRAVEL_TIME		100

#define	Bessie	0
#define	Elsie	1

int			N,M;
int			time_table[2][MAX_NUM_OF_FIELD][MAX_NUM_OF_FIELD];
bool		arrival_time[2][MAX_NUM_OF_FIELD][MAX_TRAVEL_TIME*MAX_NUM_OF_FIELD];
vector<int>	prev_field[MAX_NUM_OF_FIELD],arrival_time_vec[2][MAX_NUM_OF_FIELD];
bool		visited[MAX_NUM_OF_FIELD];

void	init(void)
{
	cin>>N>>M;
	
	for(int i=1;i<=M;i++)
	{
		int	A,B,C,D;
		
		cin>>A>>B>>C>>D;
		
		prev_field[B].push_back(A);
		time_table[Bessie][A][B] = C;
		time_table[Elsie][A][B] = D;
	}
}

void	add_time(vector<int>& src,vector<int>& dst,int time,int who,int updated_field)
{
	for(int i=0;i<src.size();i++)
	{
		int	new_arrival_time;
		
		new_arrival_time = src[i]+time;
		
		if( arrival_time[who][updated_field][new_arrival_time] == false )
		{
			arrival_time[who][updated_field][new_arrival_time] = true;
			dst.push_back(new_arrival_time);
		}
	}
}

void	get_arrival_time(int field)
{
	vector<int>&	prev_field_vec = prev_field[field];
	
	for(int i=0;i<prev_field_vec.size();i++)
	{
		int&	prev_field = prev_field_vec[i];
		
		if( visited[prev_field] == false )
		{
			get_arrival_time(prev_field);
			visited[prev_field] = true;
		}
		
		vector<int>&	Bessie_prev_time = arrival_time_vec[Bessie][prev_field];
		vector<int>&	Elsie_prev_time = arrival_time_vec[Elsie][prev_field];
		
		add_time(Bessie_prev_time,arrival_time_vec[Bessie][field],time_table[Bessie][prev_field][field],Bessie,field);
		add_time(Elsie_prev_time,arrival_time_vec[Elsie][field],time_table[Elsie][prev_field][field],Elsie,field);
	}
}

int		find_same_arrival_time(void)
{
	int	time,i;
	
	for(i=1,time=-1;i<MAX_TRAVEL_TIME*MAX_NUM_OF_FIELD;i++)
	{
		if( arrival_time[Bessie][N][i]==true && arrival_time[Elsie][N][i]==true )
		{
			time = i;
			break;
		}
	}
	
	return	time;
}

int		main(void)
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	
	init();
	
	visited[1] = true;
	arrival_time_vec[Bessie][1].push_back(0);
	arrival_time_vec[Elsie][1].push_back(0);
	
	get_arrival_time(N);
	
	int	same_arrival_time = find_same_arrival_time();
	
	if( same_arrival_time != -1 )
	{
		cout<<same_arrival_time<<'\n';
	}
	else
	{
		cout<<"IMPOSSIBLE\n";
	}
	
	return	0;
}

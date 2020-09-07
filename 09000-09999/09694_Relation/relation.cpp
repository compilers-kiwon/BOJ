#include	<iostream>
#include	<vector>
#include	<queue>

using namespace	std;

#define	MAX_SIZE	20

typedef	pair<int,int>	Relation;
typedef	pair<int,int>	State;		// first:-closeness, second:person

void	init(int& num_of_relations,int& num_of_people,vector<Relation>* connected)
{
	cin>>num_of_relations>>num_of_people;
	
	for(int i=1;i<=num_of_relations;i++)
	{
		int x,y,z;
		
		cin>>x>>y>>z;
		connected[x].push_back(make_pair(y,z));
		connected[y].push_back(make_pair(x,z));
	}
}

bool	find_shortest_path(vector<Relation>* connected,int s,int e,vector<int>& prev)
{
	priority_queue<State>	pq;
	vector<int>				dp(e+1,0x7FFFFFFF);
	
	dp[s] = 0;
	prev[s] = -1;
	pq.push(make_pair(0,s));
	
	while( !pq.empty() )
	{
		int	current_closeness,current_person;
		
		current_closeness = -pq.top().first;
		current_person = pq.top().second;
		
		pq.pop();
		
		if( current_person == e )
		{
			return	true;
		}
		
		vector<Relation>&	adj_people = connected[current_person];
		
		for(int i=0;i<adj_people.size();i++)
		{
			int&	adj_person = adj_people[i].first;
			int&	adj_closeness = adj_people[i].second;
			
			if( current_closeness+adj_closeness < dp[adj_person] )
			{
				dp[adj_person] = current_closeness+adj_closeness;
				pq.push(make_pair(-(current_closeness+adj_closeness),adj_person));
				prev[adj_person] = current_person;
			}
		}
	}
	
	return	false;
}

int		main(void)
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	
	int	T;
	
	cin>>T;
	
	for(int i=1;i<=T;i++)
	{
		int					N,M;
		vector<Relation>	connected[MAX_SIZE];
		vector<int>			prev,out;
		
		init(N,M,connected);
		
		prev.resize(M,0);
		cout<<"Case #"<<i<<": ";
		
		if( find_shortest_path(connected,0,M-1,prev) == true )
		{
			for(int j=M-1;j!=-1;j=prev[j])
			{
				out.push_back(j);
			}
			
			for(int j=out.size()-1;j>=0;j--)
			{
				cout<<out[j]<<' ';
			}
			cout<<'\n';
		}
		else
		{
			cout<<"-1\n";
		}
	}
	
	return	0;
}

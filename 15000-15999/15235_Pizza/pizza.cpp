#include	<iostream>
#include	<queue>
#include	<vector>

using namespace	std;

typedef	pair<int,int>	Contestant;	// first:number, second: number of slices that will be taken

void	simulate(int num_of_contestants,vector<int>& slices,vector<int>& time_table)
{
	queue<Contestant>	cont_q;
	
	for(int i=1;i<=num_of_contestants;i++)
	{
		cont_q.push(make_pair(i,slices[i]));	
	}
	
	for(int sec=1;!cont_q.empty();sec++)
	{
		Contestant	current;
		
		current = cont_q.front();
		cont_q.pop();
		
		if( current.second == 1 )
		{
			time_table[current.first] = sec;	
		}	
		else
		{
			cont_q.push(make_pair(current.first,current.second-1));
		}
	}
}

int		main(void)
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	
	int		N;
	
	cin>>N;
	
	vector<int>	number_of_slices(N+1),time(N+1);
	
	for(int i=1;i<=N;i++)
	{
		cin>>number_of_slices[i];
	}
	
	simulate(N,number_of_slices,time);
	
	for(int i=1;i<=N;i++)
	{
		cout<<time[i]<<' ';
	}
	cout<<'\n';
	
	return	0;
}

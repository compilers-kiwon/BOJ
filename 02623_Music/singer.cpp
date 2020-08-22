#include	<iostream>
#include	<vector>
#include	<queue>

using namespace	std;

#define	MAX_NUM_OF_SINGER	(1000+1)

int			N,M;
int			num_of_prev_singer[MAX_NUM_OF_SINGER];
vector<int>	next_singer[MAX_NUM_OF_SINGER];
vector<int>	appearance_sequence;

void	input(void)
{
	cin>>N>>M;
	
	for(int i=1;i<=M;i++)
	{
		int	g,prev;
		
		cin>>g;
		cin>>prev;
		
		for(int j=2;j<=g;j++)
		{
			int	s;
			
			cin>>s;
			next_singer[prev].push_back(s);
			num_of_prev_singer[s]++;
			prev = s;
		}
	}
}

bool	make_sequence(void)
{
	queue<int>	singer_q;
	
	for(int i=1;i<=N;i++)
	{
		if( num_of_prev_singer[i] == 0 )
		{
			singer_q.push(i);
		}
	}
	
	while( singer_q.size() != 0 )
	{
		int	current_singer;
		
		current_singer = singer_q.front();
		singer_q.pop();
		appearance_sequence.push_back(current_singer);
		
		for(int i=0;i<next_singer[current_singer].size();i++)
		{
			--num_of_prev_singer[next_singer[current_singer][i]];
			
			if( num_of_prev_singer[next_singer[current_singer][i]] == 0 )
			{
				singer_q.push(next_singer[current_singer][i]);
			}
		}
	}
	
	return	(appearance_sequence.size() == N);
}

int		main(void)
{
	input();
	
	if( make_sequence() == true )
	{
		for(int i=0;i<N;i++)
		{
			cout<<appearance_sequence[i]<<endl;
		}
	}
	else
	{
		cout<<"0\n";
	}
	
	return	0;
}

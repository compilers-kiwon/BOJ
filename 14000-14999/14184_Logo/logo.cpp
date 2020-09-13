#include	<iostream>
#include	<map>
#include	<vector>

using namespace	std;

#define	MAX_NUM_OF_CHOICE	3
#define	MAX_NUM_OF_LOGO		(1000000+1)

typedef	struct{int cnt[MAX_NUM_OF_CHOICE];}	Count;

int	get_score(Count& v)
{
	int	score;
	
	score = 0;
	
	for(int i=MAX_NUM_OF_CHOICE;i>0;i--)
	{
		score += v.cnt[i]*i;
	}
	
	return	score;
}

int	main(void)
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	
	for(;;)
	{
		int	n;
		
		cin>>n;
		
		if( n == 0 )
		{
			break;
		}
		
		map<int,Count>	vote;
		vector<bool>	visited(MAX_NUM_OF_LOGO,false);
		
		for(int i=1;i<=n;i++)
		{
			int	d;
			
			cin>>d;
			
			for(int i=MAX_NUM_OF_CHOICE;d>0;d--,i--)
			{
				int	id;
				
				cin>>id;
				
				if( visited[id] == false )
				{
					visited[id] = true;
					
					for(int j=i;j<=MAX_NUM_OF_CHOICE;j++)
					{
						vote[id].cnt[j] = 0;
					}
				}
				
				vote[id].cnt[i]++;
			}
		}
		
		vector<int>	winner;
		int			max_score;
		
		map<int,Count>::iterator	vi;
		
		max_score = 0;
		
		for(vi=vote.begin();vi!=vote.end();vi++)
		{
			int		score;
			bool	new_winner,same_winner;
			
			new_winner = same_winner = false;
			
			score = get_score(vi->second);
			
			if( score > max_score )
			{
				new_winner = true;
			}
			else if( score == max_score )
			{
				int&	prev_winner = winner.back();
				Count&	prev_winner_vote = vote[prev_winner];
				int		i;
				
				for(i=MAX_NUM_OF_CHOICE;i>0;i--)
				{
					if( prev_winner_vote.cnt[i] != vi->second.cnt[i] )
					{
						break;
					}
				}
				
				if( i == 0 )
				{
					same_winner = true;
				}
				else
				{
					if( vi->second.cnt[i] > prev_winner_vote.cnt[i] )
					{
						new_winner = true;
					}
				}
			}
			
			if( new_winner == true )
			{
				max_score = score;
				winner.clear();
				winner.push_back(vi->first);
			}
			
			if( same_winner == true )
			{
				winner.push_back(vi->first);
			}
		}
		
		for(int i=0;i<winner.size();i++)
		{
			cout<<winner[i]<<' ';
		}
		cout<<'\n';
	}
	
	return	0;
}

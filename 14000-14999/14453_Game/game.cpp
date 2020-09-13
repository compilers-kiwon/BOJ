#include	<iostream>
#include	<vector>

using namespace	std;

#define	MAX_LEN	(10000+1)

int	N,cnt[MAX_LEN][0x100];

void	init(void)
{
	cin.sync_with_stdio(false);
	
	cin>>N;
	
	for(int i=1;i<=N;i++)
	{
		char	c;
		
		cin>>c;
		
		cnt[i]['H'] = cnt[i-1]['H'];
		cnt[i]['P'] = cnt[i-1]['P'];
		cnt[i]['S'] = cnt[i-1]['S'];
		
		cnt[i][c]++;
	}
}

int		play_game(void)
{
	int	max_num_of_wins;
	
	max_num_of_wins = 1;
	
	for(int i=2;i<=N;i++)
	{
		int		num_of_prev_max_win,num_of_final_max_win;
		
		num_of_prev_max_win = max(cnt[i-1]['H'],max(cnt[i-1]['P'],cnt[i-1]['S']));
		num_of_final_max_win = max(cnt[N]['H']-cnt[i-1]['H'],max(cnt[N]['P']-cnt[i-1]['P'],cnt[N]['S']-cnt[i-1]['S']));
		
		max_num_of_wins = max(max_num_of_wins,num_of_prev_max_win+num_of_final_max_win);
	}
	
	return	max_num_of_wins;
}

int		main(void)
{
	init();
	cout<<play_game()<<'\n';
	
	return	0;
}

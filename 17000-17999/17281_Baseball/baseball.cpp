#include	<iostream>
#include	<vector>
#include	<algorithm>

using namespace	std;

#define	MAX_INNING	(50+1)
#define	MAX_HITTER	9

#define	TRUE	1
#define	FALSE	0

#define	get_next_hitter(h)	(((h)+1)%MAX_HITTER)

int	N,hitter_data[MAX_INNING][MAX_HITTER];

void	input(void)
{
	cin>>N;
	
	for(int i=1;i<=N;i++)
	{
		for(int h=0;h<MAX_HITTER;h++)
		{
			cin>>hitter_data[i][h];
		}
	}
}

int		single_simulation(int* base)
{
	int	ret;
	
	ret = base[3];
	base[3] = base[2];
	base[2] = base[1];
	base[1] = TRUE;
	
	return	ret;
}

int		double_simulation(int* base)
{
	int	ret;
	
	ret = base[3]+base[2];
	base[3] = base[1];
	base[2] = TRUE;
	base[1] = FALSE;
	
	return	ret;
}

int		triple_simulation(int* base)
{
	int	ret;
	
	ret = base[3]+base[2]+base[1];
	base[3] = TRUE;
	base[2] = base[1] = FALSE;
	
	return	ret;
}

int		homerun_simulation(int* base)
{
	int	ret;
	
	ret = base[3]+base[2]+base[1]+1;
	base[3] = base[2] = base[1] = FALSE;
	
	return	ret;
}

int		simulate_game(int* hitter_order)
{
	int	score,current_hitter;
	
	score = 0;
	current_hitter = 0;
	
	for(int i=1;i<=N;i++)
	{
		int	base_state[3+1];
		
		base_state[1] = base_state[2] = base_state[3] = FALSE;
		
		for(int out_cnt=0;out_cnt<3;)
		{
			int&	hit = hitter_data[i][hitter_order[current_hitter]];
			
			switch(hit)
			{
				case	1:
					score += single_simulation(base_state);
					break;
				case	2:
					score += double_simulation(base_state);
					break;
				case	3:
					score += triple_simulation(base_state);
					break;
				case	4:
					score += homerun_simulation(base_state);
					break;
				default :	// case	0
					out_cnt++;
					break;
			}
			
			current_hitter = get_next_hitter(current_hitter);
		}
	}
	
	return	score;
}

void	get_hitter_order(int* result,vector<int>& src)
{
	result[0] = src[0];
	result[1] = src[1];
	result[2] = src[2];
	result[3] = 0;
	result[4] = src[3];
	result[5] = src[4];
	result[6] = src[5];
	result[7] = src[6];
	result[8] = src[7];
}

int		main(void)
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	
	int			max_score;
	vector<int>	hitters;
	
	for(int i=1;i<MAX_HITTER;i++)
	{
		hitters.push_back(i);
	}
	
	input();
	max_score = 0;
	
	do{
		int	hitter_order[MAX_HITTER];
		
		get_hitter_order(hitter_order,hitters);
		max_score = max(max_score,simulate_game(hitter_order));
		
	}while(next_permutation(hitters.begin(),hitters.end()));
	
	cout<<max_score<<'\n';
	
	return	0;
}

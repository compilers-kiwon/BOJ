#include	<iostream>
#include	<string>
#include	<map>
#include	<vector>

using namespace	std;

#define	MAX_NUM_OF_KEYS		(100+1)
#define	MAX_NUM_OF_MELODIES	(100+1)
#define	MAX_NUM_OF_NOTES	12

const string	note[MAX_NUM_OF_NOTES+1] = {"","C","C#","D","D#","E","F","F#","G","G#","A","A#","B"};

int					n,m;
string				melody[MAX_NUM_OF_MELODIES];
map<string,double>	penalty[MAX_NUM_OF_KEYS];

void	input(void)
{
	cin>>n>>m;
	
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=MAX_NUM_OF_NOTES;j++)
		{
			cin>>penalty[i][note[j]];
		}
	}
	
	for(int i=1;i<=m;i++)
	{
		cin>>melody[i];
	}
}

double	get_cumulative_penalty(string& mel,int p_idx)
{
	double	ret;
	
	ret = 0.0;
	
	for(int i=0;i<mel.length();)
	{
		string	matched;
		
		for(int j=1;j<=MAX_NUM_OF_NOTES;j++)
		{
			string	tmp;
			
			tmp = mel.substr(i,note[j].size());
			
			if( tmp == note[j] )
			{
				matched = tmp;
			}
		}
		
		i += matched.length();
		ret += penalty[p_idx][matched];
	}
	
	return	ret;
}

int		main(void)
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	
	int	K;
	
	cin>>K;
	
	for(int k=1;k<=K;k++)
	{
		input();
		cout<<"Data Set "<<k<<":\n";
		
		for(int i=1;i<=m;i++)
		{
			int		best_penalty;
			double	min_cumulative_penalty;
			
			min_cumulative_penalty = 1000000.0;
			
			for(int j=1;j<=n;j++)
			{
				double	p;
				
				p = get_cumulative_penalty(melody[i],j);
				
				if( p < min_cumulative_penalty )
				{
					min_cumulative_penalty = p;
					best_penalty = j;
				}
			}
			
			cout<<best_penalty<<'\n';
		}
		
		cout<<'\n';
	}
	
	return	0;
}

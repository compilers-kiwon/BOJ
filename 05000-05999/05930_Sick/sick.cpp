#include	<iostream>
#include	<algorithm>
#include	<vector>

using namespace	std;

#define	MAX_SIZE	(20000+1)
#define	MAX_CHORD	10

int	N,C,music[MAX_SIZE],chord[MAX_CHORD];

void	input(void)
{
	cin>>N;
	
	for(int i=1;i<=N;i++)
	{
		cin>>music[i];
	}
	
	cin>>C;
	
	for(int i=0;i<C;i++)
	{
		cin>>chord[i];
	}
	
	sort(chord,chord+C);
}

bool	is_ruminant_seventh_chord(int s)
{
	int		tmp[MAX_CHORD],diff;
	bool	ret;
	
	for(int i=0;i<C;i++)
	{
		tmp[i] = music[s+i];
	}
	
	sort(tmp,tmp+C);
	ret = true;
	diff = chord[0]-tmp[0];
	
	for(int i=1;i<C;i++)
	{
		if( chord[i]-tmp[i] != diff )
		{
			ret = false;
			break;
		}
	}
	
	return	ret;
}

int		main(void)
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	
	input();
	
	vector<int>	s_idx;
	
	for(int i=1;i<=N-C+1;i++)
	{
		if( is_ruminant_seventh_chord(i) == true )
		{
			s_idx.push_back(i);
		}
	}
	
	cout<<s_idx.size()<<'\n';
	
	for(int i=0;i<s_idx.size();i++)
	{
		cout<<s_idx[i]<<'\n';
	}
	
	return	0;
}

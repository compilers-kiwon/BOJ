#include	<iostream>
#include	<vector>

using namespace	std;

#define	MAX_PARTICIPATES	(100+1)
#define	MAX_SONGS			(50+1)
#define	SEONYOUNG			1

int		N,E,song_ptr;
bool	state[MAX_PARTICIPATES][MAX_SONGS];

void	share_songs(const vector<int>& participate)
{
	for(int i=1;i<=song_ptr;i++)
	{
		bool	known;
		
		known = false;
		
		for(int j=0;j<participate.size()&&known!=true;j++)
		{
			known = state[participate[j]][i];
		}
		
		if( known == true )
		{
			for(int j=0;j<participate.size();j++)
			{
				state[participate[j]][i] = true;
			}
		}
	}
}

bool	is_included(const int& p)
{
	bool	ret;
	
	ret = true;
	
	for(int i=1;i<=song_ptr&&ret!=false;i++)
	{
		ret &= state[p][i];
	}
	
	return	ret;
}

int		main(void)
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	
	cin>>N>>E;
	
	for(int i=1;i<=E;i++)
	{
		int			K;
		bool		is_seonyoung;
		vector<int>	participate;
		
		cin>>K;
		is_seonyoung = false;
		
		for(int j=1;j<=K;j++)
		{
			int	p;
			
			cin>>p;
			participate.push_back(p);
			
			if( p == SEONYOUNG )
			{
				is_seonyoung = true;
			}
		}
		
		if( is_seonyoung == true )
		{
			song_ptr++;
			
			for(int j=0;j<K;j++)
			{
				state[participate[j]][song_ptr] = true;
			}
		}
		else
		{
			share_songs(participate);
		}
	}
	
	cout<<SEONYOUNG<<'\n';
	
	for(int i=2;i<=N;i++)
	{
		if( is_included(i) == true )
		{
			cout<<i<<'\n';
		}
	}
	
	return	0;
}

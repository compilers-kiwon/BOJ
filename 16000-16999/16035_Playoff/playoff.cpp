#include	<iostream>
#include	<vector>

using namespace	std;

#define	MAX_SIZE	(9+1)

typedef	pair<int,int>	Record;	// first:win, second:loose
typedef	pair<int,int>	Game;	// first:team1, second:team2

#define	WIN		1
#define	LOOSE	0
#define	TBD		-1

int				n,m,table[MAX_SIZE][MAX_SIZE];
Record			r[MAX_SIZE];
vector<Game>	tbd_game;

bool	input(void)
{
	cin>>n;
	
	if( n == 0 )
	{
		return	false;
	}
	
	cin>>m;
	
	for(int t=1;t<=n;t++)
	{
		fill(&table[t][1],&table[t][n+1],TBD);
		r[t] = make_pair(0,0);
	}
	
	for(int i=1;i<=m;i++)
	{
		int	x,y;
		
		cin>>x>>y;
		
		table[x][y] = WIN;
		table[y][x] = LOOSE;
		
		r[x].first++;
		r[y].second++;
	}
	
	tbd_game.clear();
	
	for(int row=1;row<=n;row++)
	{
		for(int col=row+1;col<=n;col++)
		{
			if( table[row][col] == TBD )
			{
				tbd_game.push_back(make_pair(row,col));
			}
		}
	}
	
	return	true;
}

bool	check_table(void)
{
	for(int t=1;t<=n;t++)
	{
		if( r[t].first>n/2 || r[t].second>n/2 )
		{
			return	false;
		}
	}
	
	return	true;
}

void	play_game(int idx,int& cnt)
{
	if( idx == tbd_game.size() )
	{
		cnt++;
		return;
	}
	
	int&	t1 = tbd_game[idx].first;
	int&	t2 = tbd_game[idx].second;
	
	int&	t1_win = r[t1].first;
	int&	t1_loose = r[t1].second;
	
	int&	t2_win = r[t2].first;
	int&	t2_loose = r[t2].second;
	
	// t1 win
	if( t1_win<n/2 && t2_loose<n/2 )
	{
		t1_win++;
		t2_loose++;
		
		play_game(idx+1,cnt);
		
		t2_loose--;
		t1_win--;
	}
	
	// t2 win
	if( t2_win<n/2 && t1_loose<n/2 )
	{
		t2_win++;
		t1_loose++;
		
		play_game(idx+1,cnt);
		
		t1_loose--;
		t2_win--;
	}
}

int		main(void)
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	
	for(;;)
	{
		if( input() == false )
		{
			break;
		}
		
		if( check_table() == false )
		{
			cout<<"0\n";
			continue;
		}
		
		int	cnt;
		
		cnt = 0;
		
		play_game(0,cnt);
		cout<<cnt<<'\n';
	}
	
	return	0;
}

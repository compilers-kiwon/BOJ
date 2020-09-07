#include	<iostream>

using namespace	std;

#define	MAX_GAME	1000000000

typedef	long long int	int64;

int64	bin_search(int64 X,int64 Y,int64 Z,int64 lo,int64 hi)
{
	if( lo == hi )
	{
		return	lo;
	}
	
	int64	mid,new_win,s;
	
	mid = (lo+hi)/2;
	new_win = ((Y+mid)*100)/(X+mid);
	
	if( new_win == Z )
	{
		s = bin_search(X,Y,Z,mid+1,hi);
	}
	else
	{
		s = bin_search(X,Y,Z,lo,mid);
	}
	
	return	s;
}

int		main(void)
{
	int64	X,Y,Z,more_game;

	for(;scanf("%lld %lld",&X,&Y)==2;)
	{
		Z = (Y*100)/X;
		more_game = bin_search(X,Y,Z,1,MAX_GAME);
		
		if( (((Y+more_game)*100)/(X+more_game)) != Z )
		{
			cout<<more_game<<'\n';
		}
		else
		{
			cout<<"-1\n";
		}
	}
	
	return	0;
}

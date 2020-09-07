#include	<iostream>

using namespace	std;

#define	TOTAL		0
#define	WIN			1
#define	DRAW		2
#define	LOSE		3
#define	POINT		4
#define	MAX_SIZE	5

#define	MAX_GAMES	100
#define	UNKNOWN		-1

int		count_unknown(int* record,int from,int to)
{
	int	ret,i;
	
	for(ret=0,i=from;i<=to;i++)
	{
		if( record[i] == UNKNOWN )
		{
			ret++;
		}
	}
	
	return	ret;
}

void	equation_for_num_of_games(int* record)
{
	if( record[TOTAL] == UNKNOWN )
	{
		record[TOTAL] = record[WIN]+record[LOSE]+record[DRAW];
	}
	
	if( record[WIN] == UNKNOWN )
	{
		record[WIN] = record[TOTAL]-(record[LOSE]+record[DRAW]);
	}
	
	if( record[LOSE] == UNKNOWN )
	{
		record[LOSE] = record[TOTAL]-(record[WIN]+record[DRAW]);
	}
	
	if( record[DRAW] == UNKNOWN )
	{
		record[DRAW] = record[TOTAL]-(record[WIN]+record[LOSE]);
	}
}

void	equation_for_num_of_points(int* record)
{
	if( record[WIN] == UNKNOWN )
	{
		record[WIN] = (record[POINT]-record[DRAW])/3;
	}
	
	if( record[DRAW] == UNKNOWN )
	{
		record[DRAW] = record[POINT]-3*record[WIN];
	}
	
	if( record[POINT] == UNKNOWN )
	{
		record[POINT] = 3*record[WIN]+record[DRAW];
	}
}

bool	preprocess(int* record)
{
	if( count_unknown(record,TOTAL,LOSE) == 1 )
	{
		equation_for_num_of_games(record);
		return	true;
	}
	
	if( (record[LOSE]!=UNKNOWN&&count_unknown(record,WIN,POINT)==1) 
		|| (record[LOSE]==UNKNOWN&&count_unknown(record,WIN,POINT)==2) )
	{
		equation_for_num_of_points(record);
		return	true;
	}
	
	return	false;
}

bool	fill_record(int* record,int idx)
{
	if( idx == MAX_SIZE )
	{
		int	total_games,total_points;
		
		total_games = record[WIN]+record[LOSE]+record[DRAW];
		total_points = 3*record[WIN]+record[DRAW];
		
		if( total_games==record[TOTAL] && total_points==record[POINT] )
		{
			return	true;
		}
		
		return	false;
	}
	
	if( record[idx] != UNKNOWN )
	{
		return	fill_record(record,idx+1);
	}
	
	for(int i=0;i<=MAX_GAMES;i++)
	{
		record[idx] = i;
		
		if( fill_record(record,idx+1) == true )
		{
			return	true;
		}
		
		record[idx] = UNKNOWN;
	}
	
	return	false;
}

int		str2int(string& str)
{
	if( str == "?" )
	{
		return	UNKNOWN;
	}
	
	int	ret,i;
	
	for(ret=i=0;i<str.length();i++)
	{
		ret = ret*10+(int)(str[i]-'0');
	}
	
	return	ret;
}

void	input(int* record)
{
	string	t,w,d,l,p;
	
	cin>>t>>w>>d>>l>>p;
	
	record[TOTAL] = str2int(t);
	record[WIN] = str2int(w);
	record[DRAW] = str2int(d);
	record[LOSE] = str2int(l);
	record[POINT] = str2int(p);
}

int		main(void)
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	
	int	N;
	
	cin>>N;
	
	for(int i=1;i<=N;i++)
	{
		int	record[MAX_SIZE];
		
		input(record);
		
		for(;;)
		{
			if( preprocess(record) == false )
			{
				// corner case
				if( record[TOTAL]==0 && record[WIN]==UNKNOWN && record[DRAW]==UNKNOWN && record[LOSE]==UNKNOWN )
				{
					fill(&record[WIN],&record[MAX_SIZE],0);
				}
				
				if( record[TOTAL]==UNKNOWN && record[WIN]==MAX_GAMES && record[DRAW]==UNKNOWN && record[LOSE]==UNKNOWN )
				{
					record[TOTAL] = MAX_GAMES;
					record[DRAW] = record[LOSE] = 0;
					record[POINT] = 3*MAX_GAMES;
				}
				
				if( record[TOTAL]==UNKNOWN && record[WIN]==UNKNOWN && record[DRAW]==MAX_GAMES && record[LOSE]==UNKNOWN )
				{
					record[TOTAL] = MAX_GAMES;
					record[WIN] = record[LOSE] = 0;
					record[POINT] = MAX_GAMES;
				}
				
				if( record[TOTAL]==UNKNOWN && record[WIN]==UNKNOWN && record[DRAW]==UNKNOWN && record[LOSE]==MAX_GAMES )
				{
					record[TOTAL] = MAX_GAMES;
					record[WIN] = record[DRAW] = record[POINT] = 0;
				}
				
				if( record[TOTAL]==UNKNOWN && record[WIN]==UNKNOWN && record[DRAW]==UNKNOWN && record[LOSE]==UNKNOWN && record[POINT]==0 )
				{
					fill(&record[TOTAL],&record[LOSE+1],0);
				}
				
				if( record[TOTAL]==UNKNOWN && record[WIN]==UNKNOWN && record[DRAW]==UNKNOWN && record[LOSE]==UNKNOWN && record[POINT]==3*MAX_GAMES )
				{
					record[TOTAL] = MAX_GAMES;
					record[WIN] = MAX_GAMES;
					record[DRAW] = record[LOSE] = 0;
				}
				
				if( record[TOTAL]==UNKNOWN && record[WIN]==UNKNOWN && record[DRAW]==UNKNOWN && record[LOSE]==UNKNOWN && record[POINT]==3*MAX_GAMES-2 )
				{
					record[TOTAL] = MAX_GAMES;
					record[WIN] = MAX_GAMES-1;
					record[DRAW] = 1;
					record[LOSE] = 0;
				}
				
				if( record[TOTAL]==UNKNOWN && record[WIN]==UNKNOWN && record[DRAW]==UNKNOWN && record[LOSE]==UNKNOWN && record[POINT]==3*MAX_GAMES-4 )
				{
					record[TOTAL] = MAX_GAMES;
					record[WIN] = MAX_GAMES-2;
					record[DRAW] = 2;
					record[LOSE] = 0;
				}
				
				break;
			}
		}
		
		fill_record(record,0);
		cout<<record[TOTAL]<<' '<<record[WIN]<<' '<<record[DRAW]<<' '<<record[LOSE]<<' '<<record[POINT]<<'\n';
	}
	
	return	0;
}

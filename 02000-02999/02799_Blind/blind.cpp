#include	<iostream>
#include	<string>

using namespace	std;

#define	MAX_NUM_OF_FLOOR	(100+1)
#define	WINDOW_HEIGHT		4
#define	NUM_OF_BLIND_TYPE	(WINDOW_HEIGHT+1)

string	apart[5*MAX_NUM_OF_FLOOR+1];
int		M,N;

void	init(void)
{
	cin.sync_with_stdio(false);
	
	cin>>M>>N;
	
	for(int row=0;row<5*M+1;row++)
	{
		cin>>apart[row];
	}
}

int		get_type_of_blind(int row,int col)
{
	int	type;
	
	for(type=0;type<WINDOW_HEIGHT;type++)
	{
		if( apart[row+type][col] == '.' )
		{
			break;
		}
	}
	
	return	type;
}

int		main(void)
{
	int	cnt[NUM_OF_BLIND_TYPE],row,col;
	
	for(int i=0;i<NUM_OF_BLIND_TYPE;i++)
	{
		cnt[i] = 0;
	}
	
	init();
	
	for(int row=1;row<5*M+1;row+=5)
	{
		for(int col=1;col<5*N+1;col+=5)
		{
			cnt[get_type_of_blind(row,col)]++;
		}
	}
	
	for(int i=0;i<NUM_OF_BLIND_TYPE;i++)
	{
		cout<<cnt[i]<<' ';
	}
	
	return	0;
}

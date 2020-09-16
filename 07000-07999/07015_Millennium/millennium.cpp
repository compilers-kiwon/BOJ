#include	<iostream>

using namespace	std;

#define	MAX_YEAR	1000
#define	MAX_MONTH	10
#define	MAX_DAY		20

#define	COMMON				0
#define	MULTIPLE_OF_THREE	1
#define	MAX_TYPE_OF_YEAR	2

#define	get_year_type(y)	(((y)%3)==0?MULTIPLE_OF_THREE:COMMON)
int	cnt_of_days[MAX_YEAR][MAX_MONTH+1][MAX_DAY+1];

const int	days_of_month[MAX_TYPE_OF_YEAR][MAX_MONTH+1] = 
	{{0,20,19,20,19,20,19,20,19,20,19},{0,20,20,20,20,20,20,20,20,20,20}};

void	init(void)
{
	int	cnt;
	
	cnt = 1;
	
	for(int y=MAX_YEAR-1;y>=1;y--)
	{
		for(int m=MAX_MONTH;m>=1;m--)
		{
			int	year_type;
			
			year_type = get_year_type(y);
			
			for(int d=days_of_month[year_type][m];d>=1;d--)
			{
				cnt_of_days[y][m][d] = cnt++;
			}
		}
	}
}

int		main(void)
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	
	int	n;
	
	init();
	cin>>n;
	
	for(int i=1;i<=n;i++)
	{
		int	Y,M,D;
		
		cin>>Y>>M>>D;
		cout<<cnt_of_days[Y][M][D]<<'\n';
	}
	
	return	0;
}

#include	<iostream>
#include	<vector>

using namespace	std;

#define	MAX_SIZE	5
#define	US			1

double	rate[MAX_SIZE+1][MAX_SIZE+1];

void	init(void)
{
	for(int row=1;row<=MAX_SIZE;row++)
	{
		for(int col=1;col<=MAX_SIZE;col++)
		{
			cin>>rate[row][col];
		}
	}
}

bool	get_trip_info(vector<int>& trip,double& money)
{
	int	n;
	
	cin>>n;
	
	if( n == 0 )
	{
		return	false;
	}
	
	trip.push_back(US);
	
	for(int i=1;i<=n;i++)
	{
		int	c;
		
		cin>>c;
		trip.push_back(c);
	}
	
	trip.push_back(US);
	
	cin>>money;
	
	return	true;
}

double	exchange(double money,int from_country,int to_country)
{
	int		ret;
	
	ret = (int)((money*rate[from_country][to_country])*1000.0);
	ret += 5;
	ret /= 10;
	
	return	((double)ret)/100.0;
}

int		main(void)
{
	init();
	
	for(;;)
	{
		vector<int>	t;
		double		dallars;
		
		if( get_trip_info(t,dallars) == false )
		{
			break;
		}
		
		for(int i=0;i<t.size()-1;i++)
		{
			dallars = exchange(dallars,t[i],t[i+1]);
		}
		
		printf("%.2f\n",dallars);
	}
	
	return	0;
}

#include	<iostream>

using namespace	std;

typedef	unsigned long long	uint64;

#define	GET_Y(t)	((((t)/30)+((t)%30!=0))*10)
#define	GET_M(t)	((((t)/60)+((t)%60!=0))*15)

int	main(void)
{
	uint64	y,m;
	int		N,i;
	
	cin>>N;
	
	for(i=1,y=0,m=0;i<=N;i++)
	{
		uint64	time;
		
		cin>>time;
		y += GET_Y(time);
		m += GET_M(time);
	}
	
	if( y < m )
	{
		cout<<"Y "<<y<<endl;
	}
	else if( y > m )
	{
		cout<<"M "<<m<<endl;
	}
	else
	{
		cout<<"Y M "<<y<<endl;
	}
	
	return	0;
}

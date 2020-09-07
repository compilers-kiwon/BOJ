#include	<iostream>
#include	<algorithm>

using namespace	std;

#define	MAX_SIZE			5
#define	DEGREE_FOR_HOUR		(30*10)
#define	HOUR_FOR_CLOCK		12
#define	DEGREE_FOR_MINUTE	(6*10)

#define	DEGREE_OFFSET_BETWEEN_HOUR_AND_MINUTE	5

#define	MID_POS	2

typedef	struct	_CLOCK_INFO	Clock;
struct	_CLOCK_INFO
{
	int	h,m,d;
};

int		cal_degree(int h,int m)
{
	int	h_degree,m_degree,ret;
	
	h_degree = DEGREE_FOR_HOUR*(h%HOUR_FOR_CLOCK)
				+ DEGREE_OFFSET_BETWEEN_HOUR_AND_MINUTE*m;
	m_degree = DEGREE_FOR_MINUTE*m;
	
	ret = max(h_degree,m_degree)-min(h_degree,m_degree);
	
	if( ret > 180*10 )
	{
		ret = (360*10)-ret;
	}
	
	return	ret;
}

void	input(Clock* c)
{
	for(int i=0;i<MAX_SIZE;i++)
	{
		char	buf[MAX_SIZE+1];
		
		scanf("%s",buf);
		buf[MID_POS] = ' ';
		
		sscanf(buf,"%d %d",&c[i].h,&c[i].m);
	}
}

void	get_degree(Clock* c)
{
	for(int i=0;i<MAX_SIZE;i++)
	{
		c[i].d = cal_degree(c[i].h,c[i].m);
	}
}

bool	is_less(const Clock& c1,const Clock& c2)
{
	bool	ret;
	
	if( (c1.d<c2.d) || ((c1.d==c2.d)&&(c1.h*60+c1.m<c2.h*60+c2.m)) )
	{
		ret = true;
	}
	else
	{
		ret = false;
	}
	
	return	ret;
}

int		main(void)
{
	int	N;
	
	scanf("%d",&N);
	
	for(int i=0;i<N;i++)
	{
		Clock	c[MAX_SIZE+1];
		
		input(c);
		get_degree(c);
		sort(&c[0],&c[MAX_SIZE],is_less);
		
		printf("%02d:%02d\n",c[MID_POS].h,c[MID_POS].m);
	}
	
	return	0;
}

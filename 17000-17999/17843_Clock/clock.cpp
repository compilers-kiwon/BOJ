#include	<iostream>

using namespace	std;

double	get_degree(double d1,double d2)
{
	double	ret;
	
	ret = max(d1,d2)-min(d1,d2);;
	
	if( ret > 180.0 )
	{
		ret = 360.0 - ret;
	}
	
	return	ret;
}

double	find_min_degree(double d1,double d2,double d3)
{
	return	min(min(get_degree(d1,d2),get_degree(d1,d3)),get_degree(d2,d3));
}

int		main(void)
{
	int	T;
	
	scanf("%d",&T);
	
	for(int i=1;i<=T;i++)
	{
		double	h,m,s;
		double	h_degree,m_degree,s_degree;
		
		scanf("%lf %lf %lf",&h,&m,&s);
		
		s_degree = 360.0*(s/60.0);
		m_degree = 360.0*(m/60.0) + 360.0*(1.0/60.0)*(s/60.0);
		h_degree = 360.0*(h/12.0) + 360.0*(1.0/12.0)*(m/60.0) + 360.0*(1.0/12.0)*(1.0/60.0)*(s/60.0);
		
		printf("%.6f\n",find_min_degree(s_degree,m_degree,h_degree));
	}
	
	return	0;
}

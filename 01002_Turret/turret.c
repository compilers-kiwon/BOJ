#include	<stdio.h>
#include	<math.h>

#define	D_ABS(n)	((n)<0.0?-1.0*(n):(n))

double	get_distance(double x1,double y1,double x2,double y2)
{
	double	x_delta,y_delta;
	
	x_delta = x2-x1;
	y_delta = y2-y1;
	
	return	sqrt(x_delta*x_delta+y_delta*y_delta);
}

int		main(void)
{
	double	x1,y1,r1;
	double	x2,y2,r2;
	
	int		x1_i,y1_i,r1_i;
	int		x2_i,y2_i,r2_i;
	int		T,result;
	
	scanf("%d",&T);
	
	while(T>0)
	{
		scanf("%d %d %d %d %d %d",&x1_i,&y1_i,&r1_i,&x2_i,&y2_i,&r2_i);
		
		x1 = (double)x1_i;
		y1 = (double)y1_i;
		r1 = (double)r1_i;
		
		x2 = (double)x2_i;
		y2 = (double)y2_i;
		r2 = (double)r2_i;
		
		if( (x1==x2) && (y1==y2) )
		{
			if( r1 == r2 )
			{
				result = -1;
			}
			else
			{
				result = 0;
			}
		}
		else
		{
			double	d,big_r,small_r,R;
			
			if( r1 > r2 )
			{
				big_r = r1;
				small_r = r2;
			}
			else
			{
				big_r = r2;
				small_r = r1;
			}
			
			R = big_r+small_r;
			
			d = get_distance(x1,y1,x2,y2);
			
			if( d > R )
			{
				result = 0;
			}
			else if( d == R )
			{
				result = 1;
			}
			else if( big_r-small_r < d && d < R )
			{
				result = 2;
			}
			else if( big_r == small_r+d )
			{
				result = 1;
			}
			else if( big_r > small_r+d )
			{
				result = 0;
			}
		}
		
		printf("%d\n",result);
		
		T--;
	}
	
	return	0;
}

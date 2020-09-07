#include	<iostream>
#include	<cmath>

using namespace	std;

int	main(void)
{
	int	T;
	
	scanf("%d",&T);
	
	for(int t=1;t<=T;t++)
	{
		int		N;
		double	left,right,top,bottom;
		
		scanf("%d",&N);
		left = bottom = 1000.0;
		right = top = -1000.0; 
		
		for(int i=1;i<=N;i++)
		{
			double	X,Y;
			
			scanf("%lf %lf",&X,&Y);
			
			left = min(left,X);
			bottom = min(bottom,Y);
			right = max(right,X);
			top = max(top,Y);
		}
		
		double	w,h,area,perimeter;
		
		w = right-left;
		h = top-bottom;
		
		area = w*h;
		perimeter = (w+h)*2;
		
		printf("Case %d: Area %.10g, Perimeter %.10g\n",t,area,perimeter);
	}
	
	return	0;
}

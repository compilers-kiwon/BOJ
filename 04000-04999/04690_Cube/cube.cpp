#include	<iostream>

using namespace	std;

#define	MAX_NUM	100

void	find_triple(int a)
{
	int	b,c,d;
	int	a_cube,b_cube,c_cube,d_cube;
	
	a_cube = a*a*a;
	
	for(b=2;(b_cube=b*b*b)<a_cube;b++)
	{
		for(c=b+1;(c_cube=c*c*c)<a_cube-b_cube;c++)
		{
			for(d=c+1;(d_cube=d*d*d)<=a_cube-b_cube-c_cube;d++)
			{
				if( a_cube == b_cube+c_cube+d_cube )
				{
					printf("Cube = %d, Triple = (%d,%d,%d)\n",a,b,c,d);
				}
			}
		}
	}
}

int		main(void)
{
	for(int i=2;i<=MAX_NUM;i++)
	{
		find_triple(i);
	}
	return	0;
}

#include	<iostream>

using namespace	std;

int	get_gcd(int a,int b)
{
	int min_num,max_num,gcd;
	
	min_num = min(a,b);
	max_num = max(a,b);
	
	if( max_num%min_num == 0 )
	{
		return	min_num;
	}
	
	gcd = 1;
	
	for(int i=min_num/2;i>1;i--)
	{
		if( a%i==0 && b%i == 0 )
		{
			gcd = i;
			break;
		}
	}
	return	gcd;
}

int	main(void)
{
	int	T;
	
	scanf("%d\n",&T);
	
	while(T>0)
	{
		int	M,N,x,y;
		int	to,from,max_year,answer;
		
		scanf("%d %d %d %d",&M,&N,&x,&y);
		
		to = M*N/get_gcd(M,N);
		max_year = max(M,N);
		answer = -1;
		x = (x-1)%M;
		y = (y-1)%N;
		
		if( max_year == M )
		{
			from = x;
		}
		else
		{
			from = y;
		}
		
		while( from <= to )
		{
			if( x == from%M && y == from%N )
			{
				answer = from;
				break;
			}
			from = from+max_year;
		}
		printf("%d\n",answer==-1?-1:answer+1);
		
		T--;
	}
	return	0;
}

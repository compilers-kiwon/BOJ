#include	<iostream>

using namespace	std;

#define	MAX_SIZE	(2000+1)

int	N,seq[2][MAX_SIZE];

int	get_value(int left_offset,int right_offset)
{
	int	sum,h,t;
	
	sum = 0;
	
	for(h=1+left_offset,t=N-right_offset;h<t;h++,t--)
	{
		sum += seq[0][h]*seq[1][t]+seq[0][t]*seq[1][h];
	}
	
	if( h == t )
	{
		sum += seq[0][h]*seq[1][t];
	}
	
	return	sum;
}

int	main(void)
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	
	cin>>N;
	
	for(int i=0;i<2;i++)
	{
		for(int j=1;j<=N;j++)
		{
			cin>>seq[i][j];
		}
	}
	
	int	B,E,max_value;
	
	max_value = -2000000000;
	
	for(int i=0;i<N;i++)
	{
		for(int j=0;i+j<N&&j<N;j++)
		{
			int	s;
			
			s = get_value(i,j);
			
			if( s > max_value )
			{
				B = i;
				E = j;
				max_value = s;
			}
		}
	}
	
	cout<<B<<' '<<E<<'\n'<<max_value<<'\n';
	
	return	0;
}

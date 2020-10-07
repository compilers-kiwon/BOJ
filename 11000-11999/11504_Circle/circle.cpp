#include	<iostream>

using namespace	std;

#define	MAX_SIZE			100
#define	get_index(i,size)	((i)%(size))

int	N,M,X,Y,num[MAX_SIZE];

void	input(void)
{
	cin>>N>>M;
	X = Y = 0;
	
	for(int i=1;i<=M;i++)
	{
		int	n;
		
		cin>>n;
		X = X*10+n;
	}
	
	for(int i=1;i<=M;i++)
	{
		int	n;
		
		cin>>n;
		Y = Y*10+n;
	}
	
	for(int i=0;i<N;i++)
	{
		cin>>num[i];
	}
}

int		get_number(int s)
{
	int	ret;
	
	ret = 0;
	
	for(int i=0;i<M;i++)
	{
		ret = ret*10+num[get_index(s+i,N)];
	}
	
	return	ret;
}

int		main(void)
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	
	int	T;
	
	cin>>T;
	
	for(int t=1;t<=T;t++)
	{
		int	cnt;
		
		input();
		cnt = 0;
		
		for(int i=0;i<N;i++)
		{
			int	Z;
			
			Z = get_number(i);
			
			if( X<=Z && Z<=Y )
			{
				cnt++;
			}
		}
		
		cout<<cnt<<'\n';
	}
	
	return	0;
}

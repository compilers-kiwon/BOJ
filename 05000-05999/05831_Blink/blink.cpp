#include	<iostream>

using namespace	std;

#define	MAX_STATE	(2<<16)
#define	UNVISITED	-1

#define	ON	1
#define	OFF	0

typedef	long long int	int64;

int		N,dp[MAX_STATE];
int64	B,T;

int		toggle_light(int light)
{
	int	ret = 0;
	
	for(int i=N-1;i>=1;i--)
	{
		int	current = (light>>i)%2;
		int	right = (light>>(i-1))%2;
		int	n;
		
		if( current == OFF )
		{
			n = right;	 
		}
		else
		{
			n = (right==ON)?OFF:ON;
		}
		
		ret += n<<(i-1);
	}
	
	if( light%2 == OFF )
	{
		ret += (light>>(N-1))<<(N-1);
	}
	else
	{
		ret += ((light>>(N-1))==OFF?ON:OFF)<<(N-1);
	}
	
	return	ret;
}

void	print(int light)
{
	for(int i=N-1;i>=0;i--)
	{
		cout<<(light>>i)%2<<'\n';
	}
}

int		simulate(int light)
{
	int	ret;
	
	for(T=1,dp[light]=0;T<=B;T++)
	{
		ret = toggle_light(light);
		
		if( dp[ret] != UNVISITED )
		{
			int64	p = T-(int64)dp[ret];
			int64	n = (B-(int64)dp[ret])%p;
			
			for(int i=1;i<=(int)n;i++)
			{
				ret = toggle_light(ret);
			}
			
			break;
		}
		
		dp[ret] = T;
		light = ret;
	}

	return	ret;
}

int		input(void)
{
	int	ret = 0;
	
	cin>>N>>B;
	fill(&dp[0],&dp[1<<N],UNVISITED);
	
	for(int i=1;i<=N;i++)
	{
		int	b;
		
		cin>>b;
		ret = ret*2+b;
	}

	return	ret;
}

int		main(void)
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	
	int		light;

	light = input();
	print(simulate(light));

	return	0;
}

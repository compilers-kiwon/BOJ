#include	<iostream>
#include	<algorithm>

using namespace	std;

#define	MAX_NUM_OF_DATA	(100000+1)

int		data[MAX_NUM_OF_DATA];

void	input(int& N,int& K)
{
	cin>>N>>K;
	
	for(int i=1;i<=N;i++)
	{
		double	d;
		
		cin>>d;
		data[i] = (int)(d*10.0);
	}
	
	sort(&data[1],&data[N+1]);
}

int		get_t_mean(int& N,int& K,int& sum)
{
	sum = 0;
	
	for(int i=K+1;i<=N-K;i++)
	{
		sum += data[i];
	}
	
	return	sum*100/(N-K-K);
}

int		get_a_mean(int& N,int& K,int& sum)
{
	sum += (data[K+1]+data[N-K])*K;
	
	return	sum*100/N;
}

int		main(void)
{
	int		N,K,t_mean,a_mean,sum;
	
	input(N,K);
	
	t_mean = (get_t_mean(N,K,sum)+5)/10;
	a_mean = (get_a_mean(N,K,sum)+5)/10;
	
	printf("%d.%02d\n",t_mean/100,t_mean%100);
	printf("%d.%02d\n",a_mean/100,a_mean%100);
	
	return	0;
}

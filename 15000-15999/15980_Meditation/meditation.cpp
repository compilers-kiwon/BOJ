#include	<iostream>
#include	<string>
#include	<cmath>

using namespace	std;

#define	MAX_SIZE	(2000+1)

int		N,M;
int		noise_table[MAX_SIZE],bird_table[MAX_SIZE][MAX_SIZE];

void	input(void)
{
	cin>>N>>M;
	
	for(int i=1;i<=N;i++)
	{
		char	s;
		string	noise;
		int		sign;
		
		cin>>s>>noise;
		
		if( s == 'L' )
		{
			sign = -1;
		}
		else
		{
			sign = 1;
		}
		
		for(int j=0;j<M;j++)
		{
			int&	n = bird_table[i][j];
			
			n = sign*(int)(noise[j]-'0');
			noise_table[j] += n;
		}
	}
}

void	get_min_noise(int& bird,int& min_noise)
{
	min_noise = 0x7FFFFFFF;
	
	for(int i=1;i<=N;i++)
	{
		int	tmp,sum;
		
		tmp = sum = 0;
		
		for(int j=0;j<M;j++)
		{
			sum += noise_table[j]-bird_table[i][j];
			tmp = max(tmp,abs(sum));
		}
		
		if( tmp < min_noise )
		{
			bird = i;
			min_noise = tmp;
		}
	}
}

int		main(void)
{
	int	b,n;
	
	input();
	get_min_noise(b,n);
	cout<<b<<'\n'<<n<<'\n';
	
	return	0;
}

#include	<iostream>

using namespace	std;

void	round(int& a,int& b,int& c)
{
	a += 5;
	b = a/100;
	c =(a%100)/10;
}

int		main(void)
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	
	int	T;
	
	cin>>T;
	
	for(;T>0;T--)
	{
		int		N,C,sum_C;
		double	G,sum_G;
		
		cin>>N;
		
		sum_C = 0;
		sum_G = 0.0;
		
		for(int i=1;i<=N;i++)
		{
			cin>>C>>G;
			
			sum_C += C;
			sum_G += ((double)C)*G*100.0;
		}
		
		int	s,i,f;
		
		s = ((int)sum_G)/sum_C;
		round(s,i,f);
		
		cout<<sum_C<<' '<<i<<'.'<<f<<'\n';
	}
	
	return	0;
}

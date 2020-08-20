#include	<iostream>

using namespace	std;

#define	MAX_DAY	30

typedef	pair<int,int>	Cake;

void	init(Cake day[])
{
	day[1] = make_pair(1,0);
	day[2] = make_pair(0,1);
	
	for(int i=3;i<=MAX_DAY;i++)
	{
		day[i].first = day[i-1].first+day[i-2].first;
		day[i].second = day[i-1].second+day[i-2].second;
	}
}

void	solve(int& A,int& B,int a,int b,int num_of_cake)
{
	for(A=1;;A++)
	{
		int	sum;
		
		for(B=A,sum=0;sum<num_of_cake;B++)
		{
			sum = a*A+b*B;
			
			if( sum == num_of_cake )
			{
				return;
			}
		}
	}
}

int		main(void)
{
	int		D,K,A,B;
	Cake	c[MAX_DAY+1];
	
	init(c);
	
	cin>>D>>K;
	solve(A,B,c[D].first,c[D].second,K);
	cout<<A<<endl<<B<<endl;
	
	return	0;
}

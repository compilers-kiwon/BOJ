#include	<iostream>
#include	<vector>

using namespace	std;

#define	MAX_CANDIDATE	(100+1)
#define	MAX_DONOR		(1000+1)

#define	MAX_AMOUNT_TO_CANDIDATE	2100
#define	MAX_TOTAL_AMOUNT		40000

int	c,d,t;
int	donation[MAX_CANDIDATE][MAX_DONOR];
int	total_amount[MAX_DONOR];

void	input(void)
{
	cin>>c>>d>>t;
	
	for(int row=1;row<=c;row++)
	{
		fill(&donation[row][1],&donation[row][d+1],0);
	}
	
	fill(&total_amount[1],&total_amount[d+1],0);
	
	for(int i=1;i<=t;i++)
	{
		int	d,c,m;
		
		cin>>d>>c>>m;
		
		donation[c][d] += m;
		total_amount[d] += m;
	}
}

int		find_violation(bool* v)
{
	int	ret;
	
	ret = 0;
	fill(&v[1],&v[d+1],false);
	
	for(int row=1;row<=c;row++)
	{
		for(int col=1;col<=d;col++)
		{
			const int&	candidate = row;
			const int&	donor = col;
			
			if( v[donor]==false && donation[candidate][donor]>MAX_AMOUNT_TO_CANDIDATE )
			{
				v[donor] = true;
				ret++;
			}
		}
	}
	
	for(int i=1;i<=d;i++)
	{
		if( v[i]==false && total_amount[i]>MAX_TOTAL_AMOUNT )
		{
			v[i] = true;
			ret++;
		}
	}
	
	return	ret;
}

int		main(void)
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	
	int	K;
	
	cin>>K;
	
	for(int k=1;k<=K;k++)
	{
		bool	violation[MAX_DONOR];
		
		input();
		cout<<"Data Set "<<k<<":\n";
		
		if( find_violation(violation) == 0 )
		{
			cout<<"No violations\n";
		}
		else
		{
			cout<<"Violators:\n";
			
			for(int i=1;i<=d;i++)
			{
				if( violation[i] == true )
				{
					cout<<i<<'\n';
				}
			}
		}
	}
	
	return	0;
}

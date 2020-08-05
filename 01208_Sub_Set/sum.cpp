#include	<iostream>
#include	<vector>

using namespace	std;

#define	MAX_SIZE	(40+1)
#define	MAX_VALUE	100000

typedef	unsigned long long	uint64;

vector<int>	positive_sum_table(MAX_VALUE*(MAX_SIZE/2)+1,0),negative_sum_table(MAX_VALUE*(MAX_SIZE/2)+1,0);
int			n[MAX_SIZE+1];
int			N,S;
uint64		cnt;

void	build_table(int current,int to,int sum,bool	second_flag)
{
	if( current > to )
	{
		if( second_flag == false )
		{
			if( sum >= 0 )
			{
				positive_sum_table[sum]++;
			}
			else
			{
				negative_sum_table[-sum]++;
			}
		}
		else
		{
			int	tmp;
			
			tmp = S-sum;
			
			if( tmp>=-2000000 && tmp<=2000000 )
			{
				if( tmp >= 0 )
				{
					cnt += positive_sum_table[tmp];
				}
				else
				{
					cnt += negative_sum_table[-tmp];
				}
			}
		}
		return;
	}
	
	build_table(current+1,to,sum,second_flag);
	build_table(current+1,to,sum+n[current],second_flag);
}

int		main(void)
{
	cin>>N>>S;
	
	for(int i=1;i<=N;i++)
	{
		cin>>n[i];
	}
	
	cnt = 0;
	
	build_table(1,N/2,0,false);
	build_table(N/2+1,N,0,true);
	
	if( S == 0 )
	{
		cnt--;
	}
	cout<<cnt<<endl;
	
	return	0;
}

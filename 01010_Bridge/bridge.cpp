#include	<iostream>
#include	<vector>

using namespace std;

typedef	unsigned long long	uint64;

#define	MAX_NUM	30

uint64	cnt;

void	divide(uint64& n,vector<bool>& table,uint64 size)
{
	uint64	i;
	
	for(i=2;i<=size;i++)
	{
		if( table[i] == false && n%i == 0 )
		{
			table[i] = true;
			n = n/i;
			++cnt;
		}
	}
}

int		main(void)
{
	int	T;
	
	cin>>T;
	
	while(T-->0)
	{
		uint64			M,N,value,i;
		vector<bool>	table(MAX_NUM,false);
		
		cin>>N>>M;
		cnt = 0;
				
		if( N == M )
		{
			cout<<"1\n";
			continue;
		}
		else
		{
			for(i=M,value=1;i>M-N;i--)
			{
				value = value*i;
				
				if( cnt < N-1 )
				{
					divide(value,table,N);
				}
			}
		}
		cout<<value<<endl;
	}
	
	return	0;
}

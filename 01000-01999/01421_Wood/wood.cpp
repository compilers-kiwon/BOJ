#include	<iostream>

using namespace	std;

typedef	long long int	int64;

#define	MAX_NUM_OF_WOOD	(1000+1)

int		N;
int64	C,W,wood[MAX_NUM_OF_WOOD];

int64	get_profit(int wood_index,int64 len)
{
	int64&	wood_len = wood[wood_index];
	int64	K,num_of_cut;
	
	if( wood_len < len )
	{
		return	0;
	}
	
	K = wood_len/len;
	num_of_cut = (((K*len)==wood_len)?(K-1):K);
	
	return	max((int64)0,K*len*W-num_of_cut*C);
}

int		main(void)
{
	cin.sync_with_stdio(false);
	
	cin>>N>>C>>W;
	
	int64	max_profit,max_len;
	
	max_profit = max_len = 0;
	
	for(int i=1;i<=N;i++)
	{
		cin>>wood[i];
		max_len = max(max_len,wood[i]);
	}
	
	for(int cut_len=1;cut_len<=max_len;cut_len++)
	{
		int64	p;
		
		p = 0;
		
		for(int i=1;i<=N;i++)
		{
			p += get_profit(i,cut_len);
		}
		
		max_profit = max(max_profit,p);
	}
	
	cout<<max_profit<<'\n';
	
	return	0;
}

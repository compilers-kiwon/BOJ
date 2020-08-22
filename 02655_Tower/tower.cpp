#include	<iostream>
#include	<vector>
#include	<algorithm>

using namespace	std;

#define	MAX_NUM_OF_BLOCKS	(100+1)
#define	MAX_SIZE			10000

typedef	struct	_BLOCK_INFO	Block;
struct	_BLOCK_INFO
{
	int	area,height,weight,index;
};

bool	need_to_swap(Block& b1,Block& b2)
{
	return	!(b1.area<b2.area);
}

void	init_dp(vector<Block>& b,int& num_of_blocks,vector<int>& dp)
{
	cin>>num_of_blocks;
	
	b.resize(num_of_blocks+1);
	dp.resize(num_of_blocks+1);
	
	for(int i=1;i<=num_of_blocks;i++)
	{
		cin>>b[i].area>>b[i].height>>b[i].weight;
		b[i].index = i;
	}
	
	sort(&b[1],&b[num_of_blocks+1],need_to_swap);
	
	dp[1] = b[1].height;
}

int		main(void)
{
	vector<int>		dp;
	vector<int>		used_blocks[MAX_NUM_OF_BLOCKS];
	vector<Block>	blocks;
	int				N,max_height,index_of_max_height_blocks;
	
	init_dp(blocks,N,dp);
	
	max_height = dp[1];
	index_of_max_height_blocks = 1;
	used_blocks[1].push_back(blocks[1].index);
	
	for(int i=2;i<=N;i++)
	{
		int	tmp_max_height,tmp_index;
		
		tmp_max_height = tmp_index = 0;
		
		for(int j=1;j<i;j++)
		{
			if( blocks[j].weight>blocks[i].weight )
			{
				if( tmp_max_height < dp[j] )
				{
					tmp_max_height = dp[j];
					tmp_index = j;
				}
			}
		}
		
		tmp_max_height += blocks[i].height;
		dp[i] = tmp_max_height;
		used_blocks[i] = used_blocks[tmp_index];
		used_blocks[i].push_back(blocks[i].index);
		
		if( tmp_max_height > max_height )
		{
			max_height = tmp_max_height;
			index_of_max_height_blocks = i;
		}
	}
	
	cout<<used_blocks[index_of_max_height_blocks].size()<<endl;
	
	for(int i=used_blocks[index_of_max_height_blocks].size()-1;i>=0;i--)
	{
		cout<<used_blocks[index_of_max_height_blocks][i]<<endl;
	}
	
	return	0;
}

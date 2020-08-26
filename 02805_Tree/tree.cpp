#include	<cstdio>
#include	<map>

using namespace	std;

map<int,int>	tree;

int	main(void)
{
	int	N,M;
	
	scanf("%d %d",&N,&M);
	
	for(int i=1;i<=N;i++)
	{
		int	h;
		
		scanf("%d",&h);
		++tree[-h];
	}
	
	long long	length_of_cut_trees;
	int 		num_of_prev_trees,prev_len;
	int			answer = -1;
	int			cut_len,num_of_trees;
	long long	tmp_length_of_cut_trees;
	
	map<int,int>::iterator	tree_iter;
	
	for(num_of_prev_trees=length_of_cut_trees=prev_len=0,tree_iter=tree.begin();tree_iter!=tree.end();++tree_iter)
	{
		cut_len = -tree_iter->first;
		num_of_trees = tree_iter->second;
				
		tmp_length_of_cut_trees = (long long)((long long)(prev_len-cut_len)*(long long)num_of_prev_trees)+length_of_cut_trees;
		//printf("len=%d,length_of_cut_trees=%lld\n",cut_len,tmp_length_of_cut_trees);
		if( tmp_length_of_cut_trees >= (long long)M )
		{
			int	prev_cut_len = cut_len;
				
			for(int i=cut_len+1;i<prev_len;i++)
			{
				tmp_length_of_cut_trees = (long long)((long long)(prev_len-i)*(long long)num_of_prev_trees)+length_of_cut_trees;
				//printf("\tlen=%d,length_of_cut_trees=%lld\n",i,tmp_length_of_cut_trees);	
				if( tmp_length_of_cut_trees >= (long long)M )
				{
					prev_cut_len = i;
				}
				else
				{
					break;
				}
			}
			answer = prev_cut_len;
			
			break;
		}
		prev_len = cut_len;
		num_of_prev_trees += num_of_trees;
		length_of_cut_trees = tmp_length_of_cut_trees; 
	}
	
	if( answer == -1 )
	{
		int	prev_cut_len = cut_len;
				
			for(int i=1;i<prev_len;i++)
			{
				tmp_length_of_cut_trees = (long long)((long long)(prev_len-i)*(long long)num_of_prev_trees)+length_of_cut_trees;
				//printf("\t\tlen=%d,length_of_cut_trees=%lld\n",i,tmp_length_of_cut_trees);	
				if( tmp_length_of_cut_trees >= (long long)M )
				{
					prev_cut_len = i;
				}
				else
				{
					break;
				}
			}
			answer = prev_cut_len;
	}
	
	printf("%d\n",answer);
	
	return	0;
}

//printf("len=%d,length_of_cut_trees=%d\n",cut_len,tmp_length_of_cut_trees);

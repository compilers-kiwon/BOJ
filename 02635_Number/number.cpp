#include	<iostream>
#include	<vector>

using namespace	std;

#define	MAX_NUM	30000

vector<int>	num_list[MAX_NUM+1];

void	build_num_list(int n)
{
	vector<int>&	v = num_list[n];
	
	int	current_index,tmp;
	
	for(current_index=v.size();;current_index++)
	{
		tmp = v[current_index-2]-v[current_index-1];
		
		if( tmp >= 0 )
		{
			v.push_back(tmp);	
		}
		else
		{
			break;
		}	
	}				
}

int		main(void)
{
	int	N,max_len,max_len_index,i;
	
	cin>>N;
	
	for(i=1,max_len=0;i<=N;i++)
	{
		num_list[i].push_back(N);
		num_list[i].push_back(i);
		
		build_num_list(i);
		
		if( num_list[i].size() > max_len )
		{
			max_len = num_list[i].size();
			max_len_index = i;
		}
	}
	
	cout<<max_len<<endl;
	
	for(i=0;i<num_list[max_len_index].size();i++)
	{
		cout<<num_list[max_len_index][i]<<' ';
	}
	
	return	0;
}

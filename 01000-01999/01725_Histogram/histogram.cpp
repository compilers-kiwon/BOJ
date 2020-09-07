#include	<iostream>
#include	<stack>
#include	<vector>

using namespace	std;

typedef	unsigned long long	uint64;

int	main(void)
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	
	int				N;
	uint64			max_size;
	stack<int>		st;
	vector<uint64>	h;
	
	cin>>N;
	max_size = 0;
	
	h.resize(N+1);
	
	for(int i=1;i<=N;i++)
	{
		cin>>h[i];
	}
	
	h.push_back(0);
	
	for(int current_histo=1;current_histo<=N+1;current_histo++)
	{
		for(;!st.empty();)
		{
			int		prev_histo;
			uint64	prev_height;
			
			prev_histo = st.top();			
			prev_height = h[prev_histo];
			
			if( prev_height <= h[current_histo] )
			{
				break;
			}
			
			st.pop();
			
			uint64	left,right;
			
			if( st.empty() )
			{
				left = 1;
			}
			else
			{
				left = st.top()+1;
			}
			
			right = current_histo-1;
			
			max_size = max(max_size,prev_height*(right-left+1));
		}
		
		st.push(current_histo);
	}
	
	cout<<max_size<<'\n';

	return	0;
}

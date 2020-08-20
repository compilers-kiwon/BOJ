#include	<iostream>

using namespace	std;

#define	MAX_SEQ_LEN	(100000+1)

int	main(void)
{
	int	N;
	
	cin>>N;
	
	int	current_decreasing_len,max_decreasing_len;
	int	current_increasing_len,max_increasing_len;
	int	prev;
	
	current_decreasing_len = max_decreasing_len = 0;
	current_increasing_len = max_increasing_len = 0;
	prev = 0;
	
	for(int i=1;i<=N;i++)
	{
		int	n;
		
		cin>>n;
		
		if( n < prev )
		{
			++current_decreasing_len;
			max_increasing_len = max(max_increasing_len,current_increasing_len);
			current_increasing_len = 1;
		}
		else if( n > prev )
		{
			++current_increasing_len;
			max_decreasing_len = max(max_decreasing_len,current_decreasing_len);
			current_decreasing_len = 1;
		}
		else
		{
			++current_decreasing_len;
			++current_increasing_len;
		}
		prev = n;
	}
	
	max_increasing_len = max(max_increasing_len,current_increasing_len);
	max_decreasing_len = max(max_decreasing_len,current_decreasing_len);
	
	cout<<max(max_increasing_len,max_decreasing_len)<<endl;
	
	return	0;
}

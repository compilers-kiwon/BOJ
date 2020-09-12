#include	<iostream>
#include	<algorithm>

using namespace	std;

#define	MAX_NUM_OF_PAPERS	(1000+1)

bool	is_greater(const int& n1,const int& n2)
{
	return	n1>n2;
}

int		main(void)
{
	int	n,paper[MAX_NUM_OF_PAPERS];
	
	cin>>n;
	
	for(int i=1;i<=n;i++)
	{
		cin>>paper[i];
	}
	
	sort(&paper[1],&paper[n+1],is_greater);
	
	int	max_q_index;
	
	max_q_index = 0;
	
	for(int i=1;i<=n;i++)
	{
		if( i >= paper[i] )
		{
			max_q_index = max(max_q_index,paper[i]);
		}
	}
	cout<<max_q_index<<endl;
	
	return	0;
}

#include	<iostream>
#include	<algorithm>

using namespace	std;

#define	MAX_SIZE	(8+1)

void	build_seq(int* num,int* seq,int num_index,int index,int size,int len)
{
	if( index > len )
	{
		for(int i=1;i<=len;i++)
		{
			cout<<seq[i]<<' ';
		}
		cout<<'\n';
		
		return;
	}
	
	for(int i=num_index;i<=size;i++)
	{
		seq[index] = num[i];
		build_seq(num,seq,i,index+1,size,len);
	}
}

int		main(void)
{
	int	num[MAX_SIZE];
	int	seq[MAX_SIZE];
	int	N,M;
	
	cin>>N>>M;
	
	for(int i=1;i<=N;i++)
	{
		cin>>num[i];
	}
	
	sort(&num[1],&num[N+1]);
	
	build_seq(num,seq,1,1,N,M);
	
	return	0;
}

#include	<iostream>
#include	<algorithm>

using namespace	std;

#define	MAX_SIZE	(8+1)
#define	FALSE		0

void	build_seq(int* num,int* seq,int index,int size,int len)
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
	
	for(int i=1;i<=size;i++)
	{
		if( num[i] != FALSE )
		{
			seq[index] = num[i];
			num[i] = FALSE;
			
			build_seq(num,seq,index+1,size,len);
			
			num[i] = seq[index];
		}
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
	
	build_seq(num,seq,1,N,M);
	
	return	0;
}

#include	<iostream>

using namespace	std;

#define	MAX_SIZE	(7+1)

void	build_seq(int* seq,int index,int size,int len)
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
		seq[index] = i;
		build_seq(seq,index+1,size,len);
	}
}

int		main(void)
{
	int		seq[MAX_SIZE];
	int		N,M;
	
	cin>>N>>M;
	
	build_seq(seq,1,N,M);
	
	return	0;
}

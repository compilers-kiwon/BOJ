#include	<iostream>

using namespace	std;

#define	MAX_SIZE	(8+1)

void	build_seq(bool* used,int* seq,int index,int size,int len)
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
		if( used[i] == false )
		{
			used[i] = true;
			seq[index] = i;
			
			build_seq(used,seq,index+1,size,len);
			
			used[i] = false;
		}
	}
}

int		main(void)
{
	bool	used[MAX_SIZE];
	int		seq[MAX_SIZE];
	int		N,M;
	
	cin>>N>>M;
	
	for(int i=1;i<=N;i++)
	{
		used[i] = false;
	}
	
	build_seq(used,seq,1,N,M);
	
	return	0;
}

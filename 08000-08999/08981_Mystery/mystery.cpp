#include	<iostream>

using namespace	std;

#define	MAX_SIZE	30
#define	EMPTY		0

int	N,out[MAX_SIZE],in[MAX_SIZE];

void	init(void)
{
	cin>>N;
	
	for(int i=0;i<N;i++)
	{
		cin>>out[i];
	}
}

void	build_input(void)
{
	int		in_index,out_index,i;
	
	for(in_index=out_index=0;out_index<N;out_index++)
	{
		while( in[in_index] != EMPTY )
		{
			in_index = (in_index+1)%N;
		}
		
		in[in_index] = out[out_index];
		in_index = (in_index+out[out_index])%N;
	}
}

int		main(void)
{
	cin.sync_with_stdio(false);
	
	init();
	build_input();
	
	cout<<N<<'\n';
	
	for(int i=0;i<N;i++)
	{
		cout<<in[i]<<' ';
	}
	cout<<'\n';
	
	return	0;
}

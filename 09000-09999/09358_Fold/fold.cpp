#include	<iostream>

using namespace	std;

typedef	long long int	int64;

#define	MAX_SIZE	(100+1)

void	fold(int64* n,int& size)
{
	int	head,tail;
	
	for(head=1,tail=size;head<=tail;head++,tail--)
	{
		n[head] += n[tail];
	}
	
	size = head-1; 
}

int		main(void)
{
	int	T;
	
	cin>>T;
	
	for(int c=1;c<=T;c++)
	{
		int		N;
		int64	n[MAX_SIZE];
		
		cin>>N;
		
		for(int i=1;i<=N;i++)
		{
			cin>>n[i];
		}
		
		while( N>2 )
		{
			fold(n,N);
		}
		
		if(n[1] > n[2] )
		{
			cout<<"Case #"<<c<<": Alice\n";
		}
		else
		{
			cout<<"Case #"<<c<<": Bob\n";
		}
	}
	
	return	0;
}

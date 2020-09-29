#include	<iostream>

using namespace	std;

#define	MAX_KINDS_OF_CARD	4

char	winner(int* A,int* B)
{
	char ret;
	
	ret = 'D';
	
	for(int i=MAX_KINDS_OF_CARD;i>=1;i--)
	{
		if( A[i] > B[i] )
		{
			ret = 'A';
			break;
		}
		
		if( A[i] < B[i] )
		{
			ret = 'B';
			break;
		}
	}
	
	return	ret;
}

void	input(int* arr)
{
	int	n;
	
	cin>>n;
	
	for(int i=1;i<=n;i++)
	{
		int c;
		
		cin>>c;
		arr[c]++;
	}
}

int		main(void)
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	
	int	N;
	
	cin>>N;
	
	for(int i=1;i<=N;i++)
	{
		int	A[MAX_KINDS_OF_CARD+1],B[MAX_KINDS_OF_CARD];
		
		fill(&A[1],&A[MAX_KINDS_OF_CARD+1],0);
		fill(&B[1],&B[MAX_KINDS_OF_CARD+1],0);
		
		input(A);
		input(B);
		
		cout<<winner(A,B)<<'\n';
	}
	
	return	0;
}

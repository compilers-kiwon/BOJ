#include	<iostream>

using namespace	std;

#define	MIN_PACKAGE	30

int	main(void)
{
	int	T,nA,nB,nC;
	
	cin.sync_with_stdio(false);
	
	cin>>T;
	nA = nB = nC = 0;
	 
	for(int i=1;i<=T;i++)
	{
		int	A,B,C,P;
		
		cin>>A>>B>>C;
		
		nA += A;
		nB += B;
		nC += C;
		P = min(nA,min(nB,nC));
		
		if( P >= MIN_PACKAGE )
		{
			nA -= P;
			nB -= P;
			nC -= P;
			cout<<P<<'\n';
		}
		else
		{
			cout<<"NO\n";
		}
	}
	
	return	0;
}

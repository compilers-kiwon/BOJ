#include	<iostream>

using namespace	std;

int	main(void)
{
	int	N,cnt,i;
	
	cin>>N;
	
	for(cnt=0,i=1;i<=N;i++)
	{
		int	n;
		
		cin>>n;
		cnt += (n!=i)?1:0;
	}
	cout<<cnt<<endl;
	
	return	0;
}

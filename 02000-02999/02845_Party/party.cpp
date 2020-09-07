#include	<iostream>

using namespace	std;

#define	NUM_OF_PAPER	5

int	main(void)
{
	int	L,P;
	int	num_of_people;
	
	cin>>L>>P;
	num_of_people = L*P;
	
	for(int i=1;i<=NUM_OF_PAPER;i++)
	{
		int	p;
		
		cin>>p;
		cout<<p-num_of_people<<' ';
	}
	cout<<endl;
	
	return	0;
}

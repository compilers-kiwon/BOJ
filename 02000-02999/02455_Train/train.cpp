#include	<iostream>

using namespace std;

#define	NUM_OF_STATIONS	4

int		main(void)
{
	int	num_of_people,i,max_num;
	
	for(num_of_people=0,max_num=0,i=1;i<=NUM_OF_STATIONS;i++)
	{
		int	on,off;
		
		cin>>off>>on;
		num_of_people = num_of_people+on-off;
		max_num = max(max_num,num_of_people);
	}
	cout<<max_num<<endl;
	
	return	0;
}

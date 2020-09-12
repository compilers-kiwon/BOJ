#include	<iostream>

using namespace	std;

#define	NUM_OF_CLASSES	6

#define	GIRL	0
#define	BOY		1

int	N,K,student[NUM_OF_CLASSES+1][BOY+1];

int	main(void)
{
	cin>>N>>K;
	
	for(int i=1;i<=N;i++)
	{
		int	S,Y;
		
		cin>>S>>Y;
		student[Y][S]++;
	}
	
	int	num_of_room = 0;
	
	for(int i=1;i<=NUM_OF_CLASSES;i++)
	{
		num_of_room += (student[i][GIRL]/K)+((student[i][GIRL]%K)!=0);
		num_of_room += (student[i][BOY]/K)+((student[i][BOY]%K)!=0);
	}
	cout<<num_of_room<<endl;
	
	return	0;
}

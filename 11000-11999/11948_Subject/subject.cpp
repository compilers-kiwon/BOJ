#include	<iostream>
#include	<algorithm>

using namespace	std;

#define	A					0
#define	B					1
#define	C					2
#define	D					3
#define	E					4
#define	F					5
#define	MAX_NUM_OF_SCORES	6

int	main(void)
{
	int	score[MAX_NUM_OF_SCORES];
	
	for(int i=A;i<=F;i++)
	{
		cin>>score[i];
	}
	
	sort(&score[A],&score[D+1]);
	
	cout<<score[1]+score[2]+score[3]+max(score[E],score[F])<<endl;
	
	return	0;
}

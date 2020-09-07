#include	<iostream>
#include	<cmath>

using namespace	std;

typedef	struct	_CONST_INFO	Const;
struct	_CONST_INFO
{
	double	A,B,C;
	int		type;
};

#define	NUM_OF_GAME	7

#define	TRACK	0
#define	FIELD	1

const Const	factor[NUM_OF_GAME+1] = {
	{},
	{9.23076,26.7,1.835,TRACK},
	{1.84523,75,1.348,FIELD},
	{56.0211,1.5,1.05,FIELD},
	{4.99087,42.5,1.81,TRACK},
	{0.188807,210,1.41,FIELD},
	{15.9803,3.8,1.04,FIELD},
	{0.11193,254,1.88,TRACK}
};

#define	TRACK_SCORE(A,B,C,P)	((A)*pow(((B)-(P)),(C)))
#define	FIELD_SCORE(A,B,C,P)	((A)*pow(((P)-(B)),(C)))

int	get_score(int* P)
{
	int	sum,i;	
	
	for(i=1,sum=0;i<=NUM_OF_GAME;i++)
	{
		if( factor[i].type == FIELD )
		{
			sum += FIELD_SCORE(factor[i].A,factor[i].B,factor[i].C,P[i]);
		}
		else
		{
			sum += TRACK_SCORE(factor[i].A,factor[i].B,factor[i].C,P[i]);
		}
	}
	
	return	sum;
}

int	main(void)
{
	cin.sync_with_stdio(false);
	
	int	T;
	
	cin>>T;
	
	while(T>0)	
	{
		int	P[NUM_OF_GAME+1];
		
		for(int i=1;i<=NUM_OF_GAME;i++)
		{
			cin>>P[i];
		}
		
		cout<<get_score(P)<<'\n';
		
		T--;
	}
	
	return	0;
}

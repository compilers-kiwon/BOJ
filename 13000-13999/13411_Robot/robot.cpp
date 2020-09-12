#include	<iostream>
#include	<algorithm>
#include	<cmath>

using namespace	std;

#define	MAX_NUM_OF_ROBOT	(100000+1)

typedef	long double		ld;
typedef	pair<ld,int>	Robot;

int		N;
Robot	R[MAX_NUM_OF_ROBOT];

void	input(void)
{
	scanf("%d",&N);
	
	for(int i=1;i<=N;i++)
	{
		ld X,Y,V,d;
		
		scanf("%Lf %Lf %Lf",&X,&Y,&V);
		
		d = sqrt(X*X+Y*Y);
		R[i] = make_pair(d/V,i);
	}
}

bool	is_less(const Robot& r1,const Robot& r2)
{
	return	((r1.first<r2.first) || (r1.first==r2.first && r1.second<r2.second));
}

int		main(void)
{
	input();
	
	sort(&R[1],&R[N+1],is_less);
	
	for(int i=1;i<=N;i++)
	{
		printf("%d\n",R[i].second);
	}
	
	return	0;
}

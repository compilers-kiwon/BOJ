#include	<iostream>
#include	<vector>
#include	<stdio.h>

using namespace std;

#define	MAX(a,b)	((a)>(b)?(a):(b))

int	main(void)
{
	int			N,M,i;
	vector<int>	score;
	
	cin>>N;
	
	for(M=0,i=1;i<=N;i++)
	{
		int	n;
		
		cin>>n;
		score.push_back(n);
		M = MAX(M,n);
	}
	
	double	avg;
	
	for(avg=0.0,i=0;i<score.size();i++)
	{
		avg = avg+((double)score[i])/((double)M)*100.0;
	}
	avg = avg/(double)N;
	
	printf("%.02f\n",avg);
	
	return	0;
}

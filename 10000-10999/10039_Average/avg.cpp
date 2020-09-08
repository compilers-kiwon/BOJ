#include	<iostream>

using namespace std;

#define	MAX(a,b)	((a)>(b)?(a):(b))

int	main(void)
{
	int	n[5],i,avg;
	
	for(i=0;i<5;i++)
	{
		cin>>n[i];
	}
	
	for(avg=0,i=0;i<5;i++)
	{
		avg = avg+MAX(n[i],40);
	}
	avg = avg/5;
	cout<<avg<<endl;
	
	return	0;
}

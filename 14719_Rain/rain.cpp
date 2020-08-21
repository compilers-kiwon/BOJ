#include	<iostream>

using namespace std;

#define	MAX_SIZE	(500+1)

int	get_highest(int begin,int end,int* h)
{
	int	ret,i;
	
	for(ret=0,i=begin;i<=end;i++)
	{
		ret = max(ret,h[i]);
	}
	
	return	ret;
}

int	main(void)
{
	int	H,W,w[MAX_SIZE],ret;
	
	cin>>H>>W;
	ret = 0;
	
	for(int i=1;i<=W;i++)
	{
		cin>>w[i];
	}
	
	for(int i=1;i<=W;i++)
	{
		int	left_highest,right_highest;
		
		left_highest = get_highest(1,i-1,w);
		right_highest = get_highest(i+1,W,w);
		
		ret += max(0,min(left_highest,right_highest)-w[i]);
	}
	
	cout<<ret<<'\n';
	
	return	0;
}

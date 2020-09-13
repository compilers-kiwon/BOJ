#include	<iostream>

using namespace	std;

#define	MAX_LEN	(100000+1)
#define	abs(n)	(((n)>=0)?(n):-(n))

int	s[MAX_LEN];

int	main(void)
{
	int	N,h,t,min_sum;
	
	cin>>N;
	
	for(int i=1;i<=N;i++)
	{
		cin>>s[i];
	}
	
	min_sum = 0x7FFFFFFF;
	
	for(h=1,t=N;h<t;)
	{
		int	tmp;
		
		tmp = s[h]+s[t];
		
		if( abs(min_sum) > abs(tmp) )
		{
			min_sum = tmp;
		}
		
		if( tmp >= 0 )
		{
			t--;
		}
		else
		{
			h++;
		}
	}
	
	cout<<min_sum<<endl;

	return	0;
}

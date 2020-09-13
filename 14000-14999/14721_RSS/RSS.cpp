#include	<iostream>

using namespace	std;

typedef	long long int	int64;

#define	MAX_SIZE	(100+1)
#define	f(a,b,x)	((a)*(x)+(b))

int	main(void)
{
	int		N,a_result,b_result;
	int		x[MAX_SIZE],y[MAX_SIZE];
	int64	rss;
	
	cin>>N;
	
	for(int i=1;i<=N;i++)
	{
		cin>>x[i]>>y[i];
	}
	
	rss = 0x7FFFFFFF;
	
	for(int a=1;a<=100;a++)
	{
		for(int b=1;b<=100;b++)
		{
			int64	tmp;
			
			tmp = 0;
			
			for(int i=1;i<=N;i++)
			{
				tmp += (int64)(y[i]-f(a,b,x[i]))*(int64)(y[i]-f(a,b,x[i]));
			}
			
			if( tmp < rss )
			{
				rss = tmp;
				a_result = a;
				b_result = b;
			}
		}
	}
	
	cout<<a_result<<' '<<b_result<<endl;
	
	return	0;
}

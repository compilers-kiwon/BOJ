#include	<iostream>

using namespace	std;

typedef	unsigned long long	uint64;

int	main(void)
{
	int	T;
	
	cin>>T;
	
	while(T>0)
	{
		uint64	N,p1,p2,p3,p4,p5,p6,day;
		
		cin>>N>>p1>>p2>>p3>>p4>>p5>>p6;
		
		for(day=1;;day++)
		{
			uint64	today_feed,tmp1,tmp2;
			
			today_feed = p1+p2+p3+p4+p5+p6;
			
			if( today_feed > N )
			{
				break;
			}
			
			tmp1 = p1+p3+p5;
			tmp2 = p2+p4+p6;
			
			p1 += tmp2;
			p2 += tmp1;
			p3 += tmp2;
			p4 += tmp1;
			p5 += tmp2;
			p6 += tmp1; 
		}
		cout<<day<<endl;
		
		T--;
	}
	
	return	0;
}

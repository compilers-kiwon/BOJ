#include	<iostream>
#include	<algorithm>

using namespace	std;

#define	TRUE	1
#define	FALSE	0

#define	x	first
#define	y	second

typedef	pair<int,int>	Dot;

int	get_diff(Dot& d1,Dot& d2)
{
	return	(d1.x-d2.x)*(d1.x-d2.x)+(d1.y-d2.y)*(d1.y-d2.y);
}

int	main(void)
{
	int	T;
	
	cin>>T;
	
	while(T>0)
	{
		int	result;
		Dot	d[4];
		
		for(int i=0;i<4;i++)
		{
			cin>>d[i].x>>d[i].y;
		}
		
		sort(&d[0],&d[4]);
		
		int	diff0_1,diff0_2,diff3_1,diff3_2;
		
		diff0_1 = get_diff(d[0],d[1]);
		diff0_2 = get_diff(d[0],d[2]);
		diff3_1 = get_diff(d[3],d[1]);
		diff3_2 = get_diff(d[3],d[2]);
		
		result = FALSE;
		
		if( diff0_1 == diff0_2 && diff0_2 == diff3_1 && diff3_1 == diff3_2 )
		{
			int	diff0_3,diff1_2;
			
			diff0_3 = get_diff(d[0],d[3]);
			diff1_2 = get_diff(d[1],d[2]);
			
			if( diff0_3 == diff1_2 )
			{
				result = TRUE;
			}
		}
		
		cout<<result<<endl;
		
		T--;
	}
	
	return	0;
}

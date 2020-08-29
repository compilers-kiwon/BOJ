#include	<iostream>

using namespace	std;

#define	MAX_SIZE	4

typedef	pair<int,int>	Fraction;

bool	is_bigger(Fraction& f1,Fraction& f2)
{
	int	f1_n,f2_n;
	
	f1_n = f1.first*f2.second;
	f2_n = f2.first*f1.second;
	
	return	(f1_n>f2_n);
}

int		main(void)
{
	int			arr[MAX_SIZE];
	Fraction	f[MAX_SIZE];
	
	for(int i=0;i<MAX_SIZE;i++)
	{
		cin>>arr[i];
	}
	
	// 0 1
	// 2 3
	f[0].first = arr[0]*arr[3]+arr[1]*arr[2];
	f[0].second = arr[2]*arr[3];
	
	// 2 0
	// 3 1
	f[1].first = arr[2]*arr[1]+arr[0]*arr[3];
	f[1].second = arr[3]*arr[1];
	
	// 3 2
	// 1 0
	f[2].first = arr[0]*arr[3]+arr[1]*arr[2];
	f[2].second = arr[1]*arr[0];
	
	// 1 3
	// 0 2
	f[3].first = arr[0]*arr[3]+arr[1]*arr[2];
	f[3].second = arr[2]*arr[0];
	
	int	max_rotate;
	
	max_rotate = 0;
	
	for(int i=1;i<MAX_SIZE;i++)
	{
		if( is_bigger(f[i],f[max_rotate]) == true )
		{
			max_rotate = i;
		}
	}
	
	cout<<max_rotate<<'\n';
	
	return	0;
}

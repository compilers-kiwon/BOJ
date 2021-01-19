#include	<iostream>
#include	<string>

using namespace	std;

int	A,B,C,AB,BC,CA;

int	get_max_value(void)
{
	int	ret;
	
	ret = 0;
	
	for(int cnt_of_AB=0;cnt_of_AB<=A&&cnt_of_AB<=B;cnt_of_AB++)
	{
		int	remain_A,remain_B,remain_C,cnt_of_BC,cnt_of_CA;
		
		remain_A = A-cnt_of_AB;
		remain_B = B-cnt_of_AB;
		remain_C = C;
		
		if( BC > CA )
		{
			cnt_of_BC = min(remain_B,remain_C);
			remain_C -= cnt_of_BC;
			cnt_of_CA = min(remain_C,remain_A);
		}
		else
		{
			cnt_of_CA = min(remain_C,remain_A);
			remain_C -= cnt_of_CA;
			cnt_of_BC = min(remain_B,remain_C);
		}
		
		ret = max(ret,cnt_of_AB*AB+cnt_of_BC*BC+cnt_of_CA*CA);
	}
	
	return	ret;
}

int		main(void)
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	
	int	T;
	
	cin>>T;
	
	for(int t=1;t<=T;t++)
	{
		cin>>A>>B>>C>>AB>>BC>>CA;
		cout<<get_max_value()<<'\n';
	}
	
	return	0;
}

#include	<iostream>

using namespace std;

int main(void)
{
	int	buger1,buger2,buger3;
	int	drink1,drink2;
	int	min_cost;
	
	cin>>buger1>>buger2>>buger3;
	cin>>drink1>>drink2;
	
	min_cost = min(buger1,min(buger2,buger3))+min(drink1,drink2)-50;
	
	cout<<min_cost<<endl;
	
	return	0;
}

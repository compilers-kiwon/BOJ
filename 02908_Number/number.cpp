#include	<iostream>

using namespace std;

int	main(void)
{	
	int	A,B,a,b;
	
	cin>>A>>B;
	
	a = (A/100)+(A%100)/10*10+(A%10*100);
	b = (B/100)+(B%100)/10*10+(B%10*100);
	
	cout<<max(a,b)<<endl;
	
	return	0;
}

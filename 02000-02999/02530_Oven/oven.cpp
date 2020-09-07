#include	<iostream>

using namespace	std;

int	main(void)
{
	int	A,B,C,D;
	int	h,m,s;
	
	cin>>A>>B>>C>>D;
	
	h = D/3600;
	m = (D%3600)/60;
	s = ((D%3600)%60);
	
	C = C+s;
	B = B+(C/60);
	C = C%60;
	
	B = B+m;
	A = A+(B/60);
	B = B%60;
	
	A = (A+h)%24;
	
	cout<<A<<' '<<B<<' '<<C<<endl;
	
	return	0;
}

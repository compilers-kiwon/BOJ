#include	<iostream>

using namespace	std;

int	main(void)
{
	for(int i=1;i<=3;i++)
	{
		int h1,m1,s1,t1;
		int	h2,m2,s2,t2;
		int h3,m3,s3,t3;
		
		cin>>h1>>m1>>s1>>h2>>m2>>s2;
		
		t1 = h1*60*60+m1*60+s1;
		t2 = h2*60*60+m2*60+s2;
		t3 = t2-t1;
		
		h3 = t3/(60*60);
		t3 = t3%(60*60);
		
		m3 = t3/60;
		t3 = t3%60;
		
		s3 = t3;
		
		cout<<h3<<' '<<m3<<' '<<s3<<endl;
	}
	
	return	0;
}

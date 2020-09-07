#include	<iostream>
#include	<string>

using namespace	std;

int	main(void)
{
	int	T;
	
	cin>>T;
	
	while(T>0)
	{
		string	b1,b2;
		int		i,len,cnt;
		
		cin>>b1>>b2;
		
		for(i=0,len=b1.length(),cnt=0;i<len;i++)
		{
			if( b1[i] != b2[i] )
			{
				++cnt;
			}
		}
		cout<<"Hamming distance is "<<cnt<<".\n";
		T--;
	}
	return	0;
}

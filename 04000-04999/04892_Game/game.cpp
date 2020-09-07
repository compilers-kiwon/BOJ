#include <iostream>

using namespace std;

int main(void)
{
	for(int i=1;;i++)
	{
		int  n0,n1,n2,n3,n4;
		bool even;
		
		cin>>n0;
		
		if( n0 == 0 )
		{
			break;
		}
		
		n1 = 3*n0;
		
		if( n1%2 == 0 )
		{
			n2 = n1/2;
			even = true;
		}
		else
		{
			n2 = (n1+1)/2;
			even = false;
		}
		
		n3 = n2*3;
		n4 = n3/9;
		
		if( even == true )
		{
			cout<<i<<". even "<<n4<<endl;
		}
		else
		{
			cout<<i<<". odd "<<n4<<endl;
		}
	}
	return 0;
}

#include <iostream>

using namespace std;

int main(void)
{
	while(1)
	{
		int a,b,c;
		
		cin>>a>>b>>c;
		
		if( a==0 && b==0 && c==0 )
		{
			break;
		}
		
		if( 2*b == c+a )
		{
			cout<<"AP "<<2*c-b<<endl;
		}
		else
		{
			cout<<"GP "<<c*c/b<<endl;
		}
	}
	return 0;
}

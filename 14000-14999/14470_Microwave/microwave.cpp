#include <iostream>

using namespace std;

int main(void)
{
	int A,B,C,D,E,t,f;
	
	cin>>A>>B>>C>>D>>E;
	
	if( A < 0 )
	{
		f = true;
	}
	else
	{
		f = false;
	}
	
	for(t=0;A<B;)
	{
		if( A > 0 )
		{
			t += E;
			A++;
		}
		else
		{
			if( A == 0 )
			{
				if( f == true )
				{
					f = false;
					t += D;
				}
				else
				{
					t += E;
					A++;
				}
			}
			else
			{
				t += C;
				A++;
			}
		}
	}
	
	cout<<t<<endl;
	
	return 0;
}

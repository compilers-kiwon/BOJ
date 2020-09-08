#include <iostream>

using namespace std;

int main(void)
{
	int n,T,cnt;
	
	cin>>n>>T;
	
	for(cnt=0;cnt<n;cnt++)
	{
		int t;
		
		cin>>t;
		
		if( t <= T )
		{
			T -= t;
		}
		else
		{
			break;
		}
	}
	
	cout<<cnt<<endl;
	
	return 0;
}

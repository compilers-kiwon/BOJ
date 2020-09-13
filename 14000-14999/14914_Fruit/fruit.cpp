#include <iostream>

using namespace std;

int main(void)
{
	int a,b,min_fruit;
	
	cin>>a>>b;
	min_fruit = min(a,b);
	
	for(int i=1;i<=min_fruit;i++)
	{
		if(a%i==0 && b%i==0)
		{
			cout<<i<<' '<<a/i<<' '<<b/i<<'\n';
		}
	}
	
	return 0;
}

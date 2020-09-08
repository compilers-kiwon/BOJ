#include <iostream>

using namespace std;

int main(void)
{
	int a,b,c;
	
	cin>>a>>b>>c;
	
	if( a+b+c != 180 )
	{
		cout<<"Error\n";
	}
	else
	{
		if( a!=b && b!=c && c!=a )
		{
			cout<<"Scalene\n";
		}
		else if( a==b && b==c )
		{
			cout<<"Equilateral\n";
		}
		else
		{
			cout<<"Isosceles\n";
		}
	}
	return 0;
}

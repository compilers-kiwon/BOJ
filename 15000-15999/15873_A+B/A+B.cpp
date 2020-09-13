#include <iostream>
#include <string>

using namespace std;

#define char2int(c) ((int)((c)-'0'))

int main(void)
{
	string n;
	int result;
	
	cin>>n;
	
	if( n.length() == 2 )
	{
		result = char2int(n[0])+char2int(n[1]);
	}
	else if( n.length() == 3 )
	{
		if( n[1] == '0' )
		{
			result = 10+char2int(n[2]);
		}
		else
		{
			result = char2int(n[0])+10;
		}
	}
	else
	{
		result = 20;
	}
	
	cout<<result<<endl;
	
	return 0;
}

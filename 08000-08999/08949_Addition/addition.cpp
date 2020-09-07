#include <iostream>
#include <string>

using namespace std;

#define char2int(c) ((int)((c)-'0'))

int main(void)
{
	string n1,n2,zero;
	
	cin>>n1>>n2;
	
	if( n1.length() > n2.length() )
	{
		zero.resize(n1.length()-n2.length(),'0');
		n2.insert(0,zero);
	}
	else if( n1.length() < n2.length() )
	{
		zero.resize(n2.length()-n1.length(),'0');
		n1.insert(0,zero);
	}
	
	for(int i=0;i<n1.length();i++)
	{
		cout<<char2int(n1[i])+char2int(n2[i]);
	}
	cout<<endl;
	
	return 0;
}

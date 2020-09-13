#include <iostream>
#include <string>

using namespace std;

int main(void)
{
	string str;
	int T,A,B;
	
	cin>>str>>T;
	
	for(int i=1;i<=T;i++)
	{
		cin>>A>>B;
		swap(str[A],str[B]);
	}
	
	cout<<str<<endl;
	
	return 0;
}

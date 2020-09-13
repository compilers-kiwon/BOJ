#include <iostream>
#include <string>

using namespace std;

#define char2int(c) ((int)((c)-'0'))

char Luhn(string& number)
{
	int n,i;
	
	for(n=i=0;i<number.length();i++)
	{
		int tmp = char2int(number[i]);
		
		if( i%2 == 0 )
		{
			tmp *= 2;
			
			if( tmp >= 10 )
			{
				tmp = tmp%10+1;
			}
		}
		n += tmp;
	}
	
	return ((n%10==0)?'T':'F');
}

int main(void)
{
	int T;
	
	cin>>T;
	
	while(T>0)
	{
		string number;
		
		cin>>number;
		cout<<Luhn(number)<<endl;
		
		T--;
	}
	
	return 0;
}

#include <iostream>
#include <string>

using namespace std;

#define int2char(i) ((char)((i)+(int)'0'))
#define char2int(c) ((int)((c)-'0'))

void rounds(string& number,int index,int carry)
{
	int n;
	char& c = number[index];
	
	n = char2int(c);
	c = '0';
	n += carry;
	
	if( index == 0 )
	{
		carry = n/10;
		n = n%10;
		
		if( carry == 1 )
		{
			number.insert(number.begin(),'1');
		}
		else
		{
			c = int2char(n);
		}
	}
	else
	{
		if( n >= 5 )
	    {
		    carry = 1;
	    }
	    else
	    {
		    carry = 0;
	    }		
	    rounds(number,index-1,carry);
	}
}

int main(void)
{
	int n;
	
	cin>>n;
	
	while(n>0)
	{
		string number;
		
		cin>>number;
		rounds(number,number.length(),0);
		cout<<number<<endl;
		
		n--;
	}
	
	return 0;
}

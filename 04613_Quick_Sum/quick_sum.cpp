#include <iostream>
#include <string>

using namespace std;

#define CHAR2INT(C) ((int)((C)-'A')+1)

int quick_sum(string& s)
{
	int i,len,sum;
	
	for(i=1,sum=0,len=s.length();i<len;i++)
	{
		char c;
		
		if((c=s[i])!=' ')
		{
			sum += CHAR2INT(c)*i;
		}
	}
	
	return sum;
}

int main(void)
{
	while(1)
	{
	    string str;
	
	    getline(cin,str);
		
		if( str == "#" )
		{
			break;
		}
		
		str.insert(str.begin(),' ');
		cout<<quick_sum(str)<<endl;
	}
	return 0;
}

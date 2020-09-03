#include <iostream>
#include <string>

using namespace std;

#define LEN_OF_RING 10

#define TRUE 1
#define FALSE 0

int find_str(string& str,string& ring)
{
	int result;
	
	result = FALSE;
	
	for(int i=0;(result==FALSE)&&(i<LEN_OF_RING);i++)
	{
		if( str[0] == ring[i] )
		{
			result = TRUE;
			
			for(int j=1;j<str.length();j++)
			{
				if( str[j] != ring[(i+j)%LEN_OF_RING] )
				{
					result = FALSE;
					break;
				}
			}
		}
	}
	
	return result;
}

int main(void)
{
	string str;
	int N,cnt,i;
	
	cin>>str>>N;
	
	for(i=1,cnt=0;i<=N;i++)
	{
		string ring;
		
		cin>>ring;
		cnt += find_str(str,ring);
	}
	cout<<cnt<<endl;
	
	return 0;
}

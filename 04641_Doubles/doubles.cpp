#include <iostream>
#include <vector>

using namespace std;

#define MAX_NUM 100

int main(void)
{
	while(1)
	{
		int n;
		
		cin>>n;
		
		if( n == -1 )
		{
			break;
		}
		
		vector<bool> table(MAX_NUM+1,false);
		
		while( n != 0 )
		{
			table[n] = true;
			cin>>n;
		}
		
		int cnt,i;
		
		for(i=1,cnt=0;i<MAX_NUM/2;i++)
		{
			if( table[i] == true && table[2*i] == true )
			{
				++cnt;
			}
		}
		
		cout<<cnt<<endl;
	}
	
	return 0;
}

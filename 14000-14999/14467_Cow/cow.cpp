#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
	int N,cnt,i;
	
	cin>>N;
	
	vector<int> cow(N+1,-1);
	
	for(i=1,cnt=0;i<=N;i++)
	{
		int c,l;
		
		cin>>c>>l;
		
		if( cow[c] == -1 )
		{
			cow[c] = l;
		}
		else
		{
			if( cow[c] != l )
			{
				cow[c] = l;
				cnt++;
			}
		}
	}
	cout<<cnt<<endl;
	
	return 0;
}

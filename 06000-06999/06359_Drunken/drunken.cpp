#include	<iostream>
#include	<vector>

using namespace	std;

#define	LOCK	0
#define	UNLOCK	1

int main(void)
{
	int	T;
	
	cin>>T;
	
	while(T>0)
	{
		int	n;
		
		cin>>n;
		
		vector<int>	room(n+1,LOCK);
		
		for(int i=1;i<=n;i++)
		{
			for(int j=i;j<=n;j=j+i)
			{
				room[j] ^= UNLOCK;
			}
		}
		
		int	cnt = 0;
		
		for(int i=1;i<=n;i++)
		{
			if( room[i] == UNLOCK )
			{
				++cnt;
			}
		}
		cout<<cnt<<endl;
		
		T--;
	}
	return	0;
}

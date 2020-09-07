#include	<iostream>
#include	<vector>

using namespace	std;

#define	MAX_NUM	9999

int	main(void)
{
	int				N,cnt;
	vector<bool>	visited(MAX_NUM+1,false);
		
	cin>>N;
	
	for(cnt=0;visited[N]==false;cnt++)
	{
		int	mid;
		
		visited[N] = true;
		
		mid = ((N%1000)/100)*10+((N%100)/10);
		N = mid*mid;
	}
	
	cout<<cnt<<'\n';
	
	return	0;
}

#include	<iostream>
#include	<vector>

using namespace	std;

#define	MAX_SIZE	(100000+1)

typedef	pair<int,int>	XY;
typedef	long long int	int64;

int		N;
XY		dot[MAX_SIZE];
int64	X_cnt[MAX_SIZE],Y_cnt[MAX_SIZE];

int	main(void)
{
	scanf("%d\n",&N);
	
	for(int i=1;i<=N;i++)
	{
		int	x,y;
		
		scanf("%d %d",&x,&y);
		
		X_cnt[x]++;Y_cnt[y]++;
		dot[i] = make_pair(x,y);
	}
	
	int64	cnt;
	
	cnt = 0;
	
	for(int i=1;i<=N;i++)
	{
		int& x = dot[i].first;
		int& y = dot[i].second;
		
		cnt += (X_cnt[x]-1)*(Y_cnt[y]-1);
	}
	
	cout<<cnt<<'\n';
	
	return	0;	
}

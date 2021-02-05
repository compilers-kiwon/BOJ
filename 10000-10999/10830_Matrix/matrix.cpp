#include	<iostream>
#include	<map>

using namespace	std;

#define	MAX_SIZE	(5+1)
#define	MOD(n)		((n)%1000)

typedef	long long int	int64;

typedef	struct	_ARRAY_INFO	Array;
struct	_ARRAY_INFO
{
	int	arr[MAX_SIZE][MAX_SIZE];
};

int					N;
int64				B;
map<int64,bool>		dp;
map<int64,Array>	A;

void	input(void)
{
	cin>>N>>B;
	dp[1] = true;
	
	for(int row=1;row<=N;row++)
	{
		for(int col=1;col<=N;col++)
		{
			cin>>A[1].arr[row][col];
		}
	}
}

void	mul(int64 m1,int64 m2,int64 result)
{
	Array&	a1 = A[m1];
	Array&	a2 = A[m2];
	Array&	r = A[result];
	
	for(int row=1;row<=N;row++)
	{
		for(int col=1;col<=N;col++)
		{
			r.arr[row][col] = 0;
			
			for(int i=1;i<=N;i++)
			{
				r.arr[row][col] = MOD(r.arr[row][col]+
										a1.arr[row][i]*a2.arr[i][col]);
			}
		}
	}
}

void	get_arr(int64 n)
{
	if( dp[n] == true )
	{
		return;
	}
	
	if( n%2 == 0 )
	{
		get_arr(n>>1);
		mul(n>>1,n>>1,n);
	}
	else
	{
		get_arr(1);
		get_arr(n-1);
		mul(1,n-1,n);
	}
	
	dp[n] = true;
}

int		main(void)
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	
	input();
	get_arr(B);
	
	for(int row=1;row<=N;row++)
	{
		for(int col=1;col<=N;col++)
		{
			cout<<MOD(A[B].arr[row][col])<<' ';
		}
		cout<<'\n';
	}
	
	return	0;
}

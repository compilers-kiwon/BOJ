#include	<iostream>

using namespace	std;

#define	MAX_LEN			(1000+1)
#define	NUM_OF_NUMBERS	10

#define	MOD(n)	((n)%1234567)

int	dp[MAX_LEN][NUM_OF_NUMBERS];

const bool	adj_table[NUM_OF_NUMBERS][NUM_OF_NUMBERS] = {
	//	 0,	   1,    2,    3,    4,    5,    6,    7,    8,    9  
	{false,false,false,false,false,false,false,true ,false,false},	// 0
	{false,false,true ,false,true ,false,false,false,false,false},	// 1
	{false,true ,false,true ,false,true ,false,false,false,false},	// 2
	{false,false,true ,false,false,false,true ,false,false,false},	// 3
	{false,true ,false,false,false,true ,false,true ,false,false},	// 4
	{false,false,true ,false,true ,false,true ,false,true ,false},	// 5
	{false,false,false,true ,false,true ,false,false,false,true },	// 6
	{true ,false,false,false,true ,false,false,false,true ,false},	// 7
	{false,false,false,false,false,true ,false,true ,false,true },	// 8
	{false,false,false,false,false,false,true ,false,true ,false},	// 9
};

int	get_dp(int n,int len)
{
	if( dp[len][n] != -1 )
	{
		return	dp[len][n];
	}
	
	dp[len][n] = 0;
	
	for(int i=0;i<NUM_OF_NUMBERS;i++)
	{
		if( adj_table[n][i] == true )
		{
			dp[len][n] += get_dp(i,len-1);
			dp[len][n] = MOD(dp[len][n]);
		}
	}
	
	return	dp[len][n];
}

int	main(void)
{	
	dp[1][0] = dp[1][1] = dp[1][2] = dp[1][3] = dp[1][4] =
	dp[1][5] = dp[1][6] = dp[1][7] = dp[1][8] = dp[1][9] = 1;
		
	for(int i=2;i<=MAX_LEN;i++)
	{
		dp[i][0] = dp[i][1] = dp[i][2] = dp[i][3] = dp[i][4] =
		dp[i][5] = dp[i][6] = dp[i][7] = dp[i][8] = dp[i][9] = -1;
	}
	
	int	T;
	
	cin>>T;
	
	while(T>0)
	{
		int	N,sum;
		
		cin>>N;
		sum = 0;
		
		for(int i=0;i<NUM_OF_NUMBERS;i++)
		{
			sum += get_dp(i,N);
			sum = MOD(sum);
		}
		cout<<sum<<endl;
		
		T--;
	}
}

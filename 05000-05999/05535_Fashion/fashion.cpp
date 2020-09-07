#include	<iostream>
#include	<vector>
#include	<cmath>

using namespace std;

#define	MAX_SIZE	(200+1)

int 		D,N,dp[MAX_SIZE][MAX_SIZE];
vector<int>	wearable[MAX_SIZE];

int	get_dp(int today,int today_wearable)
{
    if( today == D ) 
	{
		return	0;
	}
     
    int&	ret = dp[today][today_wearable];
    
    if( ret != -1)
	{
		return	ret;
	}
     
    ret = 0;
     
	for(int i=0;i<wearable[today+1].size();i++)
	{
    	int	diff;
		
		diff = abs(today_wearable-wearable[today+1][i]);
    	ret = max(ret, diff+get_dp(today+1,wearable[today+1][i]));
    }
    
    return	ret;
}

int	main()
{
    for(int i=1;i<MAX_SIZE;i++)
    {
     	for(int j=0;j<MAX_SIZE;j++)
     	{
     		dp[i][j] = -1;
		}
	}
     
    scanf("%d %d",&D,&N);
    
	int T[D+1];
     
	for(int i=1;i<=D;i++)
	{
		scanf("%d", &T[i]);
	} 
    
	for(int i=1;i<=N;i++)
	{
    	int	A,B,C;
    	
		scanf("%d %d %d",&A,&B,&C);
    
		for(int j=1;j<=D;j++)
		{
    		if( A<=T[j] && T[j]<=B )
			{
        		wearable[j].push_back(C);
       		}
		}
	}
     
    int	answer;
	
	answer = 0;
     
	for(int i=0;i<wearable[1].size();i++)
	{
    	answer = max(answer,get_dp(1,wearable[1][i]));
    }
    
	printf("%d\n",answer);
    
	return 0;
}

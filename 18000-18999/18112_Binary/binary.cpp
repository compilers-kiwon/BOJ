#include	<iostream>
#include	<queue>

using namespace	std;

#define	MAX_SIZE	10
#define	MAX_BIN		(1<<MAX_SIZE)
#define	BASE_NUM	2
#define	NONE		0

string	L,K;
int		dp[MAX_BIN];

int		str2int(const string& n)
{
	int	ret,i;
	
	for(ret=i=0;i<n.length();i++)
	{
		ret = ret*BASE_NUM+(int)(n[i]-'0');
	}
	
	return	ret;
}

int		simulate(int src,int dst)
{
	queue<int>	num_q;
	int			ret;
	
	dp[src] = 1;
	num_q.push(src);
	
	for(ret=0;!num_q.empty();)
	{
		int	current_num = num_q.front();
		int	current_num_of_operations = dp[current_num];
		
		num_q.pop();
		
		if( current_num == dst )
		{
			ret = current_num_of_operations-1;
			break;
		}
		
		for(int i=1;(1<<i)<=current_num;i++)
		{
			int	c;
			
			c = current_num^(1<<(i-1));
			
			if( dp[c] == NONE )
			{
				dp[c] = current_num_of_operations+1;
				num_q.push(c);
			}
		}
		
		if( current_num+1<MAX_BIN && dp[current_num+1]==NONE )
		{
			dp[current_num+1] = current_num_of_operations+1;
			num_q.push(current_num+1);
		}
		
		if( current_num!=0 && dp[current_num-1]==NONE )
		{
			dp[current_num-1] = current_num_of_operations+1;
			num_q.push(current_num-1);
		}
	}
	
	return	ret;
}


int		main(void)
{
	cin>>L>>K;
	cout<<simulate(str2int(L),str2int(K))<<'\n';
	
	return	0;
}

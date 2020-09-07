#include	<iostream>
#include	<string>

using namespace	std;

#define	MAX_LEN			100
#define	MAX_MAGIC_LEN	20

#define	DEVIL			0
#define	ANGEL			1
#define	NUM_OF_BRIDGE	2

#define	NEXT_BRIDGE(bi)	(((bi)+1)%NUM_OF_BRIDGE)

typedef	long long int	int64;

string	stone[NUM_OF_BRIDGE];
string	magic_str;
int64	dp[NUM_OF_BRIDGE][MAX_LEN][MAX_MAGIC_LEN];

int64	get_dp_value(int bridge_index,int stone_index,int prev_magic_char_index)
{
	if( prev_magic_char_index == 0 )
	{
		return	1;
	}
	
	int64&	ret = dp[bridge_index][stone_index][prev_magic_char_index];
	
	if( ret != -1 )
	{
		return	ret;
	}
	
	ret = 0;
	
	char	expected_char = magic_str[prev_magic_char_index-1];
	int		next_bridge = NEXT_BRIDGE(bridge_index);
	
	for(int i=stone_index-1;i>=0;i--)
	{
		if( stone[next_bridge][i] == expected_char )
		{
			ret += get_dp_value(next_bridge,i,prev_magic_char_index-1);
		}
	}
	
	return	ret;
}

int		main(void)
{
	cin>>magic_str>>stone[DEVIL]>>stone[ANGEL];
	
	int	stone_len,magic_len;

	stone_len = stone[DEVIL].length();
	magic_len = magic_str.length();
	
	for(int i=DEVIL;i<=ANGEL;i++)
	{
		for(int j=0;j<stone_len;j++)
		{
			for(int k=0;k<magic_len;k++)
			{
				dp[i][j][k] = -1;
			}
		}
	}
	
	int64	answer = 0;
	
	for(int i=DEVIL;i<=ANGEL;i++)
	{
		for(int j=stone_len-1;j>=0;j--)
		{
			if( stone[i][j] == magic_str[magic_len-1] )
			{
				answer += get_dp_value(i,j,magic_len-1);
			}
		}
	}
	cout<<answer<<endl;
	
	return	0;
}

#include	<iostream>
#include	<vector>
#include	<algorithm>
#include	<string>

using namespace	std;

#define	MAX_NUM_OF_BOXES	(500+1)

typedef	pair< int,pair<int,int> >	Box;

Box	box[MAX_NUM_OF_BOXES];

bool	input(int& num_of_boxes)
{
	cin>>num_of_boxes;getchar();
	
	if( num_of_boxes == -1 )
	{
		return	false;
	}
	
	if( num_of_boxes == 0 )
	{
		return	true;
	}
	
	for(int i=1;i<=num_of_boxes;i++)
	{
		string	str;
		int		e[3];
		
		getline(cin,str);
		
		for(int j=0;j<str.length();j++)
		{
			if( str[j] == 'x' )
			{
				str[j] = ' ';
			}
		}
		
		sscanf(str.c_str(),"%d %d %d",&e[0],&e[1],&e[2]);
		
		sort(&e[0],&e[3]);
		box[i] = make_pair(e[0],make_pair(e[1],e[2]));
	}
	
	sort(&box[1],&box[num_of_boxes+1]);
	
	return	true;
}

int		main(void)
{
	for(;;)
	{
		int	n,dp[MAX_NUM_OF_BOXES],answer;
		
		if( input(n) == false )
		{
			break;
		}
		
		if( n == 0 )
		{
			cout<<"0\n";
			continue;
		}
		
		dp[1] = 1;
		answer = 0;
		
		for(int b=2;b<=n;b++)
		{
			int	prev_max_len;
			
			prev_max_len = 0;
			
			for(int i=1;i<b;i++)
			{
				if( box[i].first<box[b].first && 
					box[i].second.first<box[b].second.first && 
					box[i].second.second<box[b].second.second )
				{
					prev_max_len = max(prev_max_len,dp[i]);
				}
			}
			
			dp[b] = prev_max_len+1;
			answer = max(answer,dp[b]);
		}
		
		cout<<answer<<'\n';
	}
	
	return	0;
}

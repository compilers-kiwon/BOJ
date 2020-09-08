#include	<iostream>
#include	<vector>
#include	<algorithm>

using namespace	std;

#define	HEIGHT	4
#define	WIDTH	3

#define	MAX_LEN	3
#define	MAX_NUM	200

const int	keyboard[HEIGHT][WIDTH] = {{1,2,3},{4,5,6},{7,8,9},{-1,0,-1}};

void	dfs(int current_row,int current_col,int current_value,
			int current_len,vector<int>& numbers)
{
	if( current_value > MAX_NUM )
	{
		return;
	}
	
	numbers.push_back(current_value);
	
	if( current_len == MAX_LEN )
	{
		return;	
	}
	
	for(int adj_row=current_row;adj_row<HEIGHT;adj_row++)
	{
		for(int adj_col=current_col;adj_col<WIDTH;adj_col++)
		{
			if( keyboard[adj_row][adj_col] >= 0 )
			{
				dfs(adj_row,adj_col,current_value*10+keyboard[adj_row][adj_col],current_len+1,numbers);
			}
		}	
	}
}

void	get_all_numbers(vector<int>& numbers)
{
	for(int row=0;row<HEIGHT;row++)
	{
		for(int col=0;col<WIDTH;col++)
		{
			if( keyboard[row][col] >= 0 )
			{
				dfs(row,col,keyboard[row][col],1,numbers);
			}
		}
	}
	
	sort(numbers.begin(),numbers.end());
}

int		main(void)
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	
	int			T,k;
	vector<int>	n;
	
	get_all_numbers(n);
	
	cin>>T;
	
	for(int i=1;i<=T;i++)
	{
		vector<int>::iterator	lb;
		
		cin>>k;
		lb = lower_bound(n.begin(),n.end(),k);
		
		if( *lb == k )
		{
			cout<<k<<'\n';
		}
		else
		{
			int	left,mid,right;
			
			left = *(lb-1);
			mid = k;
			right = *lb;
			
			if( mid-left < right-mid )
			{
				cout<<left<<'\n';
			}
			else
			{
				cout<<right<<'\n';
			}
		}
	}
	
	return	0;
}

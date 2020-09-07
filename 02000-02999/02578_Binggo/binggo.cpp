#include <iostream>

using namespace std;

#define  MAX_SIZE 5

int cnt;
int board[MAX_SIZE+1][MAX_SIZE+1];

bool row[MAX_SIZE+1],col[MAX_SIZE+1];
bool digonal_left_to_right,digonal_right_to_left;

pair<int,int> row_col[MAX_SIZE*MAX_SIZE+1];

void count_bingo(void)
{
	for(int i=1;i<=MAX_SIZE;i++)
	{
		if( row[i] == false )
		{
			if( board[i][1]+board[i][2]+board[i][3]+board[i][4]+board[i][5] == 0 )
			{
				row[i] = true;
				cnt++;
			}
		}
	}
	
	for(int i=1;i<=MAX_SIZE;i++)
	{
		if( col[i] == false )
		{
			if( board[1][i]+board[2][i]+board[3][i]+board[4][i]+board[5][i] == 0 )
			{
				col[i] = true;
				cnt++;
			}
		}
	}
	
	if( digonal_left_to_right == false )
	{
		if( board[1][1]+board[2][2]+board[3][3]+board[4][4]+board[5][5] == 0 )
		{
			digonal_left_to_right = true;
			cnt++;
		}
	}
	
	if( digonal_right_to_left == false )
	{
		if( board[5][1]+board[4][2]+board[3][3]+board[2][4]+board[1][5] == 0 )
		{
			digonal_right_to_left = true;
			cnt++;
		}
	}
}

int main(void)
{
	for(int i=1;i<=MAX_SIZE;i++)
	{
		for(int j=1;j<=MAX_SIZE;j++)
		{
			int n;
			
			cin>>n;
			row_col[n] = make_pair(i,j);
			board[i][j] = n;
		}
	}
	
	for(int i=1;i<=MAX_SIZE*MAX_SIZE;i++)
	{
		int n,r,c;
		
		cin>>n;
		r = row_col[n].first;
		c = row_col[n].second;
		
		board[r][c] = 0;
		count_bingo();
		
		if( cnt >= 3 )
		{
			cout<<i<<endl;
			break;
		}
	}
	
	return 0;
}

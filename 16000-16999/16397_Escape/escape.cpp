#include	<iostream>
#include	<queue>
#include	<vector>

using namespace	std;

#define	MAX_NUM	99999

typedef	pair<int,int>	State;	// first:LED number, second:remaining_num_of_button

int	get_msb_digit(int n)
{
	int	msb,div;
	
	for(msb=MAX_NUM+1;(div=n/msb)==0;msb/=10);
	
	return	msb;
}

int	get_min_num_of_button(int init_number,int max_num_of_allowed_button,int	unlock_number)
{
	queue<State>	state_q;
	vector<int>		dp(MAX_NUM+1,0x7FFFFFFF);
	
	state_q.push(make_pair(init_number,0));
	dp[init_number] = 0;
	
	while( !state_q.empty() )
	{
		int	current_number,current_num_of_button;
		
		current_number = state_q.front().first;
		current_num_of_button = state_q.front().second;
		
		state_q.pop();
		
		if( current_number == unlock_number )
		{
			break;
		}
		
		if( current_num_of_button == max_num_of_allowed_button )
		{
			continue;
		}
		
		int	next_number,next_num_of_button;
		
		next_num_of_button = current_num_of_button+1;
		
		// A
		next_number = current_number+1;
		
		if( next_number<=MAX_NUM && next_num_of_button<dp[next_number] )
		{
			dp[next_number] = next_num_of_button;
			state_q.push(make_pair(next_number,next_num_of_button));
		}
		
		// B
		if( current_number!=0 && (next_number=current_number*2)<=MAX_NUM )
		{
			int	msb_digit;
			
			msb_digit = get_msb_digit(next_number);
			next_number -= msb_digit;
			
			if( next_num_of_button<dp[next_number] )
			{
				dp[next_number] = next_num_of_button;
				state_q.push(make_pair(next_number,next_num_of_button));
			}
		}
	}
	
	return	dp[unlock_number];	
}

int	main(void)
{
	int	N,T,G,solution;
	
	cin>>N>>T>>G;
	solution = get_min_num_of_button(N,T,G);
	
	if( solution != 0x7FFFFFFF )
	{
		cout<<solution<<'\n';
	}
	else
	{
		puts("ANG");
	}
	
	return	0;
}

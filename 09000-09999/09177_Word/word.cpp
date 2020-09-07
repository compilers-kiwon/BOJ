#include	<iostream>
#include	<string>
#include	<queue>

using namespace	std;

#define	MAX_LEN	200

typedef	struct	_STATE_INFO	State;
struct	_STATE_INFO
{
	int	w1_index,w2_index,w3_index;
};

bool	build_word(string& w1,string& w2,string& w3,bool visited[][MAX_LEN+1])
{
	queue<State>	state_q;
	State			s;
	
	for(int row=0;row<=MAX_LEN;row++)
	{
		for(int col=0;col<=MAX_LEN;col++)
		{
			visited[row][col] = false;
		}
	}
	
	if( w1[0] == w3[0] )
	{
		s.w1_index = 1;
		s.w2_index = 0;
		s.w3_index = 1;
		
		visited[1][0] = true;
		state_q.push(s);
	}
	
	if( w2[0] == w3[0] )
	{
		s.w1_index = 0;
		s.w2_index = 1;
		s.w3_index = 1;
		
		visited[0][1] = true;
		state_q.push(s);
	}
	
	for(;!state_q.empty();)
	{
		int	w1_index,w2_index,w3_index;
		
		w1_index = state_q.front().w1_index;
		w2_index = state_q.front().w2_index;
		w3_index = state_q.front().w3_index;

		state_q.pop();
		
		if( w3_index == w3.length() )
		{
			return	true;
		}
		
		if( w1_index<w1.length() && w1[w1_index]==w3[w3_index] )
		{
			if( visited[w1_index+1][w2_index] == false )
			{
				s.w1_index = w1_index+1;
				s.w2_index = w2_index;
				s.w3_index = w3_index+1;
				
				visited[s.w1_index][s.w2_index] = true;
				state_q.push(s);
			}
		}
		
		if( w2_index<w2.length() && w2[w2_index]==w3[w3_index] )
		{
			if( visited[w1_index][w2_index+1] == false )
			{
				s.w1_index = w1_index;
				s.w2_index = w2_index+1;
				s.w3_index = w3_index+1;
				
				visited[s.w1_index][s.w2_index] = true;
				state_q.push(s);
			}
		}
	}
	
	return	false;
}

int		main(void)
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	
	int	n;
	
	cin>>n;
	
	for(int i=1;i<=n;i++)
	{
		string	w1,w2,w3;
		bool	visited[MAX_LEN+1][MAX_LEN+1];
		
		cin>>w1>>w2>>w3;
		
		if( build_word(w1,w2,w3,visited) == true )
		{
			cout<<"Data set "<<i<<": yes\n";
		}
		else
		{
			cout<<"Data set "<<i<<": no\n";
		}
	}
	
	return	0;
}

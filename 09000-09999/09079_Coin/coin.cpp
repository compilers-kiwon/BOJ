#include	<iostream>
#include	<string>
#include	<map>
#include	<queue>

using namespace	std;

#define	H_STATE			0
#define	T_STATE			1
#define	NUM_OF_STATE	2

#define	NEXT_STATE(s)	(((s)=='H')?'T':'H')

#define	H_FINISH		"HHHHHHHHH"
#define	T_FINISH		"TTTTTTTTT"

#define	MAX_SIZE		3

#define	GET_ROW(index)	((index)/MAX_SIZE)
#define	GET_COL(index)	((index)%MAX_SIZE)

void	do_row_operation(string& str,int index)
{
	int	current_row_index;
	
	current_row_index = GET_ROW(index)*MAX_SIZE;
	
	str[current_row_index+0] = NEXT_STATE(str[current_row_index+0]);
	str[current_row_index+1] = NEXT_STATE(str[current_row_index+1]);
	str[current_row_index+2] = NEXT_STATE(str[current_row_index+2]);
}

void	do_col_operation(string& str,int index)
{
	int	current_col_index;
	
	current_col_index = GET_COL(index);
	
	str[current_col_index+0] = NEXT_STATE(str[current_col_index+0]);
	str[current_col_index+3] = NEXT_STATE(str[current_col_index+3]);
	str[current_col_index+6] = NEXT_STATE(str[current_col_index+6]);
}

void	do_diagonal_1_operation(string& str)
{
	str[0] = NEXT_STATE(str[0]);
	str[4] = NEXT_STATE(str[4]);
	str[8] = NEXT_STATE(str[8]);
}

void	do_diagonal_2_operation(string& str)
{
	str[2] = NEXT_STATE(str[2]);
	str[4] = NEXT_STATE(str[4]);
	str[6] = NEXT_STATE(str[6]);
}

int		main(void)
{
	int	T;
	
	cin>>T;
	
	while(T>0)
	{
		string				first_state;
		int					found;
		map<string,bool>	visited;
		queue<string>		state_q;
		
		for(int i=1;i<=MAX_SIZE*MAX_SIZE;i++)
		{
			char	c;
			
			cin>>c;
			first_state.push_back(c);
		}
		
		state_q.push(first_state);
		found = -1;
		visited[first_state] = true;
		
		for(int i=0;state_q.size()!=0&&found==-1;i++)
		{
			for(int j=1,size=state_q.size();j<=size;j++)
			{
				string	current_state,tmp;
				
				current_state = state_q.front();
				state_q.pop();
				
				if( current_state == H_FINISH || current_state == T_FINISH )
				{
					found = i;
					break;
				}
				
				for(int i=0;i<MAX_SIZE*MAX_SIZE;i+=3)
				{
					tmp = current_state;
					
					do_row_operation(tmp,i);
					
					if( visited[tmp] == false )
					{
						visited[tmp] = true;
						state_q.push(tmp);
					}
				}
				
				for(int i=0;i<MAX_SIZE;i++)
				{
					tmp = current_state;
					
					do_col_operation(tmp,i);
					
					if( visited[tmp] == false )
					{
						visited[tmp] = true;
						state_q.push(tmp);
					}
				}
				
				tmp = current_state;
				do_diagonal_1_operation(tmp);
				
				if( visited[tmp] == false )
				{
					visited[tmp] = true;
					state_q.push(tmp);
				}
				
				tmp = current_state;
				do_diagonal_2_operation(tmp);
				
				if( visited[tmp] == false )
				{
					visited[tmp] = true;
					state_q.push(tmp);
				}
			}
		}
		cout<<found<<'\n';
		
		T--;
	}
}

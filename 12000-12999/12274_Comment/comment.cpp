#include	<iostream>
#include	<string>
#include	<stack>

using namespace	std;

#define	NONE	'\0'

int	main(void)
{
	string		body;
	stack<int>	st;
	char		prev;
	
	for(prev=NONE;;)
	{
		char	c;
		
		if( prev != NONE )
		{
			if( prev == EOF )
			{
				break;
			}
			
			body.push_back(prev);
			prev = NONE;
		}
		
		c = fgetc(stdin);
				
		if( c == EOF )
		{
			break;
		}
		
		body.push_back(c);
		
		if( body.length() > 1 )
		{
			char	c1 = body[body.length()-2];
			char	c2 = body[body.length()-1];
			
			if( c1=='*' && c2=='/' )
			{
				if( !st.empty() )
				{
					int	comment_start_idx;
					
					comment_start_idx = st.top();
					st.pop();
					
					body.erase(comment_start_idx,body.size()-comment_start_idx);
					prev = fgetc(stdin);
				}
			}
			
			if( c1=='/' && c2=='*' )
			{
				st.push(body.length()-2);
				prev = fgetc(stdin);
			}
		}
	}
	
	cout<<"Case #1:\n"<<body<<'\n';
	
	return	0;
}

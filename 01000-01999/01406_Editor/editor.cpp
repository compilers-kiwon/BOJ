#include	<iostream>
#include	<string>

using namespace	std;

#define	MAX_SIZE	(1000000+1)

typedef	struct	_NODE_INFO	Node;
struct	_NODE_INFO
{
	char	c;
	int		prev,next;
};

Node	str[MAX_SIZE];

void	print(int s)
{
	for(int i=s;i!=-1;i=str[i].next)
	{
		putchar(str[i].c);
	}
}

void	input(int& start_pos,int& end_pos)
{
	string	s;
	
	cin>>s;
	
	for(int i=0;i<s.length();i++)
	{
		str[i].c = s[i];
		str[i].prev = i-1;
		str[i].next = i+1;
	}
	
	str[s.length()].c = '\n';
	str[s.length()].prev = s.length()-1;
	str[s.length()].next = -1;
	
	start_pos = 0;
	end_pos = s.length();
}

int		main(void)
{
	int	N,start_pos,end_pos,current_pos;
	
	input(start_pos,end_pos);
	current_pos = end_pos;
	
	scanf("%d",&N);getchar();
	
	for(int i=1;i<=N;i++)
	{
		char	ins,p;
		
		scanf("%c",&ins);getchar();
		
		switch(ins)
		{
			case	'L':
				if( str[current_pos].prev != -1 )
				{
					current_pos = str[current_pos].prev;
				}
				break;
			case	'D':
				if( str[current_pos].next != -1 )
				{
					current_pos = str[current_pos].next;
				}
				break;
			case	'B':
				if( str[current_pos].prev != -1 )
				{
					int	pos_to_be_removed;
					
					pos_to_be_removed = str[current_pos].prev;
					str[current_pos].prev = str[pos_to_be_removed].prev;
					
					if( str[pos_to_be_removed].prev != -1 )
					{
						str[str[pos_to_be_removed].prev].next = current_pos;
					}
					else
					{
						start_pos = current_pos;
					}
				}
				break;
			case	'P':
				scanf("%c",&p);getchar();
				++end_pos;
								
				str[end_pos].c = p;
				
				str[end_pos].prev = str[current_pos].prev;
				str[end_pos].next = current_pos;
				
				str[current_pos].prev = end_pos;
				
				if( str[end_pos].prev != -1 )
				{
					str[str[end_pos].prev].next = end_pos;
				}
				else
				{
					start_pos = end_pos;
				}
				
				break;
				
			default:
				// do nothing
				break;
		}
	}
	
	print(start_pos);
	
	return	0;
}

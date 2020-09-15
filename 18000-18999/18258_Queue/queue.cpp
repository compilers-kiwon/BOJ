#include	<iostream>
#include	<string>

using namespace	std;

#define	MAX_SIZE	2000000

int	N,queue[MAX_SIZE],front_ptr,back_ptr;

void	push(int X)
{
	queue[back_ptr++] = X;
}

int		pop(void)
{
	int	ret;
	
	if( front_ptr == back_ptr )
	{
		ret = -1;
	}
	else
	{
		ret = queue[front_ptr++];
	}
	
	return	ret;
}

int		size(void)
{
	return	back_ptr-front_ptr;
}

int		empty(void)
{
	return	(size()==0)?1:0;
}

int		front(void)
{
	int	ret;
	
	if( empty() == 1 )
	{
		ret = -1;
	}
	else
	{
		ret = queue[front_ptr];
	}
	
	return	ret;
}

int		back(void)
{
	int	ret;
	
	if( empty() == 1 )
	{
		ret = -1;
	}
	else
	{
		ret = queue[back_ptr-1];
	}
	
	return	ret;
}

int		main(void)
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	
	cin>>N;
	
	for(int i=1;i<=N;i++)
	{
		string	op;
		
		cin>>op;
		
		if( op == "push" )
		{
			int	X;
			
			cin>>X;
			push(X);
		}
		else
		{
			char&	c = op[0];
			int		n;
			
			switch(c)
			{
				case	'p':
					n = pop();
					break;
				case	's':
					n = size();
					break;
				case	'e':
					n = empty();
					break;
				case	'f':
					n = front();
					break;
				case	'b':
					n = back();
					break;
				default:
					// do nothing
					break;
			}
			
			cout<<n<<'\n';
		}
	}
	
	return	0;
}

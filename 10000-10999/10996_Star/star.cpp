#include	<iostream>
#include	<string>

using namespace	std;

#define	UP			0
#define	DOWN		1
#define	MAX_LINE	2

#define	NEXT_LINE(l)	(((l)+1)%MAX_LINE)

void	build_str(int N,string& up,string& down)
{
	int	current_line,num_of_printed_star;
	
	for(current_line=UP,num_of_printed_star=0;num_of_printed_star<N;num_of_printed_star++)
	{
		if( current_line == UP )
		{
			up += "* ";
		}
		else
		{
			down +=" *";
		}
		
		current_line = NEXT_LINE(current_line);
	}
}

int		main(void)
{
	int		N;
	string	l1,l2;
	
	cin>>N;
	build_str(N,l1,l2);
	
	l1.push_back('\n');
	
	if( l2.length() != 0 )
	{
		l2.push_back('\n');
		l1 += l2;
	}
	
	for(int i=1;i<=N;i++)
	{
		cout<<l1;
	}
	
	return	0;
}

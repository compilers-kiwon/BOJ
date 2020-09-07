#include	<iostream>
#include	<string>

using namespace	std;

#define	MAX_SIZE	(100+1)

#define	NONE			0
#define	IMPOUNDED		1
#define	RETURNED		2
#define	NEXT_STATE(s)	((s)+1)

string	girl[MAX_SIZE];
int		state[MAX_SIZE];

int	main(void)
{
	for(int s=1;;s++)
	{
		int	n;
		
		cin>>n;
		
		if( n == 0 )
		{
			break;
		}
		getchar();
		
		for(int i=1;i<=n;i++)
		{
			getline(cin,girl[i]);
			state[i] = NONE;
		}
		
		for(int i=1;i<=2*n-1;i++)
		{
			int		e;
			char	c;
			
			cin>>e>>c;
			state[e] = NEXT_STATE(state[e]);
		}
		
		for(int i=1;i<=n;i++)
		{
			if( state[i] == IMPOUNDED )
			{
				cout<<s<<" "<<girl[i]<<'\n';
				break;
			}
		}
	}
	
	return	0;
}

#include	<iostream>
	
using namespace	std;

#define	MAX_NUM_OF_VARIABLE	0x100

void	run(int len_of_program,bool* variable)
{
	for(int i=1;i<=len_of_program;i++)
	{
		char	v1,eq,v2;
		
		cin>>v1>>eq>>v2;
		variable[v1] = variable[v2];
	}
}

int		main(void)
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	
	for(int i=1;;i++)
	{
		int		n,cnt;
		bool	v[MAX_NUM_OF_VARIABLE];
		
		cin>>n;
		
		if( n == 0 )
		{
			break;
		}
		
		v['a'] = true;
		
		for(char c='b';c<='z';c++)
		{
			v[c] = false;
		}
		
		run(n,v);
		
		cout<<"Program #"<<i<<'\n';
		cnt = 0;
		
		for(char c='a';c<='z';c++)
		{
			if( v[c] == true )
			{
				cout<<c<<' ';
				cnt++;
			}
		}
		
		if( cnt == 0 )
		{
			cout<<"none";
		}
		cout<<"\n\n";
	}
	
	return	0;
}

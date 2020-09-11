#include	<iostream>
#include	<string>
#include	<map>

using namespace	std;

const string	welcome = "welcome to code jam";

#define	MOD(n)	((n)%10000)

int	main(void)
{
	int				N;
	map<string,int>	state_machine;
	string			tmp;
	
	cin>>N;getchar();
	
	for(int i=0;i<welcome.length();i++)
	{
		tmp.push_back(welcome[i]);
		state_machine[tmp] = 0;
	}
	
	for(int n=1;n<=N;n++)
	{
		map<string,int>::iterator	it;
		
		for(it=state_machine.begin();it!=state_machine.end();it++)
		{
			it->second = 0;
		}
		
		string	t;

		getline(cin,t);
		
		for(int i=0;i<t.length();i++)
		{
			char&	c = t[i];
			
			if( c == 'w' )
			{
				state_machine["w"]++;
			}
			else
			{
				for(it=state_machine.begin();it!=state_machine.end();it++)
				{
					// it->first = state
					// it->second = cnt
					
					char	tail;
					string	state;
					int&	cnt = it->second;
					
					state = it->first;
					tail = state[state.length()-1];
					
					if( c == tail )
					{
						state.erase(state.length()-1,1);
						cnt = MOD(cnt+state_machine[state]); 
					}
				}
			}
		}
		
		printf("Case #%d: %04d\n",n,state_machine[welcome]);
	}
	
	return	0;
}

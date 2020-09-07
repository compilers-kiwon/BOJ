#include	<iostream>
#include	<string>

using namespace	std;

#define	STATE1		1
#define	STATE2		2
#define	STATE3		3
#define	STATE4		4
#define	STATE5		5
#define	STATE6		6
#define	MAX_STATE	7

bool	run_state_machine(const string& p,int state,int idx)
{
	if( idx == p.length() )
	{
		if( state==STATE4 || state==STATE6 )
		{
			return	true;
		}
		return	false;
	}
	
	switch(state)
	{
		case	STATE1:
			if( p[idx] == '0' )
			{
				return	run_state_machine(p,STATE2,idx+1);
			}
			break;
		case	STATE2:
			if( p[idx] == '0' )
			{
				return	run_state_machine(p,STATE3,idx+1);
			}
			break;
		case	STATE3:
			if( p[idx] == '0' )
			{
				return	run_state_machine(p,STATE3,idx+1);
			}
			else
			{
				return	run_state_machine(p,STATE4,idx+1);
			}			
			break;
		case	STATE4:
			if( p[idx] == '1' )
			{
				if( run_state_machine(p,STATE4,idx+1) || run_state_machine(p,STATE1,idx+1) )
				{
					return	true;
				}
			}
			else
			{
				return	run_state_machine(p,STATE5,idx+1);
			}
			break;
		case	STATE5:
			if( p[idx] == '1' )
			{
				return	run_state_machine(p,STATE6,idx+1);
			}
			break;
		case	STATE6:
			if( p[idx] == '1' )
			{
				return	run_state_machine(p,STATE1,idx+1);
			}
			else
			{
				return	run_state_machine(p,STATE5,idx+1);
			}
			break;
		default:
			// do nothing
			break;
	}
	
	return	false;
}

int		main(void)
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	
	int	N;
	
	cin>>N;
	
	for(int i=1;i<=N;i++)
	{
		string	p;
		bool	ret;
		
		cin>>p;
		
		if( p[0] == '0' )
		{
			ret = run_state_machine(p,STATE5,1);
		}
		else
		{
			ret = run_state_machine(p,STATE1,1);
		}
		
		if( ret == true )
		{
			cout<<"YES\n";
		}
		else
		{
			cout<<"NO\n";
		}
	}
	
	return	0;
}

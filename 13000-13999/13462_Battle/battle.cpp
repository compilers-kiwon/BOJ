#include	<iostream>
#include	<string>

using namespace	std;

#define	get_counter(c)		((c)=='R'?'S':(c)=='B'?'K':'H')
#define	find_char(a,b,c,t)	((a)==(t)||(b)==(t)||(c)==(t))

int	main(void)
{
	string	monster_attack,mech_counter;
	
	cin>>monster_attack;
	
	for(int i=0;i<monster_attack.length();i++)
	{
		char	c;
		
		c = get_counter(monster_attack[i]);
		mech_counter.push_back(c);
		
		if( mech_counter.length() >= 3 )
		{
			char	c1,c2,c3;
			int		p;
			
			p = mech_counter.length();
			c1 = mech_counter[p-1];
			c2 = mech_counter[p-2];
			c3 = mech_counter[p-3];
			
			if( find_char(c1,c2,c3,'S') && find_char(c1,c2,c3,'K') && find_char(c1,c2,c3,'H') )
			{
				mech_counter.erase(p-3,3);
				mech_counter.push_back('C');
			}
		}
	}
	
	cout<<mech_counter<<'\n';
	
	return	0;
}

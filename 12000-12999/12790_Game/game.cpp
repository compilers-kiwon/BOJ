#include	<iostream>

using namespace	std;

class	Character{
	private:
		int	HP,MP,offense,defense;
	
	public:
		void	setHP(int h){ HP=h; }
		void	setMP(int m){ MP=m; }
		void	setOffense(int o){ offense=o; }
		void	setDefense(int d){ defense=d; }
		
		void	addHP(int h){ HP+=h; }
		void	addMP(int m){ MP+=m; }
		void	addOffense(int o){ offense+=o; }
		void	addDefense(int d){ defense+=d; }
		
		int		getPower(void){
			return	(HP<1?1:HP)+5*(MP<1?1:MP)+2*(offense<0?0:offense)+2*defense;
		}
};

int		main(void)
{
	int	T;
	
	cin>>T;
	
	for(int i=1;i<=T;i++)
	{
		int			h,m,o,d;
		Character	c;
		
		cin>>h>>m>>o>>d;
		
		c.setHP(h);c.setMP(m);c.setOffense(o);c.setDefense(d);
		
		cin>>h>>m>>o>>d;
		
		c.addHP(h);c.addMP(m);c.addOffense(o);c.addDefense(d);
		
		cout<<c.getPower()<<endl;		
	}
	return	0;
}

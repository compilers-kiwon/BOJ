#include	<iostream>
#include	<string>
#include	<stack>

using namespace	std;

#define	UP		'u'
#define	RIGHT	'r'
#define	DOWN	'd'
#define	LEFT	'l'

bool	is_opposite(char d1,char d2)
{
	bool	ret;
	
	if( (d1==UP&&d2==DOWN) || (d1==RIGHT&&d2==LEFT) 
		|| (d1==DOWN&&d2==UP) || (d1==LEFT&&d2==RIGHT) )
	{
		ret = true;
	}
	else
	{
		ret = false;
	}
	
	return	ret;
}

int		main(void)
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	
	int	K;
	
	cin>>K;
	
	for(int k=1;k<=K;k++)
	{
		string		str;
		stack<char>	st;
		
		cin>>str;
		
		for(int i=0;i<str.length();i++)
		{
			if( !st.empty() && is_opposite(st.top(),str[i]) )
			{
				st.pop();
			}
			else
			{
				st.push(str[i]);
			}
		}
		
		cout<<"Data Set "<<k<<":\n";
		
		if( st.empty() )
		{
			cout<<"Yes\n\n";
		}
		else
		{
			cout<<"No\n\n";
		}
	}
	
	return	0;
}

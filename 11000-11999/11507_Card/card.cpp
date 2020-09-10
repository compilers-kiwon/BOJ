#include	<iostream>
#include	<string>
#include	<map>
#include	<vector>

using namespace	std;

typedef	vector<int>	Card;

#define	MAX_NUM	13

void	init(map<char,Card>& table)
{
	table['P'].resize(MAX_NUM+1,false);
	table['K'].resize(MAX_NUM+1,false);
	table['H'].resize(MAX_NUM+1,false);
	table['T'].resize(MAX_NUM+1,false);
}

bool	check_card(map<char,Card>& table,char& p,int& n)
{
	if( table[p][n] == true )
	{
		return	false;
	}
	
	table[p][n] = true;
	
	return	true;
}

int		count_card(map<char,Card>& table,char p)
{
	int	cnt,i;
	
	for(cnt=0,i=1;i<=MAX_NUM;i++)
	{
		if( table[p][i] == false )
		{
			++cnt;
		}
	}
	return	cnt;
}

int		main(void)
{
	string			S;
	map<char,Card>	card;
	
	cin>>S;
	
	init(card);
	
	for(int i=0;i<S.length();i+=3)
	{
		char	pattern;
		int		v;
		
		pattern = S[i];
		v = (int)(S[i+1]-'0')*10+(int)(S[i+2]-'0');
		
		if( check_card(card,pattern,v) == false )
		{
			cout<<"GRESKA\n";
			return	0;
		}
	}
	
	cout<<count_card(card,'P')<<' '<<count_card(card,'K')<<' '<<count_card(card,'H')<<' '<<count_card(card,'T')<<endl;
	
	return	0;
}

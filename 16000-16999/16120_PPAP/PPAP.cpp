#include	<iostream>
#include	<vector>
#include	<string>

using namespace	std;

void	roll_back(string& str,int& str_index,vector<char>& ppap)
{
	if( ppap.size() >= 4 )
	{
		char&	c1 = ppap[ppap.size()-4];
		char&	c2 = ppap[ppap.size()-3];
		char&	c3 = ppap[ppap.size()-2];
		char&	c4 = ppap[ppap.size()-1];
		
		if( c1=='P' && c2=='P' && c3=='A' && c4=='P' )
		{
			ppap.pop_back();
			ppap.pop_back();
			ppap.pop_back();
			
			roll_back(str,str_index,ppap);
		}
	}

	if( str_index == str.length() )
	{
		return;
	}
	
	ppap.push_back(str[str_index]);
	roll_back(str,++str_index,ppap);
}

int		main(void)
{
	string			str;
	vector<char>	ppap;
	int				index;
	
	cin.sync_with_stdio(false);
	
	cin>>str;
	index = 0;
	
	roll_back(str,index,ppap);
	
	if( ppap.size()==1 && ppap[0]=='P' )
	{
		cout<<"PPAP\n";
	}
	else
	{
		cout<<"NP\n";
	}
	
	return	0;
}

#include	<iostream>
#include	<vector>
#include	<string>

using namespace	std;

#define	in_range(MIN,n,MAX)	((MIN)<=(n)&&(n)<=(MAX))
#define	UPPER_OFFSET		32

typedef	pair<string,string>	Name;	// first:original,second:upper

void	make_upper(string& src,string& dst)
{
	for(int i=0;i<src.length();i++)
	{
		char&	c = src[i];
		
		if( in_range('a',c,'z') == true )
		{
			dst.push_back(c-(char)UPPER_OFFSET);
		}
		else
		{
			dst.push_back(c);
		}
	}
}

void	input(int& num_of_buildings,vector<Name>& buildings,Name& building_code)
{
	cin>>num_of_buildings;getchar();
	
	for(int i=1;i<=num_of_buildings;i++)
	{
		Name t;
		
		getline(cin,t.first);
		make_upper(t.first,t.second);
		
		buildings.push_back(t);
	}
	
	cin>>building_code.first;
	make_upper(building_code.first,building_code.second);
}

bool	is_matched(string& name,string& code,int name_idx,int code_idx)
{
	if( code_idx == code.length() )
	{
		return	true;
	}
	
	for(int i=name_idx;i<name.length();i++)
	{
		if( name[i] == code[code_idx] )
		{
			if( is_matched(name,code,i+1,code_idx+1) == true )
			{
				return	true;
			}
		}
	}
	
	return	false;
}

int		main(void)
{
	int	K;
	
	cin>>K;
	
	for(int k=1;k<=K;k++)
	{
		int				n;
		vector<Name>	buildings;
		Name			building_code;
		
		input(n,buildings,building_code);
		
		cout<<"Data Set "<<k<<":\n";
		
		for(int i=0;i<n;i++)
		{
			if( is_matched(buildings[i].second,building_code.second,0,0) == true )
			{
				cout<<buildings[i].first<<'\n';
			}
		}
	}
	
	return	0;
}

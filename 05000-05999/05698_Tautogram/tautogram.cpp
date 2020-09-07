#include	<iostream>
#include	<string>
#include	<vector>

using namespace	std;

bool	is_same_head(vector<char>& heads)
{
	bool	flag;
	int		i;
	
	for(flag=true,i=1;i<heads.size()&&flag!=false;i++)
	{
		if( heads[0] != heads[i] )
		{
			char	small,big;
			
			small = min(heads[0],heads[i]);
			big = max(heads[0],heads[i]);
			
			if( (big-small) != 32 )
			{
				flag = false;
			}
		}
	}
	
	return	flag;
}

int		main(void)
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	
	while(1)
	{
		string	line;
		
		getline(cin,line);
		
		if( line == "*" )
		{
			break;
		}
		
		vector<char>	h;
		
		for(int i=0;i<line.length();i++)
		{
			if( line[i] != ' ' )
			{
				if( i==0 || line[i-1]==' ' )
				{
					h.push_back(line[i]);
				}
			}
		}
		
		if( is_same_head(h) == true )
		{
			cout<<"Y\n";
		}
		else
		{
			cout<<"N\n";
		}
	}
	
	return	0;
}

#include	<iostream>
#include	<vector>
#include	<string>

using namespace	std;

void	parse_str(string& str,vector<string>& v)
{
	str.push_back(' ');
	
	string	w;
	
	for(int i=0;i<str.length();i++)
	{
		if( str[i] == ' ' )
		{
			v.push_back(w);
			w.clear();
		}
		else
		{
			w.push_back(str[i]);
		}
	}
}

int		main(void)
{	
	int	N;
	
	cin>>N;getchar();
	cin.sync_with_stdio(false);
	
	for(int i=1;i<=N;i++)
	{
		string			str;
		vector<string>	vec;
		
		getline(cin,str);
		parse_str(str,vec);
		
		cout<<"Case #"<<i<<": ";
		
		for(int j=vec.size()-1;j>0;j--)
		{
			cout<<vec[j]<<' ';
		}
		cout<<vec[0]<<'\n';
	}
	
	return	0;
}

#include	<iostream>
#include	<set>
#include	<string>
#include	<vector>

using namespace	std;

void	get_data(string& stream,set<string>& data_set)
{
	string	name;
	
	stream.push_back(' ');
	
	for(int i=0;i<stream.length();i++)
	{
		char&	c = stream[i];
		
		if( c==' ' || c=='\t' )
		{
			if( name.length() != 0 )
			{
				data_set.insert(name);
				name.clear();
			}
		}
		else
		{
			name.push_back(c);
		}
	}
}

int		main(void)
{
	int	T;
	
	cin>>T;
	
	for(int t=1;t<=T;t++)
	{
		int				n,d;
		vector<string>	r;
		set<string>		data;
		
		cin>>n;
		
		for(int i=1;i<=n;i++)
		{
			string	str;
			
			cin>>str;
			r.push_back(str);
		}
		
		cin>>d;getchar();
		
		for(int i=1;i<=d;i++)
		{
			string	stream;
			
			getline(cin,stream);
			get_data(stream,data);
		}
		
		cout<<"Test set "<<t<<":\n";
		
		for(int i=0;i<r.size();i++)
		{
			if( data.find(r[i]) != data.end() )
			{
				cout<<r[i]<<" is present\n";
			}
			else
			{
				cout<<r[i]<<" is absent\n";
			}
		}
		
		puts("");
	}
	
	return	0;
}

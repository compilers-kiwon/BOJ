#include	<iostream>
#include	<string>
#include	<map>
#include	<vector>

using namespace	std;

void	input(vector<string>& p,map<string,int>& table,string& s,int& n)
{
	string	str,name;
	
	getline(cin,str);
	str.push_back(' ');
	
	for(int i=0,idx=0;i<str.length();i++)
	{
		if( str[i] == ' ' )
		{
			p.push_back(name);
			table[name] = idx;
			
			idx++;
			name.clear();
		}
		else
		{
			name.push_back(str[i]);
		}
	}
	
	cin>>s>>n;getchar();
}

int		compute(int s,int n,int num_of_people)
{
	return	((s+(n%num_of_people)+(num_of_people-1))%num_of_people);
}

int		main(void)
{	
	int	t;
	
	cin>>t;getchar();
	
	for(;t>0;t--)
	{
		vector<string>	p;
		map<string,int>	table;
		string			s;
		int				n;
		
		input(p,table,s,n);
		cout<<p[compute(table[s],n,p.size())]<<'\n';
	}
	
	return	0;
}

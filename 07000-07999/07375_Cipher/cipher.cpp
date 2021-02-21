#include	<iostream>
#include	<string>
#include	<vector>

using namespace	std;

typedef	pair<int,string>	Message;
typedef	vector<int>			SCC;

#define	MAX_SIZE	(200+1)
#define	char2int(c)	((int)((c)-'0'))

int		read_number(const string& str,int& n)
{
	int	ret;
	
	for(ret=n=0;str[ret]!=' ';ret++)
	{
		n = n*10+char2int(str[ret]);
	}
	
	return	++ret;
}

void	get_message(const string& str,Message& m)
{
	int	ptr;
	
	ptr = read_number(str,m.first);
	m.second.push_back(' ');
		
	for(;ptr<str.length();ptr++)
	{
		m.second.push_back(str[ptr]);
	}
}

void	find_scc(vector<SCC>& scc,vector<int>& key)
{
	vector<bool>	visited(key.size(),false);
	
	for(int i=1;i<key.size();i++)
	{
		if( visited[i] == true )
		{
			continue;
		}
		
		SCC s;
		
		for(int j=i;visited[j]==false;j=key[j])
		{
			visited[j] = true;
			s.push_back(j);
		}
		
		scc.push_back(s);
	}
}

bool	input(vector<int>& key,vector<Message>& block)
{
	int	n;
	
	cin>>n;
	
	if( n == 0 )
	{
		return	false;
	}
	
	key.push_back(0);
	
	for(int i=1;i<=n;i++)
	{
		int	a;
		
		cin>>a;
		key.push_back(a);
	}
	
	getchar();
	
	for(;;)
	{
		string	str;
		Message	m;
		
		getline(cin,str);
		
		if( str == "0" )
		{
			break;
		}
		
		get_message(str,m);
		
		for(;m.second.length()<key.size();)
		{
			m.second.push_back(' ');
		}
		
		block.push_back(m);
	}
	
	return	true;
}

int		main(void)
{
	for(;;)
	{
		vector<int>		key;
		vector<Message>	block;
		vector<SCC>		scc;
		
		if( input(key,block) == false )
		{
			break;
		}
		
		find_scc(scc,key);
		
		for(int i=0;i<block.size();i++)
		{
			int&	K = block[i].first;
			string&	str = block[i].second;
			char	result[MAX_SIZE+1];
			for(int j=0;j<scc.size();j++)
			{
				int		num_of_repeat;
				
				num_of_repeat = K%scc[j].size();
				
				for(int k=0;k<scc[j].size();k++)
				{
					int	src_idx,dst_idx;
					
					src_idx = scc[j][k];
					dst_idx = scc[j][(k+num_of_repeat)%scc[j].size()];
					
					result[dst_idx] = str[src_idx];
				}
			}
			
			result[str.length()] = '\0';
			cout<<&result[1]<<'\n';
		}
		
		cout<<'\n';
	}
	
	return	0;
}

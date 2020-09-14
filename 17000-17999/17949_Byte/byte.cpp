#include	<iostream>
#include	<string>
#include	<vector>

using namespace	std;

#define	CHAR		2
#define	INT			8
#define	LONG_LONG	16

#define	IN_RANGE(MIN,n,MAX)	((MIN)<=(n)&&(n)<=(MAX))

typedef	unsigned long long uint64;

void	input(string& str,int& n,vector<string>& v)
{
	cin>>str>>n;
	
	for(int i=1;i<=n;i++)
	{
		string	t;
		
		cin>>t;
		v.push_back(t);
	}
}

void	parse(string& h,vector<string>& t,vector<uint64>& result)
{
	for(int i=0,ptr=0;i<t.size();i++)
	{
		string	s;
		uint64	n;
		
		if( t[i] == "char" )
		{
			s = h.substr(ptr,CHAR);
			ptr += CHAR;
		}
		else if( t[i] == "int" )
		{
			s = h.substr(ptr,INT);
			ptr += INT;
		}
		else	// t[i] == "long_long"
		{
			s = h.substr(ptr,LONG_LONG);
			ptr += LONG_LONG;
		}
		
		sscanf(s.c_str(),"%llx",&n);
		result.push_back(n);
	}
}

int		main(void)
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	
	string			hex;
	int				N;
	vector<string>	type;
	vector<uint64>	decode;
	
	input(hex,N,type);
	parse(hex,type,decode);
	
	for(int i=0;i<N;i++)
	{
		cout<<decode[i]<<' ';
	}
	
	return	0;
}

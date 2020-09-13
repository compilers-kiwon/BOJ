#include	<iostream>
#include	<vector>
#include	<string>

using namespace	std;

typedef	pair<int,int>	Operation;

#define	THROW	0
#define	UNDO	1

#define	char2int(c)	((int)((c)-'0'))

int		str2int(string& str)
{
	int	n,i,f;
	
	if( str[0] == '-' )
	{
		f = -1;
		i = 1;
	}
	else
	{
		f = 1;
		i = 0;
	}
	
	for(n=0;i<str.length();i++)
	{
		char&	c = str[i];
		
		n = n*10+char2int(c);
	}
	
	return	f*n;
}

void	parse(string& str,vector<Operation>& op_vec)
{
	string	buf;
	bool	undo_flag;
	
	undo_flag = false;
	str.push_back(' ');
	
	for(int i=0;i<str.length();i++)
	{
		char&	c = str[i];
		
		if( c == ' ' )
		{
			if( undo_flag == true )
			{
				undo_flag = false;
				op_vec.push_back(make_pair(UNDO,str2int(buf)));
			}
			else
			{
				if( buf == "undo" )
				{
					undo_flag = true;
				}
				else
				{
					op_vec.push_back(make_pair(THROW,str2int(buf)));
				}
			}
			buf.clear();
		}
		else
		{
			buf.push_back(c);
		}
	}
}

void	build_actual_work_list(vector<int>& actual,vector<Operation>& op_vec)
{
	for(int i=0;i<op_vec.size();i++)
	{
		if( op_vec[i].first == UNDO )
		{
			for(int	m=op_vec[i].second;!actual.empty()&&m>0;m--)
			{
				actual.pop_back();
			}
		}
		else
		{
			actual.push_back(op_vec[i].second);
		}
	}
}

int		get_final_position(int circle_size,vector<int>& actual)
{
	int	pos,i;
	
	for(pos=i=0;i<actual.size();i++)
	{
		int&	t = actual[i];
		
		if( t >= 0 )
		{
			pos = (pos+t)%circle_size;	
		}
		else
		{
			pos = (pos+circle_size-((-t)%circle_size))%circle_size;
		} 
	}
	
	return	pos;
}

int		main(void)
{
	int		n,k;
	string	str;
	
	cin>>n>>k;getchar();
	getline(cin,str);
	
	vector<Operation>	op;
	vector<int>			t;
	
	parse(str,op);
	build_actual_work_list(t,op);
	
	cout<<get_final_position(n,t)<<'\n';
	
	return	0;
}

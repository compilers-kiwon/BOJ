#include	<iostream>
#include	<string>
#include	<vector>

using namespace	std;

#define	LEFT	'('
#define	RIGHT	')'

#define	NONE		-1
#define	NUMBER		0
#define	LEFT_PAREN	1
#define	GENOME		2
#define	RIGHT_PAREN	3
#define	MAX_STATE	4

#define	IN_RANGE(MIN,n,MAX)	((MIN)<=(n)&&(n)<=(MAX))

int		str2int(string& str)
{
	if( str.length() == 0 )
	{
		return	1;
	}
	
	int	ret;
	
	ret = 0;
	
	for(int i=0;i<str.length();i++)
	{
		ret = ret*10+(int)(str[i]-'0');
	}
	
	return	ret;
}

void	add_str(string& result,string& str,int n,int query)
{
	for(int i=1;i<=n;i++)
	{
		result += str;
		
		if( result.length() > query )
		{
			break;
		}
	}
}

bool	parse(string& src,string& result,int& s,int query)
{
	string	tmp;
	int		n,prev_state,current_state;
	bool	out,flag;

	n = 1;
	out = false;
	prev_state = NONE;
	
	for(s;s<src.length();)
	{
		char&	c = src[s];
		
		switch(c)
		{
			case	LEFT:
				n = str2int(tmp);
				tmp.clear();
				
				flag = parse(src,tmp,++s,query);
												
				if( flag == true )
				{
					result += tmp;
					return	true;
				}
				
				add_str(result,tmp,n,query);
				tmp.clear();
				
				if( result.length() > query )
				{
					return	true;
				}
				
				current_state = NONE;
				break;
			case	RIGHT:
				++s;
				add_str(result,tmp,n,query);
				
				if( result.length() > query )
				{
					return	true;
				}
				
				out = true;
				break;
			default:
				if( IN_RANGE('0',c,'9') == true )
				{
					if( prev_state != NUMBER )
					{
						add_str(result,tmp,n,query);
						tmp.clear();
				
						if( result.length() > query )
						{
							return	true;
						}
					}
					tmp.push_back(c);
					current_state = NUMBER;
				}
				
				if( IN_RANGE('A',c,'Z') == true )
				{
					if( prev_state != GENOME )
					{
						n = str2int(tmp);
						tmp.clear();
					}
					tmp.push_back(c);
					current_state = GENOME;
				}
				
				++s;
				break;
		}
		
		if( out == true )
		{
			break;
		}
		
		prev_state = current_state;
	}
	
	return	false;
}

int		main(void)
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	
	for(;;)
	{
		string	s,result;
		int		i,ptr;
		
		cin>>s>>i;
		
		if( s=="0" && i==0 )
		{
			break;
		}
		
		s.insert(s.begin(),'(');
		s.push_back(')');
		
		ptr = 0;
		parse(s,result,ptr,i);
		
		if( i < result.length() )
		{
			cout<<result[i]<<'\n';
		}
		else
		{
			cout<<"0\n";
		}
	}
	
	return	0;
}

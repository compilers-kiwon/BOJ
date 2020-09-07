#include	<iostream>
#include	<deque>
#include	<string>
#include	<algorithm>

using namespace	std;

#define	char2int(c)	((int)((c)-'0'))

#define	ERROR		-1

#define	FORWARD		0
#define	BACKWARD	1
#define	MAX_DIR		2

#define	REVERSE(d)	(((d)+1)%MAX_DIR)

int		str2int(string& str)
{
	int	i,n;
	
	for(i=n=0;i<str.length();i++)
	{
		n = n*10+char2int(str[i]);
	}
	
	return	n;
}

void	parse(string& arr,deque<int>& dq)
{
	int		i,n;
	string	tmp;
		
	for(i=1;i<arr.length();i++)
	{
		if( arr[i]>='0' && arr[i]<='9' )
		{
			tmp.push_back(arr[i]);
		}
		else
		{
			dq.push_back(str2int(tmp));
			tmp.clear();
		}
	}
}

int		do_operation(string& op,deque<int>& dq)
{
	int	d;
	
	d = FORWARD;
	
	for(int i=0;i<op.length();i++)
	{
		if( op[i] == 'R' )
		{
			d = REVERSE(d);
		}
		else
		{
			if( dq.empty() )
			{
				d = ERROR;
				break;
			}
			
			if( d == FORWARD )
			{
				dq.pop_front();
			}
			else
			{
				dq.pop_back();
			}
		}
	}
	return	d;
}

int		main(void)
{
	ios::sync_with_stdio(false);

	int	T;
	
	cin>>T;
	
	while(T>0)
	{
		string		p,arr;
		int			n,d;
		deque<int>	dq;
		
		cin>>p>>n>>arr;
		
		if( n != 0 )
		{
			parse(arr,dq);
		}
		d = do_operation(p,dq);
		
		if( d == ERROR )
		{
			cout<<"error\n";
		}
		else
		{
			if( dq.size() == 0 )
			{
				cout<<"[]\n";
			}
			else
			{
				if( d == BACKWARD )
				{
					reverse(dq.begin(),dq.end());
				}
				
				cout<<'[';
				for(int i=0;i<dq.size();i++)
				{
					cout<<dq[i];
					
					if( i<dq.size()-1 )
					{
						cout<<',';
					}
				}
				cout<<"]\n";
			}
		}
		
		T--;
	}
	return	0;
}

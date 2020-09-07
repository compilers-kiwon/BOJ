#include	<iostream>
#include	<string>

using namespace	std;

#define	char2int64(c)	((int64)((c)-'0'))
#define	int642char(i)	((char)((i)+(int64)'0'))

typedef	long long int	int64;

void	get_number(int64 n,int64 b,string& s)
{
	if( n == 0 )
	{
		s.push_back('0');
		return;
	}
	
	for(;n>0;n/=b)
	{
		s.push_back(int642char(n%b));
	}
	
	for(int h=0,t=s.length()-1;h<t;h++,t--)
	{
		swap(s[h],s[t]);
	}
}

int		main(void)
{
	for(;;)
	{
		int64	b,p_value,m_value;
		string	p,m,n;
		
		cin>>b;
		
		if( b == 0 )
		{
			break;
		}
		
		cin>>p>>m;
		
		p_value = m_value = 0;
		
		for(int i=0;i<m.length();i++)
		{
			m_value = m_value*b+char2int64(m[i]);
		}
		
		for(int i=0;i<p.length();i++)
		{
			p_value = p_value*b+char2int64(p[i]);
			
			if( p_value >= m_value )
			{
				p_value %= m_value;
			}
		}
		
		get_number(p_value,b,n);
		cout<<n<<'\n';
	}
	
	return	0;
}

#include	<iostream>
#include	<string>
#include	<vector>

using namespace	std;

#define	c_pos	0
#define	h_pos	1
#define	o_pos	2
#define	MAX_POS	3

#define	M1			0
#define	M2			1
#define	M3			2
#define	MAX_MOLE	3

#define	char2int(c)	((int)((c)-'0'))
#define	MAX_NUM		10

#define	IN_RANGE(MIN,n,MAX)	((MIN)<=(n)&&(n)<=(MAX))

typedef	struct	_MOLE_INFO	Mole;
struct	_MOLE_INFO
{
	vector<char>	exp;
	int				atom_cnt[MAX_POS];
};

void	parse_mole(Mole& m)
{
	m.atom_cnt[c_pos] = m.atom_cnt[h_pos] = m.atom_cnt[o_pos] = 0;
	
	for(int i=0;i<m.exp.size();i+=2)
	{
		int	pos,n;
		
		switch(m.exp[i])
		{
			case	'C':
				pos = c_pos;
				break;
			case	'H':
				pos = h_pos;
				break;
			case	'O':
				pos = o_pos;
				break;
			default:
				// do nothing
				break;
		}
		
		n = char2int(m.exp[i+1]);
		m.atom_cnt[pos] += n;
	}
}

void	input(Mole* m)
{
	string	str;
	
	cin>>str;
	str.push_back('+');
	
	for(int m_index=M1,i=0;m_index<MAX_MOLE;i++)
	{
		if( str[i]=='+' || str[i]=='=' )
		{
			if( IN_RANGE('A',m[m_index].exp.back(),'Z') )
			{
				m[m_index].exp.push_back('1');
			}
			
			m_index++;
			continue;
		}
		
		if( IN_RANGE('A',str[i],'Z') )
		{
			if( m[m_index].exp.size()!=0 && IN_RANGE('A',m[m_index].exp.back(),'Z') )
			{
				m[m_index].exp.push_back('1');
			}
		}
		
		m[m_index].exp.push_back(str[i]);
	}
}

int		main(void)
{
	Mole	m[MAX_MOLE];
	bool	found;
	int		i,j,k;
	
	input(m);
	
	for(i=M1;i<=M3;i++)
	{
		parse_mole(m[i]);
	}
	
	found = false;
	
	for(i=1;i<=MAX_NUM&&found==false;i++)
	{
		int	num_of_m1_c,num_of_m1_h,num_of_m1_o;
		
		num_of_m1_c = i*m[M1].atom_cnt[c_pos];
		num_of_m1_h = i*m[M1].atom_cnt[h_pos];
		num_of_m1_o = i*m[M1].atom_cnt[o_pos];
		
		for(j=1;j<=MAX_NUM&&found==false;j++)
		{
			int	num_of_m2_c,num_of_m2_h,num_of_m2_o;
			
			num_of_m2_c = j*m[M2].atom_cnt[c_pos];
			num_of_m2_h = j*m[M2].atom_cnt[h_pos];
			num_of_m2_o = j*m[M2].atom_cnt[o_pos];
			
			for(k=1;k<=MAX_NUM&&found==false;k++)
			{
				int	num_of_m3_c,num_of_m3_h,num_of_m3_o;
				
				num_of_m3_c = k*m[M3].atom_cnt[c_pos];
				num_of_m3_h = k*m[M3].atom_cnt[h_pos];
				num_of_m3_o = k*m[M3].atom_cnt[o_pos];
				
				if( (num_of_m1_c+num_of_m2_c==num_of_m3_c) 
					&& (num_of_m1_h+num_of_m2_h==num_of_m3_h)
					&& (num_of_m1_o+num_of_m2_o==num_of_m3_o) )
				{
					cout<<i<<' '<<j<<' '<<k<<'\n';
					found = true;		
				}
			}
		}
	}
	
	if( found == false )
	{
		cout<<"NEMOGUCE\n";
	}
	
	return	0;
}

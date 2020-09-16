#include	<iostream>
#include	<string>

using namespace	std;

#define	GROUP_LEN		5
#define	GET_INDEX(C)	((int)((C)-'A'))

void	input(int& ciphertext_len,string& ciphertext,string& crib)
{
	cin>>ciphertext_len;
	
	for(int i=0;i<ciphertext_len;i+=GROUP_LEN)
	{
		string	w;
		
		cin>>w;
		ciphertext += w;
	}
	
	cin>>crib;
}

void	build_modified_plaintext(string& cipher,int g,string& modified)
{
	for(int i=0;i<cipher.length();i+=g)
	{
		int	s,e;
		
		s = min(i+g-1,(int)(cipher.length())-1);
		e = i;
		
		for(int j=s;j>=e;j--)
		{
			modified.push_back(cipher[j]);
		}
	}
}

bool	is_same_offset(string& modified,int s,string& crib,int& offset)
{
	bool	ret;
	
	ret = true;
	offset = GET_INDEX(modified[s])-GET_INDEX(crib[0]);
	
	if( offset == 0 )
	{
		return	false;
	}
	
	if( offset < 0 )
	{
		offset += 26;
	}
	
	for(int i=1;i<crib.length();i++)
	{
		int	expected_index;
		
		expected_index = (GET_INDEX(crib[i])+offset)%26;
		
		if( expected_index != GET_INDEX(modified[s+i]) )
		{
			ret = false;
			break;
		}
	}
	
	return	ret;
}

int		main(void)
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	
	int	T;
	
	for(cin>>T;T>0;T--)
	{
		int		n,s_key,m_key;
		string	cipher,crib;
		
		input(n,cipher,crib);
		s_key = m_key = 0x7FFFFFFF;
		
		for(int m=5;m<=20;m++)
		{
			string	modified;
			
			build_modified_plaintext(cipher,m,modified);
			
			for(int i=0;i<=modified.length()-crib.length();i++)
			{
				int	offset;
					
				if( is_same_offset(modified,i,crib,offset) == true )
				{
					if( offset < s_key )
					{
						s_key = offset;
						m_key = m;
					}
					else if( offset == s_key )
					{
						if( m < m_key )
						{
							s_key = offset;
							m_key = m;
						}
					}
				}
			}
		}
		
		if( s_key==0x7FFFFFFF && m_key==0x7FFFFFFF )
		{
			cout<<"Crib is not encrypted.\n";
		}
		else
		{
			cout<<s_key<<' '<<m_key<<'\n';
		}
	}
	
	return	0;
}

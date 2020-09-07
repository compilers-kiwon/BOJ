#include	<iostream>
#include	<vector>
#include	<string>
#include	<map>

using namespace	std;

#define	MAX_SEQ_LEN			5
#define	MAX_CNT				5
#define	OFFSET(c)			((c)-'a')
#define	in_range(MIN,n,MAX)	((MIN)<=(n)&&(n)<=(MAX))

typedef	vector<string>	Seq;

void	input(string& s)
{
	for(;;)
	{
		char	c;
		
		c = fgetc(stdin);
		
		if( c == EOF )
		{
			break;
		}
		
		if( in_range('a',c,'z') == true )
		{
			c = 'A'+OFFSET(c);
		}
		
		s.push_back(c);
	}
}

bool	ignored(const string& s)
{
	for(int i=0;i<s.length();i++)
	{
		if( !in_range('A',s[i],'Z') )
		{
			return	true;
		}
	}
	
	return	false;
}

void	find_sequence(int seq_len,const string& str,map<int,Seq>& analysis_result)
{
	map<string,int>	frequency;
	
	for(int i=0;i<=str.length()-seq_len;i++)
	{
		string	s;
		
		s = str.substr(i,seq_len);
		
		if( ignored(s) == true )
		{
			continue;
		}
		
		frequency[s]--;
	}
	
	map<string,int>::iterator	it;
	
	for(it=frequency.begin();it!=frequency.end();it++)
	{
		analysis_result[it->second].push_back(it->first);
	}
}

void	print(int seq_len,map<int,Seq>& analysis_result)
{
	cout<<"Analysis for Letter Sequences of Length "<<seq_len<<'\n';
	cout<<"-----------------------------------------\n";
	
	int						cnt;
	map<int,Seq>::iterator	it;
	
	for(cnt=1,it=analysis_result.begin();cnt<=MAX_CNT&&it!=analysis_result.end();it++,cnt++)
	{
		cout<<"Frequency = "<<-(it->first)<<", Sequence(s) = (";
		
		for(int i=0;i<it->second.size()-1;i++)
		{
			cout<<it->second[i]<<',';
		}
		cout<<it->second.back()<<")\n";
	}
	
	cout<<'\n';
}

int		main(void)
{
	string	str;
	
	input(str);
	
	for(int i=1;i<=MAX_SEQ_LEN;i++)
	{
		map<int,Seq>	result;
		
		find_sequence(i,str,result);
		print(i,result);
	}
	
	return	0;
}

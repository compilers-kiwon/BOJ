#include	<iostream>
#include	<vector>
#include	<string>

using namespace	std;

#define	MAX_TABLE_SIZE	0x100
#define	HEX_SIZE		4
#define	NONE			0x100

#define	MAX_NONE_RUN_SIZE	128
#define	MAX_ENCODE_SIZE		130
#define	MIN_RUN_SIZE		3
#define	LINE_LENGTH			80

int	convert_table[MAX_TABLE_SIZE];

typedef	pair<int,int>	Byte;	// first:count,second:byte

void	init(void)
{
	int		value;
	char	c;
	
	for(c='0',value=0;c<='9';c++,value++)
	{
		convert_table[c] = value;
	}
	
	for(c='A',value=0xA;c<='F';c++,value++)
	{
		convert_table[c] = value;
	}
}

void	process_non_run_data(vector<int>& non_run,vector<int>& out)
{
	if( !non_run.empty() )
	{
		out.push_back(non_run.size()-1);
			
		for(int j=0;j<non_run.size();j++)
		{
			out.push_back(non_run[j]);
		}
		
		non_run.clear();
	}
}

void	encode(vector<Byte>& data,vector<int>& out)
{
	vector<int>	tmp;
	
	for(int i=0;i<data.size();i++)
	{
		int&	l = data[i].first;
		int&	b = data[i].second;
		
		if( l >= MIN_RUN_SIZE )
		{
			process_non_run_data(tmp,out);
			
			for(;l>=MIN_RUN_SIZE;)
			{
				int	h,encoded_len;
			
				encoded_len = min(l,MAX_ENCODE_SIZE);
				h = (1<<7)+encoded_len-MIN_RUN_SIZE;
			
				out.push_back(h);out.push_back(b);
				l -= encoded_len;
			}
		}
		
		for(int j=0;j<l;j++)
		{
			tmp.push_back(b);
			
			if( tmp.size() == MAX_NONE_RUN_SIZE )
			{
				process_non_run_data(tmp,out);
			}
		}
	}
	
	process_non_run_data(tmp,out);
}

void	RLE(vector<string>& data,vector<int>& out)
{
	vector<Byte>	cnt;
		
	for(int i=0;i<data.size();i++)
	{
		string& in = data[i];
		
		for(int j=0;j<in.length();j+=2)
		{ 
			int	n;
			
			n = (convert_table[in[j]]<<HEX_SIZE)+convert_table[in[j+1]];
			
			if( cnt.empty() || cnt.back().second!=n )
			{
				cnt.push_back(make_pair(1,n));
			}
			else
			{
				cnt.back().first++;
			}
		}
	}
	
	encode(cnt,out);
}

int		main(void)
{
	int	P;
	
	cin>>P;
	init();
	
	for(int p=1;p<=P;p++)
	{
		int				B;
		vector<string>	buf;
		vector<int>		out;
		
		cin>>B;
		
		for(int total_size=0;total_size<B*2;)
		{
			string	s;
			
			cin>>s;
			total_size += s.length();
			buf.push_back(s);
		}
		
		RLE(buf,out);
		cout<<out.size()<<'\n';
		
		for(int i=0;i<out.size();)
		{
			for(int j=0;j<LINE_LENGTH&&i<out.size();i++,j+=2)
			{
				printf("%02X",out[i]);
			}
			puts("");
		}
	}
	
	return	0;
}

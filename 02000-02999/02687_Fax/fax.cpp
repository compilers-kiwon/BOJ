#include	<iostream>
#include	<string>
#include	<vector>

using namespace	std;

#define	HALF_BYTE_SIZE			4
#define	IN_RANGE(MIN,n,MAX)		((MIN)<=(n)&&(n)<=(MAX))
#define	char2int(c)				(IN_RANGE('0',(c),'9')?((int)((c)-'0')):((int)((c)-'A')+10))
#define	get_byte_value(c1,c2)	((char2int(c1)<<HALF_BYTE_SIZE)+char2int(c2))

#define	FLAG_MASK	(1<<7)
#define	LENGTH_MASK	(0x0000007F)
#define	LINE_LENGTH	80

void	write_data(vector<int>& src,const int& from,const int& size,
				   const int& repeats,vector<int>& out)
{
	for(int i=0;i<repeats;i++)
	{
		for(int j=0;j<size;j++)
		{
			out.push_back(src[from+j]);
		}
	}
}

void	decode_data(vector<int>& d,vector<int>& out)
{
	for(int i=0;i<d.size();i++)
	{
		int&	h = d[i];
		
		if( h&FLAG_MASK )
		{
			int	num_of_repeats;
			
			num_of_repeats = (h&LENGTH_MASK)+3;
			write_data(d,i+1,1,num_of_repeats,out);
			i++;
		}
		else
		{
			int	length;
			
			length = (h&LENGTH_MASK)+1;
			write_data(d,i+1,length,1,out);
			i += length;
		}
	}
}

void	parse_input(string& str,vector<int>& data)
{
	for(int i=0;i<str.length();i+=2)
	{
		char&	c1 = str[i+0];
		char&	c2 = str[i+1];
		
		data.push_back(get_byte_value(c1,c2));
	}
}

void	read_input_data(string& data,const int& input_size)
{
	for(int read_size=0;read_size<input_size;)
	{
		string	str;
		
		cin>>str;
		data += str;
		read_size += str.length()/2;	
	}
}

void	print_raw_data(vector<int>& data)
{
	for(int i=0;i<data.size();)
	{
		for(int j=0;i<data.size()&&j<LINE_LENGTH;i++,j+=2)
		{
			printf("%02X",data[i]);
		}
		puts("");
	}
}

int		main(void)
{
	int	P;
	
	cin>>P;
	
	for(int p=1;p<=P;p++)
	{
		int				B;
		string			data;
		vector<int>		tmp,out;
		
		cin>>B;
		read_input_data(data,B);
		
		parse_input(data,tmp);
		decode_data(tmp,out);
		
		cout<<out.size()<<'\n';
		print_raw_data(out);
	}
	
	return	0;
}

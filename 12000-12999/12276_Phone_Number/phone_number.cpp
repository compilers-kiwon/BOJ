#include	<iostream>
#include	<vector>
#include	<string>

using namespace	std;

#define	MAX_SIZE	10
#define	MAX_LEN		100

#define	char2int(c)	((int)((c)-'0'))

const string	successive[MAX_SIZE+1] = {"",""," double"," triple"," quadruple",
									   	  " quintuple"," sextuple"," septuple",
									      " octuple"," nonuple"," decuple"};

const string 	num[MAX_SIZE] = {"zero","one","two","three","four",
								 "five","six","seven","eight","nine"};
								 
void	read_number(string& number,vector<int>& format)
{
	int	number_ptr;
	
	number_ptr = 0;
	
	for(int i=0;i<format.size();i++)
	{
		int 	cnt;
		char	prev;
		
		cnt = 1;
		prev = number[number_ptr];
		
		for(int j=1;j<format[i];j++)
		{
			char&	current = number[number_ptr+j];
			
			if( current == prev )
			{
				cnt++;
			}
			else
			{
				if( cnt > MAX_SIZE )
				{
					for(int k=1;k<=cnt;k++)
					{
						cout<<' '<<num[char2int(prev)];
					}
				}
				else
				{
					cout<<successive[cnt]<<' '<<num[char2int(prev)];
				}
				
				cnt = 1;
				prev = current;
			}
		}
		
		if( cnt > MAX_SIZE )
		{
			for(int k=1;k<=cnt;k++)
			{
				cout<<' '<<num[char2int(prev)];
			}
		}
		else
		{
			cout<<successive[cnt]<<' '<<num[char2int(prev)];
		}
		
		number_ptr += format[i];
	}
	cout<<'\n';
}

void	get_format(string& str,vector<int>& format)
{
	int	n;
	
	n = 0;
	str.push_back('-');
	
	for(int i=0;i<str.length();i++)
	{
		char&	c = str[i];
		
		if( c == '-' )
		{
			format.push_back(n);
			n = 0;
		}
		else
		{
			n = n*10+char2int(c);
		}
	}
}

int		main(void)
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	
	int	T;
	
	cin>>T;
	
	for(int t=1;t<=T;t++)
	{
		string		s1,s2;
		vector<int>	format;
		
		cin>>s1>>s2;
		cout<<"Case #"<<t<<":";
		
		get_format(s2,format);
		read_number(s1,format);
	}
	
	return	0;
}

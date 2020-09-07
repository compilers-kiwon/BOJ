#include	<iostream>
#include	<string>
#include	<vector>

using namespace	std;

#define	LINE_LEN	80

int	main(void)
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	
	vector<string>	out;
	string			buf;
	
	out.push_back(buf);
	
	while(1)
	{
		string&	cur = out.back();
		string	word;
		
		cin>>word;
		
		if( word == "" )
		{
			break;
		}
		
		if( word == "<br>" )
		{
			string	new_buf;
			
			out.push_back(new_buf);
			continue;
		}
		else if( word == "<hr>" )
		{
			if( cur.length() == 0 )
			{
				cur.resize(LINE_LEN,'-');
				
				string	new_buf;
			
				out.push_back(new_buf);
				continue;
			}
			else
			{
				string	hr,new_buf;
				
				hr.resize(LINE_LEN,'-');
				out.push_back(hr);
				out.push_back(new_buf);
				
				continue;
			}
		}
		else
		{
			int	len_of_cur_buf;
			
			len_of_cur_buf = cur.length();
			
			if( len_of_cur_buf+1+word.length() <= LINE_LEN )
			{
				if( len_of_cur_buf != 0 )
				{
					cur.push_back(' ');
				}
				cur += word;
			}
			else
			{
				out.push_back(word);
			}
		}
	}
	
	for(int i=0;i<out.size();i++)
	{
		cout<<out[i]<<'\n';
	}
	
	return	0;
}

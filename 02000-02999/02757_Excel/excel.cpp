#include	<iostream>
#include	<string>
#include	<vector>

using namespace	std;

void	parse_row_col(string& str,int* row,int* col)
{
	str.insert(1," ");
	
	for(int i=2;;i++)
	{
		if( str[i] == 'C' )
		{
			str.insert(i+1," ");
			str.insert(i," ");
			break;
		}
	}
	
	char	c;
		
	sscanf(str.c_str(),"%c %d %c %d",&c,row,&c,col);
}

void	convert_col(string& str,int& col,string& table)
{
	if( col == 0 )
	{
		return;
	}
	
	if( col%26 == 0 )
	{
		str.push_back('Z');
		col -= 26;
	}
	else
	{
		int	tmp;
		
		tmp = col-(col/26)*26;
		str.push_back(table[tmp]);
		col -= tmp;
	}
	
	col /= 26;
	convert_col(str,col,table);
}

int		main(void)
{
	string	table = "ZABCDEFGHIJKLMNOPQRSTUVWXYZ";
	
	while(1)
	{
		string		str,col_number;
		int			row,col,s;
		vector<int>	n;
		
		cin>>str;
		parse_row_col(str,&row,&col);
		
		if( row == 0 && col == 0 )
		{
			break;
		}
		
		convert_col(col_number,col,table);
		
		for(int h=0,t=col_number.length()-1;h<t;h++,t--)
		{
			swap(col_number[h],col_number[t]);
		}
				
		cout<<col_number<<row<<'\n';
	}
	
	return	0;
}

#include	<iostream>
#include	<string>
#include	<vector>

using namespace	std;

string						roman_number;
int							roman_number_length;
vector< pair<int,string> >	number_roman_table;

void	init_number_roman_table(void)
{
	number_roman_table.push_back(make_pair(1000,"M"));
	number_roman_table.push_back(make_pair(900,"CM"));
	number_roman_table.push_back(make_pair(500,"D"));
	number_roman_table.push_back(make_pair(400,"CD"));
	number_roman_table.push_back(make_pair(100,"C"));
	number_roman_table.push_back(make_pair(90,"XC"));
	number_roman_table.push_back(make_pair(50,"L"));
	number_roman_table.push_back(make_pair(40,"XL"));
	number_roman_table.push_back(make_pair(10,"X"));
	number_roman_table.push_back(make_pair(9,"IX"));
	number_roman_table.push_back(make_pair(5,"V"));
	number_roman_table.push_back(make_pair(4,"IV"));
	number_roman_table.push_back(make_pair(1,"I"));
}

char	get_char(int index)
{
	char	c;
	
	if( index == roman_number_length )
	{
		c = '\0';
	}
	else
	{
		c = roman_number[index];
	}
	return	c;
}

int		get_number(void)
{
	int		result = 0;
	char	c,d;
	
	for(int i=0;(c=get_char(i))!='\0';i++)
	{
		switch(c)
		{
			case	'M':
				result = result+1000;
				break;
			case	'D':
				result = result+500;
				break;
			case	'C':
				d = get_char(i+1);
				
				if(  d == 'D' )
				{
					result = result+400;
					i++;
				}
				else if( d == 'M' )
				{
					result = result+900;
					i++;
				}
				else
				{
					result = result+100;
				}
				break;
			case	'L':
				result = result+50;
				break;
			case	'X':
				d = get_char(i+1);
				
				if(  d == 'L' )
				{
					result = result+40;
					i++;
				}
				else if( d == 'C' )
				{
					result = result+90;
					i++;
				}
				else
				{
					result = result+10;
				}
				break;
			case	'V':
				result = result+5;
				break;
			case	'I':
				d = get_char(i+1);
				
				if(  d == 'V' )
				{
					result = result+4;
					i++;
				}
				else if( d == 'X' )
				{
					result = result+9;
					i++;
				}
				else
				{
					result = result+1;
				}
				break;
			default:
				cout<<"Wrong Input: "<<c<<endl;
				break;
		}
	}
	return	result;
}

void	get_roman_number(int n,string& out)
{
	init_number_roman_table();
	
	vector< pair<int,string> >::iterator	vi;
	
	for(vi=number_roman_table.begin();vi!=number_roman_table.end();)
	{
		int 	current_number,tmp;
		string	current_roman;
		
		current_number = vi->first;
		current_roman = vi->second;
		
		if( n == current_number )
		{
			out = out+current_roman;
			break;
		}
		else if( n > current_number )
		{
			out = out+current_roman;
			n = n-current_number;
		}
		else
		{
			vi++;
		}
	}
}

int		main(void)
{	
	int		result = 0;
	string	sum;
	
	cin>>roman_number;
	roman_number_length = roman_number.length();
	
	result = result+get_number();
	
	cin>>roman_number;
	roman_number_length = roman_number.length();
	
	result = result+get_number();
	
	cout<<result<<endl;
	
	get_roman_number(result,sum);
		
	cout<<sum<<endl;
	
	return	0;
}


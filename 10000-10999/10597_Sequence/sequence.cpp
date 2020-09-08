#include	<iostream>
#include	<map>
#include	<string>
#include	<vector>

using namespace std;

#define	MAX_NUM	50

typedef	unsigned int	uint32;

string				str;
map<uint32,uint32>	len;
uint32				N;

void	init_len(void)
{
	uint32	i,cnt;
	
	for(i=1;i<=9;i++)
	{
		len[i] = i;
	}
	
	for(cnt=10,i=11;i<=91;i=i+2,cnt++)
	{
		len[i] = cnt;
	}
	
	//map<uint32,uint32>::iterator	iter;
	//
	//for(iter=len.begin();iter!=len.end();iter++)
	//{
	//	cout<<"N="<<iter->second<<"::Len="<<iter->first<<endl;
	//}
}

bool	find_seq(vector<bool>& table,uint32 pos)
{
	char	first,second;
	uint32	n,next_pos;
	
	first = str[pos];
	n = (uint32)first-(uint32)'0';
	next_pos = pos+1;
	
	if( table[n] == false )
	{
		table[n] = true;
		
		if( next_pos == str.length() )
		{
			return	true;
		}
		
		str.insert(next_pos," ");
		
		if( find_seq(table,next_pos+1) == true )
		{
			return	true;
		}
		
		str.erase(next_pos,1);
		table[n] = false;
	}
	
	if( pos+1 != str.length() )
	{
		second = str[pos+1];
		n = n*10+(uint32)second-(uint32)'0';
		next_pos = pos+2;
		
		if( n <= N && table[n] == false )
		{
			table[n] = true;
			
			if( next_pos == str.length() )
			{
				return	true;
			}
			
			str.insert(next_pos," ");
			
			if( find_seq(table,next_pos+1) == true )
			{
				return	true;
			}
			
			str.erase(next_pos,1);
			table[n] = false;
		}
	}
	return	false;
}
int		main(void)
{
	init_len();
	
	cin>>str;
	N = len[str.length()];
	
	vector<bool>	table(N+1,false);
	
	if( find_seq(table,0) == true )
	{
		cout<<str<<endl;
	}
	
	return	0;
}

#include	<iostream>
#include	<vector>
#include	<string>

using namespace	std;

#define	GET_SUM(ACC_TABLE,FROM,TO)	((ACC_TABLE)[(TO)]-(ACC_TABLE)[(FROM)-1])
#define	char2int(c)					((int)((c)-'0'))

void	init(string& t,vector<int>& acc)
{
	acc.push_back(0);
	
	for(int i=0;i<t.length();i++)
	{
		acc.push_back(acc.back()+char2int(t[i]));
	}
}

int		get_max_len_of_fortunate_ticket(vector<int>& acc,int len)
{
	int	i,j;
	
	for(i=len/2;i>0;i--)
	{
		bool	result;
		
		for(result=false,j=1;j<=len-i*2+1&&result==false;j++)
		{
			if( GET_SUM(acc,j,j+i-1) == GET_SUM(acc,j+i,j+i+i-1) )
			{
				result = true;
			}
		}
		
		if( result == true )
		{
			break;
		}
	}
	
	return	i*2;
}

int		main(void)
{
	string		ticket;
	vector<int>	acc;
	
	cin>>ticket;
	
	init(ticket,acc);
	cout<<get_max_len_of_fortunate_ticket(acc,ticket.length())<<'\n';
	
	return	0;
}

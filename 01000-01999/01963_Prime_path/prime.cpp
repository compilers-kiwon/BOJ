#include	<iostream>
#include	<queue>
#include	<vector>
#include	<map>
#include	<string>

using namespace	std;

#define	UNKNOWN		0
#define	PRIME		1
#define	NOT_PRIME	2

#define	MAX_NUM		10000

#define	char2int(c)	((int)((c)-'0'))

typedef	struct	_PRIME_INFO	Prime;
struct	_PRIME_INFO
{
	string	number;
	int		num_of_change;
};

void	build_prime_table(map<string,bool>& table)
{
	vector<int>	int_table(MAX_NUM,true);
	
	for(int i=2;i<MAX_NUM;i++)
	{
		if( int_table[i] == true )
		{
			for(int j=i+i;j<MAX_NUM;j+=i)
			{
				int_table[j] = false;
			}
		}
	}
	
	char	d1,d2,d3,d4;
	
	for(d1='1';d1<='9';d1++)
	{
		for(d2='0';d2<='9';d2++)
		{
			for(d3='0';d3<='9';d3++)
			{
				for(d4='0';d4<='9';d4++)
				{
					int		n;
					
					n = char2int(d1)*1000+char2int(d2)*100+char2int(d3)*10+char2int(d4);
					
					if( int_table[n] == true )
					{
						string	number;
						
						number.push_back(d1);
						number.push_back(d2);
						number.push_back(d3);
						number.push_back(d4);
						
						table[number] = true;
					}
				}
			}
		}
	}
}

int		get_min_prime_path(string& from,string& to,map<string,bool>& prime_table)
{
	queue<Prime>		prime_q;
	map<string,bool>	visited;
	
	Prime	p;
	int		min_num_of_change;
	
	p.number = from;
	p.num_of_change = 0;
	visited[from] = true;
	prime_q.push(p);
	
	min_num_of_change = 0x7FFFFFFF;
	
	while( prime_q.size() != 0 )
	{
		string	current_number;
		int		current_num_of_change;
		
		current_number = prime_q.front().number;
		current_num_of_change = prime_q.front().num_of_change;
		prime_q.pop();
		
		if( current_number == to )
		{
			min_num_of_change = current_num_of_change;
			break;
		}
		
		int	next_num_of_change = current_num_of_change+1;
		
		for(char c='1';c<='9';c++)
		{
			if( c == current_number[0] )
			{
				continue;
			}
			
			string	next_num = current_number;
			
			next_num[0] = c;
			
			if( prime_table[next_num] == true && visited[next_num] == false )
			{
				p.number = next_num;
				p.num_of_change = next_num_of_change;
				visited[next_num] = true;
				prime_q.push(p);
			}
		}
		
		for(int i=1;i<=3;i++)
		{
			for(char c='0';c<='9';c++)
			{
				if( c == current_number[i] )
				{
					continue;
				}
				
				string	next_num = current_number;
				
				next_num[i] = c;
				
				if( prime_table[next_num] == true && visited[next_num] == false )
				{
					p.number = next_num;
					p.num_of_change = next_num_of_change;
					visited[next_num] = true;
					prime_q.push(p);
				}
			}
		}
	}
	
	return	min_num_of_change;
}

int		main(void)
{
	map<string,bool>	prime_table;
	
	build_prime_table(prime_table);
	
	int	T;
	
	cin>>T;
	
	while(T>0)
	{
		string		from,to;
		int			answer;
		
		cin>>from>>to;
		
		answer = get_min_prime_path(from,to,prime_table);
		
		if( answer == 0x7FFFFFFF )
		{
			cout<<"Impossible\n";
		}
		else
		{
			cout<<answer<<'\n';
		}
		
		T--;
	}
	return	0;
}

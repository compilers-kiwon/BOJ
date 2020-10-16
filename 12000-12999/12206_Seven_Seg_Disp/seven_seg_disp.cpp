#include	<iostream>
#include	<string>

using namespace	std;

#define	MAX_SIZE	100
#define	MAX_LEN		7
#define	MAX_NUM		(9+1)
#define	NONE		-1

#define	next_num(n)	(((n)+(MAX_NUM-1))%MAX_NUM)

#define	ON	'1'
#define	OFF	'0'

#define	TRUE	1
#define	FALSE	0
#define	UNKNOWN	-1

const string	led[MAX_NUM] = {"1111110","0110000","1101101",
						 		"1111001","0110011","1011011",
						 		"1011111","1110000","11111111",
						 		"1111011"};

int		N,cnt,last_number;
bool	possible_state[MAX_LEN];
string	record[MAX_SIZE];

void	find_number(int idx,int expected_num,bool* available)
{
	if( idx == N )
	{
		if( cnt != 0 )
		{
			string	n1,n2;
			
			for(int i=0;i<MAX_LEN;i++)
			{
				if( possible_state[i] == false )
				{
					n1.push_back(OFF);
				}
				else
				{
					n1.push_back(led[last_number][i]);
				}
				
				if( available[i] == false )
				{
					n2.push_back(OFF);
				}
				else
				{
					n2.push_back(led[expected_num][i]);
				}
			}
			
			if( n1 == n2 )
			{
				return;
			}
		}
		
		cnt++;
		last_number = expected_num;
		
		for(int i=0;i<MAX_LEN;i++)
		{
			possible_state[i] = available[i];
		}
		
		return;
	}
	
	bool	possible;
	
	possible = true;
	
	for(int i=0;i<MAX_LEN;i++)
	{
		if( record[idx][i] == ON )
		{
			if( available[i]==false || led[expected_num][i]==OFF )
			{
				possible = false;
				break;
			}
		}
		
		if( record[idx][i] == OFF )
		{
			if( available[i]==true && led[expected_num][i]==ON )
			{
				possible = false;
				break;
			}
		}
	}
	
	if( possible == true )
	{
		find_number(idx+1,next_num(expected_num),available);
	}
}

void	get_state(int idx,bool* available)
{
	if( idx == MAX_LEN )
	{
		for(int n=0;n<MAX_NUM;n++)
		{
			find_number(0,n,available);
		}
		
		return;
	}
	
	available[idx] = true;
	get_state(idx+1,available);

	available[idx] = false;
	get_state(idx+1,available);
}

void	input(void)
{
	cin>>N;
	cnt = 0;
	
	for(int i=0;i<N;i++)
	{
		cin>>record[i];
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
		bool	available[MAX_LEN];
		
		input();
		get_state(0,available);
		
		cout<<"Case #"<<t<<": ";
		
		if( cnt == 1 )
		{
			for(int i=0;i<MAX_LEN;i++)
			{
				if( possible_state[i] == false )
				{
					cout<<OFF;
				}
				else
				{
					cout<<led[last_number][i];
				}
			}
			
			cout<<'\n';
		}
		else
		{
			cout<<"ERROR!\n";
		}
	}
	
	return	0;
}

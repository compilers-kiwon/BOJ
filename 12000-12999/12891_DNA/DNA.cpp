#include	<iostream>
#include	<string>

using namespace	std;

#define	MAX_SIZE			(1000000+1)
#define	NUM_OF_BASE			4
#define	GET_BASE_INDEX(C)	((C)=='A'?0:(C)=='C'?1:(C)=='G'?2:3)

int		S,P;
int		base_table[NUM_OF_BASE][MAX_SIZE];
int		required_num_of_base[NUM_OF_BASE];
string	DNA;

void	init(void)
{
	cin>>S>>P>>DNA;
	
	for(int i=0;i<NUM_OF_BASE;i++)
	{
		cin>>required_num_of_base[i];
	}
	
	DNA.insert(DNA.begin(),' ');
	
	for(int i=1;i<=S;i++)
	{
		for(int b=0;b<NUM_OF_BASE;b++)
		{
			base_table[b][i] = base_table[b][i-1];
		}
		
		base_table[GET_BASE_INDEX(DNA[i])][i]++;
	}
}

int		count_valid_password(void)
{
	int	cnt,i,j;
	
	for(cnt=0,i=0,j=P;j<=S;i++,j++)
	{
		bool	is_valid;
		int		b;
		
		for(is_valid=true,b=0;b<NUM_OF_BASE;b++)
		{
			if( required_num_of_base[b] > base_table[b][j]-base_table[b][i] )
			{
				is_valid = false;
				break;
			}
		}
		
		if( is_valid == true )
		{
			cnt++;
		}
	}
	
	return	cnt;
}

int		main(void)
{
	init();
	cout<<count_valid_password()<<'\n';
	
	return	0;
}

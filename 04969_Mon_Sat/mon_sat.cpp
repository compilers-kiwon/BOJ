#include	<iostream>
#include	<vector>

using namespace	std;

#define	MAX_SIZE	300000

bool	is_MoSa_Num[MAX_SIZE+1];
bool	is_MoSa_Prime[MAX_SIZE+1];

vector<int>	MoSa_Num,MoSa_Prime;

void	build_table(void)
{
	is_MoSa_Num[1] = true;
	MoSa_Num.push_back(1);
	
	for(int i=7;i<=MAX_SIZE;i+=7)
	{
		is_MoSa_Num[i-1] = is_MoSa_Num[i+1] = true;
		
		MoSa_Num.push_back(i-1);
		MoSa_Num.push_back(i+1);
	}
	
	fill(&is_MoSa_Prime[2],&is_MoSa_Prime[MAX_SIZE+1],true);
	
	for(int i=1;i<MoSa_Num.size();i++)
	{
		int&	n = MoSa_Num[i];
		
		if( is_MoSa_Prime[n] == true )
		{
			MoSa_Prime.push_back(n);
			
			for(int j=1;j<MoSa_Num.size();j++)
			{
				int	m;
				
				m = n*MoSa_Num[j];
				
				if( m > MAX_SIZE )
				{
					break;
				}
				
				if( is_MoSa_Num[m] == true )
				{
					is_MoSa_Prime[m] = false;
				}
			}
		}
	}
}

int		main(void)
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	
	build_table();
	
	for(;;)
	{
		int			n;
		
		cin>>n;
		
		if( n == 1 )
		{
			break;
		}
		
		cout<<n<<":";
		
		for(int i=0;i<MoSa_Prime.size();i++)
		{
			if( n%MoSa_Prime[i] == 0 )
			{
				cout<<' '<<MoSa_Prime[i];
			}
		}
		cout<<'\n';
	}
	
	return	0;
}

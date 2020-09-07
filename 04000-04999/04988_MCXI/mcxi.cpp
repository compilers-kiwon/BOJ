#include	<iostream>
#include	<map>
#include	<string>

using namespace	std;

#define	MAX_NUM		9999

#define	THOUSAND	0
#define	HUNDRED		1
#define	TEN			2
#define	ONE			3
#define	MAX_SIZE	4

const string	int2char = "0123456789";
const string	MCXI_CHAR = "mcxi";
const int		value[MAX_SIZE] = {1000,100,10,1};

#define	get_number(n,cnt,idx)	{((cnt)[(idx)]=(n)/value[(idx)]);(n)=(n)%value[(idx)];}

void	build_table(string* int2mcxi,map<string,int>& mcxi2int)
{
	for(int n=1;n<=MAX_NUM;n++)
	{
		int		tmp,num[MAX_SIZE];
		string	str;
		
		tmp = n;
		
		get_number(tmp,num,THOUSAND);
		get_number(tmp,num,HUNDRED);
		get_number(tmp,num,TEN);
		get_number(tmp,num,ONE);
		
		for(int i=THOUSAND;i<=ONE;i++)
		{
			if( num[i] <= 1 )
			{
				if( num[i] == 1 )
				{
					str.push_back(MCXI_CHAR[i]);
				}
			}
			else
			{
				str.push_back(int2char[num[i]]);
				str.push_back(MCXI_CHAR[i]);
			}
		}
		
		int2mcxi[n] = str;
		mcxi2int[str] = n;
	}
}

int		main(void)
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	
	string			int2mcxi[MAX_NUM+1];
	map<string,int>	mcxi2int;
	
	build_table(int2mcxi,mcxi2int);
	
	int	n;
	
	cin>>n;
	
	for(int i=1;i<=n;i++)
	{
		string	str1,str2;
		
		cin>>str1>>str2;
		cout<<int2mcxi[mcxi2int[str1]+mcxi2int[str2]]<<'\n';
	}
	
	return	0;
}

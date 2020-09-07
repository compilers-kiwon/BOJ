#include	<iostream>
#include	<string>
#include	<cmath>

using namespace	std;

#define	MAX_MONTH	(100+1)
#define	MAX_SIZE	(100+1)
#define	int2char(i)	((char)((i)+(int)'0'))

void	to_currency_format(char* in,string& out)
{
	int	in_len;
	
	for(in_len=0;in[in_len]!='\0';in_len++);
	
	out.push_back(in[in_len-1]);
	out.push_back(in[in_len-2]);
	out.push_back(in[in_len-3]);
	
	for(int i=in_len-4,cnt=1;i>=0;i--,cnt++)
	{
		if( cnt == 4 )
		{
			out.push_back(',');
			cnt = 1;
		}
		
		out.push_back(in[i]);		
	}
	
	for(int h=0,t=out.length()-1;h<t;h++,t--)
	{
		swap(out[h],out[t]);
	}
}

int		main(void)
{
	for(;;)
	{
		string	out;
		int		N;
		double	cost[MAX_MONTH];
		char	buf[MAX_SIZE];
		
		cin>>cost[1];
		
		if( cost[1] == -1.0 )
		{
			break;
		}
		
		cin>>cost[2]>>cost[3]>>N;
		
		for(int i=4;i<=N;i++)
		{
			cost[i] = round(cost[i-3]*cost[i-2]/cost[i-1]*100.0)/100.0;
		}
		
		sprintf(buf,"%.02f",cost[N]);
		to_currency_format(buf,out);
		
		cout<<"Month "<<N<<" cost: $"<<out<<'\n';
	}
	
	return	0;
}

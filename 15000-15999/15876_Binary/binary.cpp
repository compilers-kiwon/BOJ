#include	<iostream>
#include	<string>

using namespace	std;

#define	MAX_LEN		500
#define	int2char(i)	(((i)==0)?'0':'1')

void	int2bin(int n,string& b)
{
	for(;n>0;n/=2)
	{
		b.push_back(int2char(n%2));
	}
	
	for(int h=0,t=b.length()-1;h<t;h++,t--)
	{
		swap(b[h],b[t]);
	}
}

int		main(void)
{
	string	bin;
	int		n,k,i;
	bool	flag;
	
	cin>>n>>k;
	bin.push_back('0');
	
	for(i=1,flag=true;flag!=false;i++)
	{
		string	tmp;
		
		int2bin(i,tmp);
		
		if( bin.length()+tmp.length() > MAX_LEN )
		{
			flag = false;
			
			for(int j=0;bin.length()<=MAX_LEN;j++)
			{
				bin.push_back(tmp[j]);
			}
		}
		else
		{
			bin += tmp;
		}
	}
	
	for(int i=0;i<5;i++)
	{
		cout<<bin[i*n+k-1]<<' ';
	}
	cout<<'\n';
	
	return	0;
}

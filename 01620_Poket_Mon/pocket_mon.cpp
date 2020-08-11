#include	<iostream>
#include	<string>
#include	<vector>
#include	<map>

using namespace	std;

#define	char2int(c)	((int)((c)-'0'))
#define	MAX_LEN		20
#define	MAX_SIZE	(100000+1)

vector<string>	index_dic(MAX_SIZE);
map<string,int>	name_dic;
char			buf[MAX_LEN+1];

int		string2int(string& str)
{
	int	value,i;
	
	for(i=value=0;i<str.length();i++)
	{
		value = value*10+char2int(str[i]);
	}
	return	value;
}

void	input_pocket_mon_list(int& num_of_pocket_mon,int& num_of_query)
{
	scanf("%d %d",&num_of_pocket_mon,&num_of_query);
	
	for(int i=1;i<=num_of_pocket_mon;i++)
	{
		scanf("%s",buf);
		
		string	name=buf;
		
		index_dic[i] = name;
		name_dic[name] = i;
	}
}

int		main(void)
{
	int	N,M;
	
	input_pocket_mon_list(N,M);
	
	for(int i=1;i<=M;i++)
	{
		scanf("%s",buf);
		
		string	q = buf;
		
		if( q[0]>='A' && q[0]<='Z' )
		{
			printf("%d\n",name_dic[q]);
		}
		else
		{
			//cout<<index_dic[string2int(q)]<<'\n';
			puts(index_dic[string2int(q)].c_str());
		}
	}
	
	return	0;
}

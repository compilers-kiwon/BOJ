#include	<iostream>
#include	<string>
#include	<map>

using namespace	std;

#define	MAX_SIZE		0x100
#define	get_index(c)	((int)())

typedef	long long int	int64;

map<string,int64>	tree[MAX_SIZE];

int	main(void)
{
	int64	total;
	
	for(total=0;;total++)
	{
		string	t;
		
		getline(cin,t);
		
		if( t.empty() )
		{
			break;
		}
		
		tree[t[0]][t]++;
	}
	
	for(int i=0;i<MAX_SIZE;i++)
	{
		map<string,int64>::iterator	it;
		
		for(it=tree[i].begin();it!=tree[i].end();it++)
		{
			int64	p;
			
			p = (it->second)*100000*100/total+5;
			printf("%s %d.%04d\n",it->first.c_str(),p/100000,(p%100000)/10);
		}
	}
	
	return	0;
}

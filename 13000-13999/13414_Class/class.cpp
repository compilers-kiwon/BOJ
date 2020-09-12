#include	<iostream>
#include	<map>
#include	<vector>

using namespace	std;

#define	MAX_NUM_OF_INPUT	(500000+1)

map<int,int>	order_of_sn;		// <sn,order>
vector<int>		sn_list_as_order(MAX_NUM_OF_INPUT,-1);

int	main(void)
{
	int	K,L;
	
	scanf("%d %d",&K,&L);
	
	for(int i=1;i<=L;i++)
	{
		int	sn,prev_order;
		
		scanf("%d",&sn);
		
		prev_order = order_of_sn[sn];
		
		order_of_sn[sn] = i;
		sn_list_as_order[i] = sn;
		sn_list_as_order[prev_order] = -1;
	}
	
	for(int i=1,cnt=0;i<=L&&cnt<K;i++)
	{
		if( sn_list_as_order[i] != -1 )
		{
			printf("%08d\n",sn_list_as_order[i]);
			cnt++;
		}
	}
	
	return	0;
}

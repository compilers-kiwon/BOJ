#include	<iostream>

using namespace	std;

#define	BBUN	0
#define	DEGI	1

#define	get_next(i,N)	(((i)+1)%(N))
#define	check_cnt()		{if(cnt[W]==T){break;}}
int	main(void)
{
	int	A,T,W,i,n;
	int	cnt[DEGI+1];
	
	cin>>A>>T>>W;
	cnt[BBUN] = cnt[DEGI] = 0;
	
	for(n=1,i=0;;n++)
	{
		// BBUN
		cnt[BBUN]++;
		check_cnt();
		i = get_next(i,A);
		
		// DEGI
		cnt[DEGI]++;
		check_cnt();
		i = get_next(i,A);
		
		// BBUN
		cnt[BBUN]++;
		check_cnt();
		i = get_next(i,A);
		
		// DEGI
		cnt[DEGI]++;
		check_cnt();
		i = get_next(i,A);
		
		bool	found = false;
		
		// BBUN BBUN ...
		for(int j=1;j<=n+1;j++)
		{
			cnt[BBUN]++;
			
			if( cnt[W] == T )
			{
				found = true;
				break;
			}
			
			i = get_next(i,A);
		}
		
		if( found == true )
		{
			break;
		}
		
		// DEGI DEGI ...
		for(int j=1;j<=n+1;j++)
		{
			cnt[DEGI]++;
			
			if( cnt[W] == T )
			{
				found = true;
				break;
			}
			
			i = get_next(i,A);
		}
		
		if( found == true )
		{
			break;
		}
	}
	
	cout<<i<<'\n';
	
	return	0;
}

#include	<iostream>
#include	<string>

using namespace	std;

#define	TARGET_WORD	"sheep"

int	count_word(void)
{
	int	cnt,m;
	
	cin>>m;
	cnt = 0;
	
	for(int i=1;i<=m;i++)
	{
		string	w;
		
		cin>>w;
		
		if( w == TARGET_WORD )
		{
			cnt++;
		}
	}
	
	return	cnt;
}

int	main(void)
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	
	int	n;
	
	cin>>n;
	
	for(int i=1;i<=n;i++)
	{
		cout<<"Case "<<i<<": This list contains "<<count_word()<<" sheep.\n\n";
	}
	
	return	0;
}

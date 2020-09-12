#include	<iostream>
#include	<string>
#include	<vector>

using namespace	std;

#define	MAX_SKILL	(1<<10)
#define	MAX_CLASS	9
#define	char2int(c)	((int)((c)-'0'))

int		get_skill(void)
{
	char	s[MAX_CLASS+1];
	int		skill;
	
	scanf("%s",s);
	skill = 0;
	
	for(int i=0;s[i]!='\0';i++)
	{
		skill |= 1<<char2int(s[i]);
	}
	
	return	skill;
}

int		main(void)
{
	for(int N;scanf("%d",&N)==1;)
	{
		int				cnt;
		vector<bool>	visited(MAX_SKILL,false);
		
		cnt = 0;
		
		for(int i=1;i<=N;i++)
		{
			int	skill;
			
			skill = get_skill();
			
			if( visited[skill] == false )
			{
				visited[skill] = true;
				cnt++;
			}
		}
		
		printf("%d\n",cnt);
	}
	
	return	0;
}

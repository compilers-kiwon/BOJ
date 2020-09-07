#include	<cstdio>
#include	<string>

using namespace	std;

#define	MAX_SIZE		(64+1)
#define	NOT_ARCHIVED	' '

char	screen[MAX_SIZE][MAX_SIZE+1];

string	archive(int x,int y,int len)
{
	string	result;
	
	if( len == 1 )
	{
		result += screen[y][x];
		return result;
	}
	
	int		next_len = len/2;
	string	t1,t2,t3,t4;
	
	t1 = archive(x,y,next_len);
	t2 = archive(x+next_len,y,next_len);
	t3 = archive(x,y+next_len,next_len);
	t4 = archive(x+next_len,y+next_len,next_len);
	
	if( t1 == t2 && t2 == t3 && t3 == t4 && (t4=="0" || t4=="1") )
	{
		result.insert(0,t1);
	}
	else
	{
		result = "("+t1+t2+t3+t4+")";
	}
	return	result;
}

int		main(void)
{
	int	N;
	
	scanf("%d",&N);
	
	for(int i=1;i<=N;i++)
	{
		scanf("%s",&screen[i][1]);
	}
	
	string	s = archive(1,1,N);
	
	printf("%s\n",s.c_str());
	
	return	0;
}

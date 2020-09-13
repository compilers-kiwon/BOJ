#include	<iostream>
#include	<string>

using namespace	std;

#define	GRID_ROW_SIZE		5
#define	GRID_COL_SIZE		3
#define	MAX_NUM_OF_LETTERS	5

#define	GET_INDEX(C)	((int)((C)-'A'))

const string	letter[MAX_NUM_OF_LETTERS] =
{
	"****.*****.**.*",
	"****.*****.****",
	"****..*..*..***",
	"****.**.**.****",
	"****..****..***"
};

int	main(void)
{
	int		N;
	string	S,outbuf;
	
	cin>>N>>S;
	
	for(int i=0;i<GRID_ROW_SIZE;i++)
	{
		for(int j=0;j<S.length();j++)
		{
			for(int k=0;k<GRID_COL_SIZE;k++)
			{
				char	c;
				
				c = letter[GET_INDEX(S[j])][i*GRID_COL_SIZE+k];
				outbuf.push_back(c);
			}
		}
		outbuf.push_back('\n');
	}
	
	cout<<outbuf;
	
	return	0;
}

#include	<iostream>
#include	<string>
#include	<vector>
#include	<cmath>

using namespace	std;

#define	NUM_OF_ALPHABET	26
#define	BUF_SIZE		100

int	main(void)
{
	int	N;
	
	cin>>N;getchar();
	
	for(int j=1;j<=N;j++)
	{
		char		str1[BUF_SIZE+1],str2[BUF_SIZE+1];
		vector<int>	word(0x100,0);
		int			sum;
		
		fgets(str1,BUF_SIZE,stdin);
		fgets(str2,BUF_SIZE,stdin);
		
		for(int i=0;str1[i]!='\n';i++)
		{
			word[str1[i]]++;
		}
		
		for(int i=0;str2[i]!='\n';i++)
		{
			word[str2[i]]--;
		}
		
		sum = 0;
		
		for(char i='a';i<='z';i++)
		{
			sum += abs(word[i]);
		}
		
		printf("Case #%d: %d\n",j,sum);
	}
	
	return	0;
}

#include	<iostream>
#include	<string>
#include	<vector>

using namespace	std;

#define	MAX_LEN			2000
#define	GET_INDEX(c)	((int)(c-'A'))

vector<int>	table[2*MAX_LEN];
int			stroke_count[26] = {3, 2, 1, 2, 3, 3, 2, 3, 3, 2, 2, 1, 2, 2, 1, 2, 2, 2, 1, 2, 1, 1, 1, 2, 2, 1};

int	main(void)
{
	string	A,B;
	int		i,level;
	
	cin>>A>>B;
	
	for(i=0;i<A.length();i++)
	{
		table[A.length()*2].push_back(stroke_count[GET_INDEX(A[i])]);
		table[A.length()*2].push_back(stroke_count[GET_INDEX(B[i])]);
	}
	
	for(level=A.length()*2;level>2;level--)
	{
		for(int i=0;i<level-1;i++)
		{
			int	s1,s2;
			
			s1 = table[level][i];
			s2 = table[level][i+1];
			
			table[level-1].push_back((s1+s2)%10);
		}
	}
	cout<<table[2][0]<<table[2][1]<<endl;
	
	return	0;
}

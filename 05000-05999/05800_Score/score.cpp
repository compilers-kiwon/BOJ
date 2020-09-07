#include	<iostream>
#include	<vector>
#include	<algorithm>

using namespace	std;

int	main(void)
{
	int	K;
	
	cin>>K;
	
	for(int class_no=1;class_no<=K;class_no++)
	{
		int	N,max_gap;
		vector<int>	score;
		
		cin>>N;
				
		for(int i=1;i<=N;i++)
		{
			int	s;
			
			cin>>s;
			score.push_back(s);
		}
		
		sort(score.begin(),score.end());
		max_gap = 0;
		
		for(int i=1;i<score.size();i++)
		{
			max_gap = max(max_gap,score[i]-score[i-1]);
		}
		
		printf("Class %d\n",class_no);
		printf("Max %d, Min %d, Lagest gap %d\n",score[score.size()-1],score[0],max_gap);
	}
	
	return	0;
}

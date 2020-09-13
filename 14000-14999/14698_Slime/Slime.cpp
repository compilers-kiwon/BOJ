#include	<cstdio>
#include	<queue>
#include	<vector>

using namespace std;

typedef	long long	int64;

#define	MOD(n)	((n)%1000000007)

int	main(void)
{
	int	T;
	
	scanf("%d",&T);
	
	while(T>0)
	{
		priority_queue<int64>	slimes;
		int	N,i;
		
		scanf("%d",&N);
		
		for(i=1;i<=N;i++)
		{
			int64	slime;
			
			scanf("%lld",&slime);
			slimes.push(-slime);
		}
		
		int64			result = 1;
		vector<int64>	energy_vec;
		
		while( slimes.size() != 1 )
		{
			int64	s1,s2,energy;
			
			s1 = -(slimes.top());
			slimes.pop();
			s2 = -(slimes.top());
			slimes.pop();
			
			energy = s1*s2;
			energy_vec.push_back(MOD(energy));
			
			slimes.push(-energy);
		}
		
		for(int i=0;i<energy_vec.size();i++)
		{
			result = MOD(result*energy_vec[i]);
		}
		
		printf("%lld\n",result);
		
		T--;
	}
	return	0;
}

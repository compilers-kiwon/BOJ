#include	<iostream>
#include	<vector>
#include	<algorithm>

using namespace	std;

#define	MAX_SIZE	(8+1)
#define	BOUND		500

#define	SUCCESS	1
#define	FAIL	0

int	simulate(int num_of_days,int loss,int* weight,vector<int>& program)
{
	int	result,w;
	
	w = BOUND;
	result = SUCCESS;
	
	for(int i=0;i<num_of_days;i++)
	{
		w += weight[program[i]]-loss;
		
		if( w < BOUND )
		{
			result = FAIL;
			break;
		}
	}
	
	return	result;
}

int	main(void)
{
	int			N,K,A[MAX_SIZE];
	vector<int>	program;
	
	cin>>N>>K;
	
	for(int i=1;i<=N;i++)
	{
		cin>>A[i];
		program.push_back(i);
	}
	
	int	cnt;
	
	cnt = 0;
	
	do{
		cnt += simulate(N,K,A,program);
	}while(next_permutation(program.begin(),program.end()));
	
	cout<<cnt<<'\n';
	
	return	0;
}

#include	<iostream>
#include	<queue>
#include	<map>

using namespace std;

#define	NONE	0

typedef	unsigned long long	uint64;
typedef	pair<uint64, int>	State;

int	main(void)
{
	uint64					A, B;
	int						ret;
	map<uint64, int>		dp;
	priority_queue<State>	pq;

	cin >> A >> B;
	ret = -1;

	dp[A] = 1;
	pq.push(make_pair(A,1));

	for (;!pq.empty();)
	{
		uint64	n;
		int		m;

		n = pq.top().first;
		m = pq.top().second;

		pq.pop();
		
		if (n == B)
		{
			ret = m;
			break;
		}

		if (n * 2 <= B && (dp[n * 2] == NONE || m + 1 < dp[n * 2]))
		{
			pq.push(make_pair(n * 2, m + 1));
			dp[n * 2] = m + 1;
		}

		if (n*10 + 1 <= B && (dp[n*10 + 1] == NONE || m + 1 < dp[n*10 + 1]))
		{
			pq.push(make_pair(n*10 + 1, m + 1));
			dp[n*10 + 1] = m + 1;
		}
	}
	
	cout << ret << '\n';

	return	0;
}
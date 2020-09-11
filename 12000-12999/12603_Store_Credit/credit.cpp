#include	<iostream>

using namespace std;

#define	MAX_SIZE	(100+1)

int	main(void)
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);

	int	N;

	cin >> N;

	for (int n = 1; n <= N; n++)
	{
		int	C, I, P[MAX_SIZE];
		int	max_credit, i1, i2;

		cin >> C >> I;

		for (int i = 1; i <= I; i++)
		{
			cin >> P[i];
		}

		max_credit = 0;

		for (int i = 1; i < I; i++)
		{
			for (int j = i + 1; j <= I; j++)
			{
				if (P[i] + P[j] <= C && P[i] + P[j] > max_credit)
				{
					i1 = i;
					i2 = j;
					max_credit = P[i] + P[j];
				}
			}
		}

		cout << "Case #" << n << ": " << i1 << ' ' << i2 << '\n';
	}

	return	0;
}
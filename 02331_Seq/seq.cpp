#include	<iostream>
#include	<vector>
#include	<cmath>

using namespace	std;

#define	MAX_NUM	(236196+1)

vector<bool>	table(MAX_NUM,false);
vector<int>		digit_sum;

int	get_digit_pow_sum(int A,int P)
{
	int	n,i;
	
	n = A;
	table[n] = true;
	digit_sum.push_back(n);
	
	while(1)
	{
		int	sum = 0;
		
		while(n>0)
		{
			sum += pow(n%10,P);
			n = n/10;
		}
		
		if( table[sum] == false )
		{
			table[sum] = true;
			digit_sum.push_back(sum);
			n = sum;
		}
		else
		{
			for(i=0;i<digit_sum.size();i++)
			{
				if( digit_sum[i] == sum )
				{
					break;
				}
				//else
				//{
				//	cout<<digit_sum[i]<<endl;
				//}
			}
			break;
		}
	}
	return	i;
}

int	main(void)
{
	int	A,P;
	
	cin>>A>>P;
	cout<<get_digit_pow_sum(A,P)<<endl;
	
	return	0;	
}	

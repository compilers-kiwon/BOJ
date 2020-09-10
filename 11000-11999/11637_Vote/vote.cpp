#include	<iostream>

using namespace	std;

int	main(void)
{
	int	T;
	
	cin>>T;
	
	while(T>0)
	{
		int	n,max_vote,cnt,sum,R;
		
		cin>>n;
		
		max_vote = cnt =sum = 0;
		
		for(int i=1;i<=n;i++)
		{
			int	v;
			
			cin>>v;
			
			sum += v;
			
			if( v > max_vote )
			{
				max_vote = v;
				cnt = 1;
				R = i;
			}
			else if( v == max_vote )
			{
				++cnt;
			}
		}
		
		if( cnt == 1 )
		{
			if( max_vote > sum/2 )
			{
				cout<<"majority winner ";
			}
			else
			{
				cout<<"minority winner ";
			}
			cout<<R<<endl;
		}
		else
		{
			cout<<"no winner\n";
		}
		T--;
	}
}

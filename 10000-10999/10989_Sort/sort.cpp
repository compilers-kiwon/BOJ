#include	<cstdio>
#include	<vector>

using namespace std;

#define	MAX_NUMBER	(10000+1)
#define	SWAP(a,b)	{int tmp = numbers[(a)];numbers[(a)]=numbers[(b)];numbers[(b)]=tmp;}

int			num_of_numbers[MAX_NUMBER];
vector<int>	numbers;

void	quick_sort(int from,int to)
{
    int	pivot;
	int	left,right;
    
	if( from >= to )
	{
		return;
	}
	
    pivot = numbers[from];
	left = from;
	right = to+1;
	
	while( 1 )
	{
		while( numbers[++left] < pivot );
		while( numbers[--right] > pivot );
		
		if( left >= right )
		{
			break;
		}
		
		SWAP(left,right);		
	}
	
	numbers[from] = numbers[right];
	numbers[right] = pivot;
	
	quick_sort(from,right-1);
	quick_sort(right+1,to);
}

int		main(void)
{
	int	N,i;
	
	scanf("%d",&N);
	
	for(i=1;i<=N;i++)
	{
		int	n;
		
		scanf("%d",&n);
		
		if( num_of_numbers[n] == 0 )
		{
			num_of_numbers[n] = 1;
			numbers.push_back(n);
		}
		else
		{
			++num_of_numbers[n];
		}
	}
	
	quick_sort(0,numbers.size()-1);
	
	for(i=0;i<numbers.size();i++)
	{
		for(int j=1;j<=num_of_numbers[numbers[i]];j++)
		{
			printf("%d\n",numbers[i]);
		}
	}
	
	return	0;
}

#include	<vector>
#include	<iostream>
#include	<queue>

#define	IN_RANGE(MIN,n,MAX)	((MIN)<=(n)&&(n)<=(MAX))

void	quick_sort(std::vector<int> &a, int index,int left,int right)
{
	std::cout<<"["<<left<<","<<right<<"]\n";
	if( right <= left )
	{
		return;
	}
	
	int	i,j,p;
	
	i = left;
	j = right+1;
	p = left;
	
	while( i < j )
	{
		do{i++;}while((a[p]>a[i])&&(i<=right));
		do{j--;}while((a[p]<a[j])&&(j>=left+1));
		
		if( i < j )
		{
			std::swap(a[i],a[j]);
		}
	}
	std::swap(a[left],a[j]);
	
	if( index == j )
	{
		return;
	}
	else
	{
		if( IN_RANGE(left,index,j-1) )
		{
			quick_sort(a,index,left,j-1);
		}
		else
		{
			quick_sort(a,index,j+1,right);
		}
	}
}

int kth(std::vector<int> &a, int k) {
	int	ans = 0;
	
	quick_sort(a,k-1,0,a.size()-1);
	ans = a[k-1];
	   
	return ans;
}

int	main(void)
{
	std::vector<int>	arr;
	int			N,k;
	
	std::cin>>N>>k;
	
	for(int i=1;i<=N;i++)
	{
		int	a;
		
		std::cin>>a;
		arr.push_back(a);
	}
	
	std::cout<<kth(arr,k)<<'\n';
	
	return	0;
}

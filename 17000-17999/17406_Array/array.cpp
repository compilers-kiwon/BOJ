#include	<iostream>
#include	<vector>
#include	<algorithm>

using namespace	std;

#define	MAX_SIZE		(50+1)
#define	MAX_OPERATION	(6+1)
#define	INF				0x7FFFFFFF

typedef	struct	_OPERATION_INFO	Operation;
struct	_OPERATION_INFO
{
	int	r,c,s;
};

int			N,M,K;
int			src[MAX_SIZE][MAX_SIZE];
int			array[MAX_SIZE][MAX_SIZE];
Operation	op[MAX_OPERATION];

void	print_array(void);

void	rotate(int op_index)
{
	int&	r = op[op_index].r;
	int&	c = op[op_index].c;
	int&	s = op[op_index].s;
	
	for(int d=1;d<=s;d++)
	{
		int	top,bottom,left,right,prev,tmp;
		
		top = r-d;
		bottom = r+d;
		left = c-d;
		right = c+d;
		
		prev=array[top][right];
		
		for(int col=right;col>left;col--)
		{
			array[top][col] = array[top][col-1];	
		}
		
		tmp = prev;
		prev=array[bottom][right];
		
		for(int row=bottom;row>top;row--)
		{
			array[row][right] = array[row-1][right];	
		}
		
		array[top+1][right] = tmp;
		tmp = prev;
		prev=array[bottom][left];
		
		for(int col=left;col<right;col++)
		{
			array[bottom][col] = array[bottom][col+1];	
		}
		
		array[bottom][right-1] = tmp;
		
		for(int row=top;row<bottom;row++)
		{
			array[row][left] = array[row+1][left];
		}
		
		array[bottom-1][left] = prev; 
	}
}

int		get_min_value(void)
{
	int	ret;
	
	ret = INF;
	
	for(int row=1;row<=N;row++)
	{
		int	sum;
		
		sum = 0;
		
		for(int col=1;col<=M;col++)
		{
			sum += array[row][col];
		}
		
		ret = min(ret,sum);
	}
	
	return	ret;
}

void	copy_array(void)
{
	for(int row=1;row<=N;row++)
	{
		for(int col=1;col<=M;col++)
		{
			array[row][col] = src[row][col];
		}
	}
}

void	input(vector<int>& op_order)
{
	cin>>N>>M>>K;
	
	for(int row=1;row<=N;row++)
	{
		for(int col=1;col<=M;col++)
		{
			cin>>src[row][col];
		}
	}
	
	for(int i=1;i<=K;i++)
	{
		cin>>op[i].r>>op[i].c>>op[i].s;
		op_order.push_back(i);
	}
}

void	print_array(void)
{
	cout<<"=======================================\n";
	
	for(int row=1;row<=N;row++)
	{
		for(int col=1;col<=M;col++)
		{
			cout<<array[row][col]<<' ';
		}
		cout<<'\n';
	}
	
	cout<<"=======================================\n";
}
int		main(void)
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	
	int			min_value;
	vector<int>	order;
	
	input(order);
	min_value = INF;
	
	do{
		copy_array();
		
		for(int i=0;i<K;i++)
		{
			rotate(order[i]);
		}
		
		min_value = min(min_value,get_min_value());
		
	}while(next_permutation(order.begin(),order.end()));
	
	cout<<min_value<<'\n';
	
	return	0;
}

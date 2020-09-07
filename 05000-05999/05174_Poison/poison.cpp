#include	<iostream>
#include	<string>

using namespace	std;

#define	MAX_NUM_OF_SUBSTANCES	50
#define	MAX_NUM_OF_PRODUCTS		20

int		num_of_substances,num_of_products;
int		cnt_of_substances[MAX_NUM_OF_SUBSTANCES];
string	victim,products[MAX_NUM_OF_PRODUCTS];

bool	is_victim(void)
{
	for(int i=0;i<num_of_substances;i++)
	{
		if( (victim[i]=='y'&&cnt_of_substances[i]==0) 
			|| (victim[i]=='n'&&cnt_of_substances[i]!=0) )
		{
			return	false;
		}
	}
	
	return	true;
}

void	dfs(int product_idx,
			int num_of_used_products,
			int& min_num_of_used_products)
{
	if( product_idx == num_of_products )
	{
		if( is_victim() == true )
		{
			min_num_of_used_products = 
				min(min_num_of_used_products,num_of_used_products);
		}
		
		return;
	}
	
	for(int i=0;i<num_of_substances;i++)
	{
		if( products[product_idx][i] == 'y' )
		{
			cnt_of_substances[i]++;
		}
	}
	
	dfs(product_idx+1,num_of_used_products+1,min_num_of_used_products);
	
	for(int i=0;i<num_of_substances;i++)
	{
		if( products[product_idx][i] == 'y' )
		{
			cnt_of_substances[i]--;
		}
	}
	
	dfs(product_idx+1,num_of_used_products,min_num_of_used_products);
}

void	input(void)
{
	cin>>num_of_substances>>num_of_products;
	
	for(int i=0;i<num_of_products;i++)
	{
		cin>>products[i];
	}
	
	cin>>victim;
	fill(&cnt_of_substances[0],&cnt_of_substances[num_of_substances],0);
}

int		main(void)
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	
	int	K;
	
	cin>>K;
	
	for(int k=1;k<=K;k++)
	{
		int	min_num_of_used_products;
		
		input();
		
		min_num_of_used_products = MAX_NUM_OF_PRODUCTS;
		dfs(0,0,min_num_of_used_products);
		
		cout<<"Data Set "<<k<<":\n";
		
		if( min_num_of_used_products == MAX_NUM_OF_PRODUCTS )
		{
			cout<<"Impossible.\n\n";
		}
		else
		{
			cout<<min_num_of_used_products<<"\n\n";
		}
	}
	
	return	0;
}

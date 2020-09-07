#include	<iostream>
#include	<vector>

using namespace	std;

#define	MAX_NUM_OF_OIL_FIELDS	(100+1)
#define	MAX_AMOUNT_OF_BUDGET	(100+1)

int		n,m,B;
double	oil_table[MAX_NUM_OF_OIL_FIELDS][MAX_AMOUNT_OF_BUDGET];

void	init(void)
{
	for(int i=1;i<=n;i++)
	{
		fill(&oil_table[i][0],&oil_table[i][B+1],0.0);
	}
}

void	find_max_extracted_oil(vector<double>* oil)
{
	for(int oil_field=1;oil_field<=n;oil_field++)
	{
		for(int current_investment=0;current_investment<=m;current_investment++)
		{
			double&	extracted_oil = oil[oil_field][current_investment];
			 
			for(int prev_investment=0;prev_investment+current_investment<=B;prev_investment++)
			{
				if( oil_table[oil_field-1][prev_investment]+extracted_oil 
					> oil_table[oil_field][prev_investment+current_investment] )
				{
					oil_table[oil_field][prev_investment+current_investment] 
						= oil_table[oil_field-1][prev_investment]+extracted_oil;
				}
			}
		}
	}
}

void	input(vector<double>* oil)
{
	scanf("%d %d %d",&n,&m,&B);
	
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<=m;j++)
		{
			double	d;
			
			scanf("%lf",&d);
			oil[i].push_back(d);
		}
	}
}

double	get_max_oil(void)
{
	double	ret;
	
	ret = 0.0;
	
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<=B;j++)
		{
			ret = max(ret,oil_table[i][j]);
		}
	}
	
	return	ret;
}

int		main(void)
{
	int	K;
	
	scanf("%d",&K);
	
	for(int k=1;k<=K;k++)
	{
		vector<double>	oil[MAX_NUM_OF_OIL_FIELDS];
		
		input(oil);
		init();
		
		find_max_extracted_oil(oil);
		printf("Data Set %d:\n%.02f\n\n",k,get_max_oil());
	}
	
	return	0;
}

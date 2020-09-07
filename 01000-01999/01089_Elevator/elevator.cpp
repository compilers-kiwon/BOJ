#include	<iostream>
#include	<vector>
#include	<cmath>

using namespace	std;

#define	MAX_DIGIT	9
#define	MAX_WIDTH	(4*MAX_DIGIT-1)

#define	DIGIT_WIDTH		3
#define	DIGIT_HEIGHT	5

typedef	unsigned long long	uint64;

const char	number[10][DIGIT_HEIGHT][DIGIT_WIDTH+1] = {
	{"###","#.#","#.#","#.#","###"},	// 0
	{"..#","..#","..#","..#","..#"},	// 1
	{"###","..#","###","#..","###"},	// 2
	{"###","..#","###","..#","###"},	// 3
	{"#.#","#.#","###","..#","..#"},	// 4
	{"###","#..","###","..#","###"},	// 5
	{"###","#..","###","#.#","###"},	// 6
	{"###","..#","..#","..#","..#"},	// 7
	{"###","#.#","###","#.#","###"},	// 8
	{"###","#.#","###","..#","###"}		// 9
};

int		N;
char	grid[DIGIT_HEIGHT][MAX_WIDTH+1];

bool	compare_digit(int num,int s_col)
{
	for(int row=0;row<DIGIT_HEIGHT;row++)
	{
		for(int col=0;col<DIGIT_WIDTH;col++)
		{
			if( number[num][row][col]=='.' && grid[row][s_col+col]=='#' )
			{
				return	false;
			}
		}
	}
	
	return	true;
}

void	get_candidate_numbers(vector<int>* candidate)
{
	for(int i=0;i<N;i++)
	{
		for(int num=0;num<=9;num++)
		{
			if( compare_digit(num,4*i) == true )
			{
				candidate[i].push_back(num);
			}
		}
	}
}

double	get_sum(const vector<int>& n)
{
	double	ret;
	
	ret = 0.0;
	
	for(int i=0;i<n.size();i++)
	{
		ret += (double)n[i];
	}
	
	return	ret;
}

double	get_average(vector<int>* candidate,double cnt)
{
	double	ret,d;
	
	ret = 0.0;
	d = pow(10,N-1);
		
	for(int i=0;i<N;i++)
	{
		double	sum;
		
		sum = get_sum(candidate[i]);
		ret += sum/((double)candidate[i].size())*d;
		d /= 10.0;
	}
	
	return	ret;
}

int		get_num_of_possible_floor(vector<int>* candidate)
{
	int	ret,i;
	
	for(ret=1,i=0;i<N;i++)
	{
		ret *= candidate[i].size();
	}
	
	return	ret;
}

int		main(void)
{
	scanf("%d",&N);
	
	for(int row=0;row<DIGIT_HEIGHT;row++)
	{
		scanf("%s",&grid[row][0]);
	}
	
	int			num_of_possible_floor;
	vector<int>	candidate[MAX_DIGIT];
	
	get_candidate_numbers(candidate);
	num_of_possible_floor = get_num_of_possible_floor(candidate);
	
	if( num_of_possible_floor == 0 )
	{
		puts("-1");
		return	0;
	}
	
	printf("%.5f\n",get_average(candidate,(double)num_of_possible_floor));
	
	return	0;
}

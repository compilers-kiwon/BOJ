#include	<iostream>
#include	<map>
#include	<string>

using namespace	std;

void	input(map<string,double>& job,double& t)
{
	while(1)
	{
		string	str;
		
		getline(cin,str);
		
		if( str == "" )
		{
			break;
		}
		
		for(int i=0;i<str.length();i=i+3)
		{
			job[str.substr(i,2)]++;
			t++;
		}
	}
}

int		main(void)
{
	map<string,double>	job_cnt;
	double				total;
	
	total = 0.0;
	
	input(job_cnt,total);
	
	printf("Re %d %.2f\n",(int)job_cnt["Re"],job_cnt["Re"]/total);
	printf("Pt %d %.2f\n",(int)job_cnt["Pt"],job_cnt["Pt"]/total);
	printf("Cc %d %.2f\n",(int)job_cnt["Cc"],job_cnt["Cc"]/total);
	printf("Ea %d %.2f\n",(int)job_cnt["Ea"],job_cnt["Ea"]/total);
	printf("Tb %d %.2f\n",(int)job_cnt["Tb"],job_cnt["Tb"]/total);
	printf("Cm %d %.2f\n",(int)job_cnt["Cm"],job_cnt["Cm"]/total);
	printf("Ex %d %.2f\n",(int)job_cnt["Ex"],job_cnt["Ex"]/total);
	printf("Total %d 1.00\n",(int)total);
	
	return	0;
}

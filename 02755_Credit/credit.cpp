#include <iostream>
#include <string>
#include <map>

using namespace std;

map<string,double> credit_table;

void init_table(void)
{
    credit_table["A+"] = 4.3;
    credit_table["A0"] = 4.0;
    credit_table["A-"] = 3.7;
    
    credit_table["B+"] = 3.3;
    credit_table["B0"] = 3.0;
    credit_table["B-"] = 2.7;
    
    credit_table["C+"] = 2.3;
    credit_table["C0"] = 2.0;
    credit_table["C-"] = 1.7;
    
    credit_table["D+"] = 1.3;
    credit_table["D0"] = 1.0;
    credit_table["D-"] = 0.7;
    
    credit_table["F"] = 0.0;
}

int main(void)
{
    init_table();
    
    int		N,i;
    double	s,total_class_time;
    
	cin>>N;
	
	for(i=1,s=total_class_time=0.0;i<=N;i++)
	{
		string	name,credit;
		double	time;
		
		cin>>name>>time>>credit;
		
		total_class_time += time;
		s += time*credit_table[credit];
	}
	
    printf("%.2f\n",s/total_class_time+0.001);
    
    return 0;
}

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
    string credit;
    
    init_table();
    cin>>credit;
    printf("%.1f\n",credit_table[credit]);
    
    return 0;
}

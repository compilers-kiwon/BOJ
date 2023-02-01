#include    <iostream>

using namespace std;

#define MAX_NUMBER_OF_DRINK_KINDS   3

const int drink_price[MAX_NUMBER_OF_DRINK_KINDS+1] = {0,500,800,1000}; 

int main(void)
{
    int total_spent = 0;

    for(int n;scanf("%d",&n)==1;
            total_spent+=drink_price[n]);
    cout<<5000-total_spent<<'\n';

    return  0;
}
#include    <iostream>

using namespace std;

typedef long long int   int64;

#define PI      31415926536
#define SHIFT   10000000000

int64   get_amount_of_slice_pizza_per_dollar(void)
{
    int64   A,P;

    cin>>A>>P;

    return  (A*(int64)SHIFT)/P;
}

int64   get_amount_of_circular_pizza_per_dollar(void)
{
    int64   R,P;

    cin>>R>>P;

    return  (R*R*(int64)PI)/P;
}

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);
    
    int64   slice,whole;

    slice = get_amount_of_slice_pizza_per_dollar();
    whole = get_amount_of_circular_pizza_per_dollar();

    cout<<((slice>whole)?"Slice of pizza\n":"Whole pizza\n");

    return  0;
}
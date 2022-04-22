#include    <iostream>
#include    <string>
#include    <cmath>

using namespace std;

typedef enum {
    ABUNDANT,
    DEFICIENT,
    PERFECT,
    MAX_CLASSIFICATION
} Classification;

const string    result[MAX_CLASSIFICATION] = {
    " is an abundant number.\n",
    " is a deficient number.\n",
    " is a perfect number.\n"
};

int get_sum_of_divisors(int n)
{
    int ret,square_root;

    ret = 1;
    square_root = sqrt(n);

    for(int i=2;i<=square_root;i++)
    {
        if( n%i == 0 )
        {
            ret += i+(n/i);
        }
    }

    if( square_root*square_root == n )
    {
        ret -= square_root;
    }

    return  ret;
}

Classification  determine_number(int n)
{
    int sum_of_divisors = get_sum_of_divisors(n);

    if( sum_of_divisors > n )
    {
        return  ABUNDANT;
    }

    if( sum_of_divisors < n )
    {
        return  DEFICIENT;
    }

    return  PERFECT;
}

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int n;

    cin>>n;

    for(int i=1;i<=n;i++)
    {
        int             num;
        Classification  c;

        cin>>num;
        c = determine_number(num);

        cout<<num<<result[c]<<'\n';
    }

    return  0;
}
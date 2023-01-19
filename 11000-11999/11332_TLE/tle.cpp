#include    <iostream>
#include    <string>

using namespace std;

typedef long long int   int64;

#define NUM_OF_OPERATIONS   (100000000LL)
#define MAX_NUM_OF_UNITS    (10LL)
#define MAX_ALLOWED_TIME    (MAX_NUM_OF_UNITS*NUM_OF_OPERATIONS)
#define MAX_SIZE_OF_INPUTS  1000000

#define pow_two(n)      ((n)*(n))
#define pow_three(n)    (pow_two((n))*(n))

int64   factorial[MAX_SIZE_OF_INPUTS+1];

#define INF 0

void    init_factorial(void)
{
    factorial[0] = 1;

    for(int i=1;i<=MAX_SIZE_OF_INPUTS;i++)
    {
        int64   tmp = factorial[i-1]*(int64)i;

        if( tmp > MAX_ALLOWED_TIME )
        {
            break;
        }

        factorial[i] = tmp;
    }
}

string  big_o(const string& str,int64 size_of_inputs,
                int64 num_of_test_cases,int64 limt_of_time)
{
    int64   estimated = MAX_ALLOWED_TIME;
    int64   allowed_time = limt_of_time*NUM_OF_OPERATIONS;

    if( str == "O(N)" )
    {
        estimated = size_of_inputs*num_of_test_cases;
    }
    else if( str == "O(N^2)" )
    {
        estimated = pow_two(size_of_inputs)*num_of_test_cases;
    }
    else if( str == "O(N^3)" )
    {
        estimated = pow_three(size_of_inputs);
        estimated = (estimated>MAX_ALLOWED_TIME)?
                        estimated:estimated*num_of_test_cases;
    }
    else if( str == "O(2^N)" )
    {
        estimated = num_of_test_cases;

        for(int64 i=1;i<=size_of_inputs;i++)
        {
            if( (estimated*=2) > allowed_time )
            {
                break;
            }
        }
    }
    else    // str == "O(N!)"
    {
        estimated = factorial[size_of_inputs]*num_of_test_cases;

        if( estimated==INF || estimated>allowed_time )
        {
            estimated = allowed_time+1;
        }
    }

    return  ((estimated>allowed_time)?"TLE!":"May Pass.");
}

int     main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int C;

    cin>>C;
    init_factorial();

    for(int i=1;i<=C;i++)
    {
        string  str;
        int64   N,T,L;

        cin>>str>>N>>T>>L;
        cout<<big_o(str,N,T,L)<<'\n';
    }

    return  0;
}
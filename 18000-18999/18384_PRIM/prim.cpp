#include    <iostream>
#include    <vector>
#include    <algorithm>
#include    <cmath>

using namespace std;

#define MAX_NUM     1000000
#define MAX_SIZE    5

bool    visited[MAX_NUM+1];

bool    is_prime(int n)
{
    for(int i=2;i<=sqrt(n);i++)
    {
        if( n%i == 0 )
        {
            return  false;
        }
    }

    return  true;
}

void    find_prime(vector<int>& p)
{
    for(int i=2;i<=MAX_NUM;i++)
    {
        if( visited[i] == false )
        {
            p.push_back(i);

            for(int j=i;j<=MAX_NUM;j+=i)
            {
                visited[j] = true;
            }
        }
    }

    for(int i=MAX_NUM+1;;i++)
    {
        if( is_prime(i) == true )
        {
            p.push_back(i);
            break;
        }
    }
}

int     main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int         T;
    vector<int> prime;

    cin>>T;
    find_prime(prime);

    for(int t=1;t<=T;t++)
    {
        int sum = 0;

        for(int i=1;i<=MAX_SIZE;i++)
        {
            int I;

            cin>>I;
            sum += *(lower_bound(prime.begin(),prime.end(),I));
        }

        cout<<sum<<'\n';
    }

    return  0;
}
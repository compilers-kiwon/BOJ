#include    <iostream>
#include    <vector>
#include    <cmath>

using namespace std;

#define MAX_NUM 99999

static int  K,M;
static bool is_prime[MAX_NUM+1];
static bool is_sum[MAX_NUM+1];
static bool is_multiplication[MAX_NUM+1];
static vector<int>  prime_num;

typedef long long int   int64;

int get_prime_numbers(void)
{
    fill(&is_prime[1],&is_prime[MAX_NUM+1],true);

    is_prime[1] = false;

    for(int i=2;i<=MAX_NUM;i++)
    {
        if( is_prime[i] == true )
        {
            prime_num.push_back(i);

            for(int j=i+i;j<=MAX_NUM;j+=i)
            {
                is_prime[j] = false;
            }
        }
    }

    return  0;
}

int get_sum_of_primes(void)
{
    for(int i=0;i<prime_num.size();i++)
    {
        for(int j=i+1;j<prime_num.size();j++)
        {
            int&    p1 = prime_num[i];
            int&    p2 = prime_num[j];

            if( p1+p2 > MAX_NUM )
            {
                break;
            }

            is_sum[p1+p2] = true;
        }
    }

    return  0;
}

int get_multiplication_of_primes(void)
{
    for(int i=0;i<prime_num.size();i++)
    {
        for(int j=i;j<prime_num.size();j++)
        {
            int&    p1 = prime_num[i];
            int&    p2 = prime_num[j];

            if( (int64)p1*(int64)p2 > MAX_NUM )
            {
                break;
            }

            is_multiplication[p1*p2] = true;
        }
    }

    return  0;
}

int divide(int num)
{
    int ret;

    for(ret=num;ret%M==0;ret/=M);
    return  ret;
}

int dfs(int num_of_used,int num,bool used[],int& cnt)
{
    if( num_of_used == K )
    {
        if( is_sum[num] && is_multiplication[divide(num)] )
        {
            cnt++;
        }

        return  1;
    }

    for(int i=0;i<=9;i++)
    {
        if( used[i] == false )
        {
            used[i] = true;
            dfs(num_of_used+1,num*10+i,used,cnt);
            used[i] = false;
        }
    }

    return  1;
}

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int cnt = 0;

    cin>>K>>M;

    get_prime_numbers();
    get_sum_of_primes();
    get_multiplication_of_primes();
    
    for(int i=1;i<=9;i++)
    {
        bool    used[10] = {false,};

        used[i] = true;
        dfs(1,i,used,cnt);
    }

    cout<<cnt<<'\n';

    return  0;
}
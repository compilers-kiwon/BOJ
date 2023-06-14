#include    <iostream>
#include    <vector>

using namespace std;

#define MAX_NUM 1000000

static bool is_prime[MAX_NUM+1];

int get_prime_numbers(vector<int>& p)
{
    fill(&is_prime[1],&is_prime[MAX_NUM+1],true);

    is_prime[1] = false;

    for(int i=2;i<=MAX_NUM;i++)
    {
        if( is_prime[i] == true )
        {
            p.push_back(i);

            for(int j=i+i;j<=MAX_NUM;j+=i)
            {
                is_prime[j] = false;
            }
        }
    }

    return  0;
}

int get_num_of_partitions(int num,const vector<int>& p)
{
    int ret = 0;
    int upper = num>>1;

    for(int i=0;i<p.size();i++)
    {
        int cur_prime = p[i];
        int other = num-p[i];

        if( cur_prime > upper )
        {
            break;
        }

        ret += (is_prime[other])?1:0;
    }

    return  ret;
}

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int T;
    vector<int> p;

    cin>>T;
    get_prime_numbers(p);

    for(int t=1;t<=T;t++)
    {
        int N;

        cin>>N;
        cout<<get_num_of_partitions(N,p)<<'\n';
    }

    return  0;
}
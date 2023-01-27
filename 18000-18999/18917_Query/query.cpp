#include    <iostream>
#include    <vector>

using namespace std;

#define MAX_SIZE    32

typedef long long int   int64;

int     A[MAX_SIZE];
int64   sum;

enum{
    ADD = 1,
    REMOVE = 2,
    SUM = 3,
    XOR = 4
};

void    get_bit_map(const int n,
                vector<int>& bit_map)
{
    for(int i=0;i<MAX_SIZE;i++)
    {
        bit_map.push_back((n>>i)&0x1);
    }
}

void    merge(int n)
{
    vector<int> bit_map;

    sum += (int64)n;
    get_bit_map(n,bit_map);

    for(int i=0;i<MAX_SIZE;i++)
    {
        A[i] += bit_map[i];
    }
}

void    remove(int n)
{
    vector<int> bit_map;

    sum -= (int64)n;
    get_bit_map(n,bit_map);

    for(int i=0;i<MAX_SIZE;i++)
    {
        A[i] -= bit_map[i];
    }    
}

int     xor_numbers(void)
{
    int ret = 0;

    for(int i=0;i<MAX_SIZE;i++)
    {
        ret += (A[i]%2)<<i;
    }

    return  ret;
}

int     main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int M;

    cin>>M;

    for(int i=1;i<=M;i++)
    {
        int q,x;

        cin>>q;

        switch(q)
        {
            case ADD:cin>>x;merge(x);break;
            case REMOVE:cin>>x;remove(x);break;
            case SUM:cout<<sum<<'\n';break;
            case XOR:cout<<xor_numbers()<<'\n';break;
            default:break;
        }
    }

    return  0;
}
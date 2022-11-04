#include    <iostream>
#include    <queue>
#include    <map>

using namespace std;

#define MAX_NUM     100000
#define NONE        -1

int     num_of_prime_numbers[MAX_NUM+1];
bool    is_prime[MAX_NUM+1];

#define IN_RANGE(MIN,n,MAX) ((MIN)<=(n)&&(n)<=(MAX))

void    mark_prime_numbers(void)
{
    fill(&is_prime[2],&is_prime[MAX_NUM+1],true);

    for(int i=2;i<=MAX_NUM;i++)
    {
        if( is_prime[i] == true )
        {
            for(int j=i+i;j<=MAX_NUM;j+=i)
            {
                is_prime[j] = false;
            }
        }
    }

    for(int i=2;i<=MAX_NUM;i++)
    {
        num_of_prime_numbers[i] = num_of_prime_numbers[i-1]+(is_prime[i]?1:0);
    }
}

void    div_num_by(int n,queue<int>& q,map<int,int>& v,int d)
{
    int result = n/d;

    if( v.find(result) == v.end() )
    {
        v[result] = v[n]+1;
        q.push(result);
    }
}

void    inc_num(int n,queue<int>& q,map<int,int>& v)
{
    if( v.find(n+1) == v.end() )
    {
        v[n+1] = v[n]+1;
        q.push(n+1);
    }
}

void    dec_num(int n,queue<int>& q,map<int,int>& v)
{
    if( n == 0 )
    {
        return;
    }

    if( v.find(n-1) == v.end() )
    {
        v[n-1] = v[n]+1;
        q.push(n-1);
    }
}

int     simulate(int init_num,int min_num,int max_num)
{
    int ret = NONE;

    if( num_of_prime_numbers[min_num-1] == num_of_prime_numbers[max_num] )
    {
        return  ret;
    }

    queue<int>      q;
    map<int,int>    visited;

    for(visited[init_num]=0,q.push(init_num);!q.empty();q.pop())
    {
        int current_num = q.front();
        
        if( IN_RANGE(min_num,current_num,max_num) && is_prime[current_num]==true )
        {
            ret = visited[current_num];
            break;
        }

        div_num_by(current_num,q,visited,2);
        div_num_by(current_num,q,visited,3);
        inc_num(current_num,q,visited);
        dec_num(current_num,q,visited);
    }

    return  ret;
}

int     main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int T;

    cin>>T;
    mark_prime_numbers();

    for(int t=1;t<=T;t++)
    {
        int N,A,B;

        cin>>N>>A>>B;
        cout<<simulate(N,A,B)<<'\n';
    }

    return  0;
}
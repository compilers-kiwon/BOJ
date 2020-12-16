#include    <iostream>
#include    <string>
#include    <map>
#include    <queue>

using namespace std;

#define MAX_SIZE    15
#define INF         0x7FFFFFFF

int     N,M,cnt[MAX_SIZE];
string  input;

typedef pair<int,string>    State;  // first:-num_of_swaps,second:str

void    init(int& cnt_of_zero,int& cnt_of_one)
{
    cin>>N>>M;

    for(int i=0;i<N;i++)
    {
        char    c;

        cin>>c;
        input.push_back(c);

        if( c == '0' )
        {
            cnt_of_zero++;
        }
        else
        {
            cnt_of_one++;
        }
        
    }

    for(int i=0;i<M;i++)
    {
        cin>>cnt[i];
    }
}

void    build_str(char head,int& cnt_of_zero,int& cnt_of_one,string& result)
{
    for(int i=0;i<M;i++)
    {
        for(int j=0;j<cnt[i];j++)
        {
            result.push_back(head);
        }

        if( head == '0' )
        {
            cnt_of_zero += cnt[i];
            head = '1';
        }
        else
        {
            cnt_of_one += cnt[i];
            head = '0';
        }
    }
}

int     swap_bit(const string& final_bits)
{
    priority_queue<State>   pq;
    map<string,int>         dp;

    pq.push(make_pair(-1,input));
    dp[input] = 1;
    
    for(;!pq.empty();)
    {
        int     current_num_of_swaps;
        string  current_bit_str;

        current_num_of_swaps = -pq.top().first;
        current_bit_str = pq.top().second;

        pq.pop();

        if( current_bit_str == final_bits )
        {
            return  current_num_of_swaps-1;
        }

        for(int i=0;i<N-1;i++)
        {
            string  new_bits;

            new_bits = current_bit_str;
            swap(new_bits[i],new_bits[i+1]);

            if( dp[new_bits]==0 || current_num_of_swaps+1<dp[new_bits] )
            {
                dp[new_bits] = current_num_of_swaps+1;
                pq.push(make_pair(-(current_num_of_swaps+1),new_bits));
            }
        }
    }

    return  INF;
}

int     main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int num_of_zero,num_of_one;

    num_of_zero = num_of_one = 0;
    init(num_of_zero,num_of_one);

    string  z_str;
    int     z_num_of_zero,z_num_of_one;

    z_num_of_zero = z_num_of_one = 0;
    build_str('0',z_num_of_zero,z_num_of_one,z_str);

    string  o_str;
    int     o_num_of_zero,o_num_of_one;

    o_num_of_zero = o_num_of_one = 0;
    build_str('1',o_num_of_zero,o_num_of_one,o_str);
    
    int z_min_num_of_swaps,o_min_num_of_swaps;

    z_min_num_of_swaps = o_min_num_of_swaps = INF;

    if( z_num_of_zero==num_of_zero && z_num_of_one==num_of_one )
    {
        z_min_num_of_swaps = swap_bit(z_str);
    }

    if( o_num_of_zero==num_of_zero && o_num_of_one==num_of_one )
    {
        o_min_num_of_swaps = swap_bit(o_str);
    }

    cout<<min(z_min_num_of_swaps,o_min_num_of_swaps)<<'\n';

    return  0;
}
#include    <iostream>

using namespace std;

#define MAX_SIZE    (100000+1)

static int  N,S[MAX_SIZE];
static int  inc_from_left[MAX_SIZE],inc_from_right[MAX_SIZE];

int get_num_of_inc(int from,int to,int offset,int arr[])
{
    arr[from] = 0;

    for(int i=from+offset;i!=to;i+=offset)
    {
        int prev_num = S[i-offset];
        int current_num = S[i];

        arr[i] = (current_num>prev_num)?arr[i-offset]+1:0;
    }

    return  0;
}

int init(void)
{
    get_num_of_inc(1,N+1,1,inc_from_left);
    get_num_of_inc(N,0,-1,inc_from_right);

    return  0;
}

int is_palindrome(int head,int tail)
{
    for(;head<tail;head++,tail--)
    {
        if( S[head] != S[tail] )
        {
            return  0;
        }
    }

    return  1;
}

int get_length_of_palindrome(int l,int r,int max_len)
{
    int ret = r-l+1;

    for(int offset=1;offset<=max_len;offset++)
    {
        if( S[l-offset] != S[r+offset] )
        {
            break;
        }

        ret += 2;
    }

    return  ret;
}

int get_max_len_of_palindrome(void)
{
    int ret = 1;

    for(int i=1;i<=N;i++)
    {
        int left_pos,right_pos,upper,len;

        left_pos = i;
        right_pos = (i+1<=N&&S[i]==S[i+1])?i+1:i;

        upper = min(inc_from_left[left_pos],inc_from_right[right_pos]);
        len = get_length_of_palindrome(left_pos,right_pos,upper);
        ret = max(ret,len);
    }

    return  ret;
}

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    cin>>N;

    for(int i=1;i<=N;i++)
    {
        cin>>S[i];
    }

    init();
    cout<<get_max_len_of_palindrome()<<'\n';

    return  0;
}
#include    <iostream>

using namespace std;

const static int MAX_QUANTITY = 1000000+1;

typedef long long int   int64;

static int64 S,C,L[MAX_QUANTITY],total_len;

int64 get_num_of_greens(int64 max_len,int64 total_len)
{
    int64 ret;

    for(int64 lo=1,hi=max_len;lo<=hi;) {
        int64 mid,g;

        g = 0;
        mid=(lo+hi)/2;

        for (int64 i=1;i<=S;i++) {
            g += L[i]/mid;
        }

        if (g >= C) {
            ret = total_len-(C*mid);
            lo = mid+1;
        } else {
            hi = mid-1;
        }
    }

    return  ret;
}

int64 input(int64& total_len)
{
    int64 ret = 0;

    cin>>S>>C;
    total_len = 0;

    for (int64 i=1;i<=S;i++) {
        cin>>L[i];
        ret = max(ret,L[i]);
        total_len += L[i];
    }

    return  ret;
}

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int64   max_len,total_len;
    
    max_len = input(total_len);
    cout<<get_num_of_greens(max_len,total_len)<<'\n';

    return  0;
}
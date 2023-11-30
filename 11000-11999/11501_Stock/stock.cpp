#include    <iostream>

using namespace std;

const static int MAX_SIZE = 1000000+1;

typedef long long int   int64;

static int N;
static int64 price[MAX_SIZE];
static int64 max_price_in_future[MAX_SIZE];

void input(void)
{
    cin>>N;

    for (int i=1;i<=N;i++) {
        cin>>price[i];
    }

    max_price_in_future[N] = 0;

    for (int i=N-1;i>=1;i--) {
        max_price_in_future[i] =
            max(price[i+1],max_price_in_future[i+1]);
    }
}

int64 simulate(void)
{
    int64 ret = 0;

    for (int i=1;i<=N;i++) {
        if (price[i] >= max_price_in_future[i]) continue;
        ret += max_price_in_future[i]-price[i];
    }

    return  ret;
}

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int T;

    cin>>T;

    for (int t=1;t<=T;t++) {
        input();
        cout<<simulate()<<'\n';
    }

    return  0;
}
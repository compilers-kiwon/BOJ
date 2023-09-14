#include    <iostream>
#include    <algorithm>

using namespace std;

#define MAX_NUM_OF_PAPERS   (500000+1)

static int  N,score[MAX_NUM_OF_PAPERS];

bool is_bigger(const int& a,const int& b)
{
    return  a>b;
}

int input(void)
{
    cin>>N;

    for (int i=1;i<=N;i++) cin>>score[i];
    sort(&score[1],&score[N+1],is_bigger);

    return  0;
}

int get_hindex(void)
{
    int ret = 0;
    for (int i=N;i>=1;i--) {
        if (score[i] >= i) { ret=i;break; }
    }
    return  ret;
}

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    input();
    cout<<get_hindex()<<'\n';

    return  0;
}
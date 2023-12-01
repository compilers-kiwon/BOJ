#include    <iostream>

using namespace std;

static inline int get_tax(int income,int rate) {
    return  income/100*rate;
}

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int N;

    cin>>N;
    cout<<N-get_tax(N,22)<<' '
        <<N-get_tax(N*20/100,22)<<'\n';

    return  0;
}
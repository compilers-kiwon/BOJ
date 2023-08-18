#include    <iostream>

using namespace std;

typedef long long int   int64;

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int64   cnt,sum,n;

    cin>>n;
    sum = cnt = 0;

    for (int64 i=1;;cnt++,i++) {
        if ((sum+=i*i) > n) break;
    }

    cout<<cnt<<'\n';
    return  0;
}
#include    <iostream>

using namespace std;

typedef long long int   int64;

static int64    A,B,C,cnt[10];

int count_digits(int64 num)
{
    for(;num>0;num/=10)
    {
        cnt[num%10]++;
    }

    return  0;
}

int print(void)
{
    for(int i=0;i<10;i++)
    {
        cout<<cnt[i]<<'\n';
    }

    return  0;
}

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    cin>>A>>B>>C;

    count_digits(A*B*C);
    print();

    return  0;
}
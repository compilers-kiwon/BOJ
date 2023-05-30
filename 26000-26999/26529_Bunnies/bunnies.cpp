#include    <iostream>

using namespace std;

#define MAX_SIZE    45

static int fibo[MAX_SIZE+1];

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    fibo[0] = fibo[1] = 1;

    for(int i=2;i<=MAX_SIZE;i++)
    {
        fibo[i] = fibo[i-1]+fibo[i-2];
    }

    int N;

    cin>>N;

    for(int i=1;i<=N;i++)
    {
        int x;

        cin>>x;
        cout<<fibo[x]<<'\n';
    }

    return  0;
}
#include    <iostream>

using namespace std;

#define MAX_SIZE    (20000+1)

static int  N,arr[MAX_SIZE];

int input(void)
{
    cin>>N;

    for(int i=1;i<=N;i++)
    {
        int k;

        cin>>k;
        arr[k] = i;
    }

    return  0;
}

int output(void)
{
    for(int i=1;i<=N;i++)
    {
        cout<<arr[i]<<'\n';
    }

    return  0;
}

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    input();
    output();

    return  0;
}
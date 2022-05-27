#include    <iostream>

using namespace std;

#define MAX_SIZE    (2000+1)

int N,M,pos[MAX_SIZE];

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    cin>>N>>M;

    for(int i=1;i<=N;i++)
    {
        pos[i] = i;
    }

    for(int i=1;i<=M;i++)
    {
        int X,Y;

        cin>>X>>Y;
        pos[X] = Y;
    }

    for(int i=1;i<=N;i++)
    {
        cout<<pos[i]<<'\n';
    }

    return  0;
}
#include    <iostream>

using namespace std;

#define DAYS_PER_WEEK   7

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int A,B,C,d,coin;

    cin>>A>>B>>C;

    for(d=1,coin=0;;d++)
    {
        coin += A+(!(d%DAYS_PER_WEEK)?B:0);
        if(coin>=C) break;
    }

    cout<<d<<'\n';
    return  0;
}
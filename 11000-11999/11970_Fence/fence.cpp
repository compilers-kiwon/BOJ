#include    <iostream>

using namespace std;

#define MAX_SIZE    (100+1)

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int     a,b,c,d,cnt;
    bool    painted[MAX_SIZE];

    cin>>a>>b>>c>>d;
    fill(&painted[0],&painted[MAX_SIZE],false);

    for(int i=a;i<b;i++)
    {
        painted[i] = true;
    }

    for(int i=c;i<d;i++)
    {
        painted[i] = true;
    }

    cnt = 0;

    for(int i=0;i<MAX_SIZE;i++)
    {
        cnt += (painted[i]?1:0);
    }

    cout<<cnt<<'\n';

    return  0;
}
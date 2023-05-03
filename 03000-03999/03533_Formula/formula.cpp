#include    <iostream>

using namespace std;

#define MAX_SIZE    10

int main(void)
{
    int x[MAX_SIZE+1],cnt;

    for(int i=1;i<=MAX_SIZE;i++)
    {
        cin>>x[i];
    }

    cnt = 0;

    for(int i=1;i<MAX_SIZE;i++)
    {
        for(int j=i+1;j<=MAX_SIZE;j++)
        {
            cnt += (x[i]+x[j])?1:0;
        }
    }

    for(int i=1;i<=MAX_SIZE-2;i++)
    {
        for(int j=i+1;j<=MAX_SIZE-1;j++)
        {
            for(int k=j+1;k<=MAX_SIZE;k++)
            {
                cnt += (x[i]+x[j]+x[k])?1:0;
            }
        }
    }

    cout<<cnt%2<<'\n';

    return  0;
}
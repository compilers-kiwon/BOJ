#include    <iostream>

using namespace std;

#define MAX_SIZE    5

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int d[MAX_SIZE];

    for(int i=1;i<MAX_SIZE;i++)
    {
        cin>>d[i];
        d[i] += d[i-1];
    }

    for(int i=0;i<MAX_SIZE;i++)
    {
        for(int j=0;j<MAX_SIZE;j++)
        {
            cout<<abs(d[i]-d[j])<<' ';
        }
        cout<<'\n';
    }

    return  0;
}
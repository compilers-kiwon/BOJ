#include    <iostream>

using namespace std;

#define MAX_SIZE    (100+1)

int main(void)
{
    int n,order[MAX_SIZE];

    cin>>n;
    order[1] = 1;

    for(int i=2;i<=n;i++)
    {
        int d;

        cin>>d;
        order[1+d+1] = i;
    }

    for(int i=1;i<=n;i++)
    {
        cout<<order[i]<<((i==n)?'\n':' ');
    }

    return  0;
}
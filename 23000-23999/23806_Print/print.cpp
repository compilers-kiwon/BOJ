#include    <iostream>

using namespace std;

#define MAX_SIZE    5

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int N;

    cin>>N;

    for(int i=1;i<=MAX_SIZE;i++)
    {
        for(int j=1;j<=N;j++)
        {
            for(int k=1;k<=N;k++) cout<<'@';
            for(int k=1;k<=3*N;k++) cout<<((i==1||i==MAX_SIZE)?'@':' ');
            for(int k=1;k<=N;k++) cout<<'@';
            cout<<'\n';
        }
    }

    return  0;
}
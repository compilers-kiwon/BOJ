#include    <iostream>

using namespace std;

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int N;

    cin>>N;

    for(int i=1;i<=N+2;i++)
    {
        if( i==1 || i==N+2 )
        {
            for(int j=1;j<=N+2;j++)
            {
                cout<<'@';
            }
        }
        else
        {
            for(int j=1;j<=N+2;j++)
            {
                cout<<((j==1||j==N+2)?'@':' ');
            }
        }

        cout<<'\n';
    }

    return  0;
}
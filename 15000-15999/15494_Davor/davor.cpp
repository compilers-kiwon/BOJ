#include    <iostream>

using namespace std;

#define MAX_X   100

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int N;

    cin>>N;
    N /= 52;

    for(int X=MAX_X;X>=1;X--)
    {
        if( N-7*X>0 && (N-7*X)%21==0 )
        {
            cout<<X<<'\n'<<(N-7*X)/21<<'\n';
            break;
        }
    }

    return  0;
}
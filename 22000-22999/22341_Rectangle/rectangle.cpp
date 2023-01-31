#include    <iostream>

using namespace std;

#define CUT_COL()   (X*B)
#define CUT_ROW()   (Y*A)

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int N,C,A,B;

    cin>>N>>C;
    
    A = N;
    B = N;

    for(int i=1;i<=C;i++)
    {
        int X,Y;

        cin>>X>>Y;

        if( X>=A || Y>=B )
        {
            continue;
        }

        if( CUT_COL() >= CUT_ROW() )
        {
            A = X;
        }
        else
        {
            B = Y;
        }
    }

    cout<<A*B<<'\n';

    return  0;
}
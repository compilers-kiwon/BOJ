#include    <iostream>

using namespace std;

int main(void)
{
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    for(;;)
    {
        int R0,W0,C,R,X;

        cin>>R0>>W0>>C>>R;

        if( R0==0 && W0==0 && C==0 && R==0 )
        {
            break;
        }

        for(X=0;(R0+X*R)/W0<C;X++);

        cout<<X<<'\n';
    }

    return  0;
}